// ArrayCplus native assembly code template.
// PHOENIX CONTACT Software embedded CLR native assembly builder tool generated source file.
// use this file to implement your own native code

#include "eclr.h"
#include "ArrayTest.h"
int state = 0;
// class ArrayTest.ArrayCplus implementation
void __PInvoke__ ArrayTest::ArrayCplus::__Init()
{
    // implement your code here !
    
}

void __PInvoke__ ArrayTest::ArrayCplus::__Process()
{
    // implement your code here !
    if (!state)
    {
        CreateDataType Demo;
        Demo.sName.Empty();
        Demo.sAttriibute.Empty();
        Demo.sType = cType::EM;
        for (int i = 0; i <= 20; i++)
        {
            this->ArrayFB.set_Item(i, Demo); 
        }
        state = 1;
    }
}

ArrayTest::ArrayCplus::ArrayCplus()
{
    // implement your constructor code here !
}

void __PInvoke__ ArrayTest::ArrayCplus::ctor()
{
    // automatically generated auxiliary constructor : calls the constructor by displacement new operator !
    // @Begin automatically generated code, do not modify !
    new (this) ArrayTest::ArrayCplus();
    // @End automatically generated code
}

