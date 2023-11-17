// IntArrayFB native assembly code template.
// PHOENIX CONTACT Software embedded CLR native assembly builder tool generated source file.
// use this file to implement your own native code

#include "eclr.h"
#include "ArrayTest.h"

// class ArrayTest.IntArrayFB implementation
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