This is a tutorial on how to create complex **user-defined arrays** in native FB.

## Have a look
First of all, the official PLCnext Github [CSharp User-defined Array](https://github.com/PLCnext/CSharpExamples/tree/master/PLCnext_CSharpExamples/04_UserArray) only show how to deal with User-defined Array in C# code.
But sometimes user need Native FB (input/output is defined by CSharp and logic is defined by C++) to deal with their complex logic.

In this tuorial, a complex Array will be created. The elements inside this Array is a structure, including String, Enum

```
public enum cType
    {
        EM,
        sql_INT,
        sql_TEXT,
        sql_REAL,
        sql_FLOAT,
        sql_DOUBLE,
        sql_NUMERIC,
        sql_CHAR50,
        sql_CHAR100,
    }

public struct CreateDataType
    {
        public IecString80 sName;
        public cType sType;
        public IecString80 sAttriibute;
        [Initialization]
        public void Init()
        {
            // No implementation in native methods
        }
    }
```
## Create your Native FB

Here, we assume the reader has relevant experience, so we will only explain how to create a custom array.
The Most things are simliar with the original CSharp Codes, User need to define the **dimension** of the Array, and also the **size** of the Array
For String element, we need extra calculate padding, the reference is here [How to Cal Szie](https://github.com/PLCnext/CSharpExamples/blob/master/PLCnext_CSharpExamples/04_UserArray/UserArray.md)

86+2+4+86+2=180
|Var|size|align|
|---|---|---|
|sName| 86B| align=2|
|sType| 4B| align=4|
|sAttriibute| 86B |align=2|

sName offset 0 -> 85

sType will start from 86, but 86/4=21.5 so need padding to 88

88/4=22

sType will be 88-91 (4byte)

sAttriibute will start from 92

92/2=46

now the total size is 86+2+4+86=178

178/4=44.5 so need padding to 180

the final size for this **CreateDataType** is 180

180 * (20-0+1)=3780

and in the **public struct IntArrayFB**, we don't need to implment the **get** and **set** function, those function will be implment in C++

```C#
    [Native]
    [Enumeration]
    public enum cType
    {
        EM,
        sql_INT,
        sql_TEXT,
        sql_REAL,
        sql_FLOAT,
        sql_DOUBLE,
        sql_NUMERIC,
        sql_CHAR50,
        sql_CHAR100,
    }

    [Native]
    [Structure]
    public struct CreateDataType
    {
        public IecString80 sName;
        public cType sType;
        public IecString80 sAttriibute;
        [Initialization]
        public void Init()
        {
            // No implementation in native methods
        }
    }

    [Native]
    [Array(1), ArrayDimension(0, 0, 20), DataType("CreateDataType")]
    [StructLayout(LayoutKind.Explicit, Size = 3780)]
    public struct IntArrayFB
    {
        // Helper containing constants to have a
        // clear and maintainable definition for boundaries and size


        // Fields
        // The field "Anchor" defines the beginning of the array.
        [FieldOffset(0)]
        // The Anchor's data type is the child data type of the array
        public CreateDataType Anchor;

        // The constants LB and UB define the upper and lower bound. Boundaries will be checked by using them.
        public CreateDataType this[int index]
        {
            get
            {
                // No implementation in C#
                throw new Exception();
            }
            set
            {
                //No implementation in C#
            }
        }
        
        [Initialization]
        public void Init()
        {
            // No implementation in native methods
        }

    }
```

## Remove Error in cli32 and cli64 header files

When the CSharp codes generate the Cpp codes, there will an error in the *cli32.h and *cli64.h, just remove `#error structs as method result not supported` and `#error arg 2: structs as method arguments not supported`

```c++
    struct IntArrayFB
    {
        // @Begin automatically generated code, do not modify native structs !
#error structs as method result not supported
        CreateDataType get_Item(Int32 p0);
#error arg 2: structs as method arguments not supported
        void set_Item(Int32 p0, CreateDataType p1);
        void Init();
        CreateDataType Anchor;  // offset=0
                uint8 __pad1[3600];
        // Size of structure = 3780 Bytes
        // @End automatically generated code
    };
```

## Implement the get_Item() and set_Item() function

```c++
ArrayTest::CreateDataType __PInvoke__ ArrayTest::IntArrayFB::get_Item(Int32 p0)
{
    // implement your code here !
    CreateDataType* pvalue = &Anchor;
    CreateDataType result = *(pvalue + p0);
    return result;
}

void __PInvoke__ ArrayTest::IntArrayFB::set_Item(Int32 p0, ArrayTest::CreateDataType p1)
{
    // implement your code here !
    CreateDataType* pvalue = &Anchor;
    *(pvalue + p0) = p1;
}
```

## Implement the Init() function

if user use String as variable, for example this case, the string need to be inited.

In the CreateDataType-cli.cpp

```c++
void __PInvoke__ ArrayTest::CreateDataType::Init()
{
    // implement your code here !
    this->sName.SetCapacity(this->sName._Capacity_);
    this->sName.Empty();
    this->sType = cType::EM;
    this->sAttriibute.SetCapacity(this->sAttriibute._Capacity_);
    this->sAttriibute.Empty();

}
```
In the IntArrayFB-cli.cpp

```c++
void __PInvoke__ ArrayTest::IntArrayFB::Init()
{
    // implement your code here !
    ArrayTest::CreateDataType* pvalue = &Anchor;
    for (Int32 index = 0; index <=20; index ++){
        pvalue[index].Init();
    }
}
```

## Generate the pcwlx library 

Assume the reader is familiar with the process.

