// CreateDataType native assembly code template.
// PHOENIX CONTACT Software embedded CLR native assembly builder tool generated source file.
// use this file to implement your own native code

#include "eclr.h"
#include "ArrayTest.h"

// class ArrayTest.CreateDataType implementation
void __PInvoke__ ArrayTest::CreateDataType::Init()
{
    // implement your code here !
    this->sName.SetCapacity(this->sName._Capacity_);
    this->sName.Empty();
    this->sType = cType::sql_REAL;
    this->sAttriibute.SetCapacity(this->sAttriibute._Capacity_);
    this->sAttriibute.Empty();

}

