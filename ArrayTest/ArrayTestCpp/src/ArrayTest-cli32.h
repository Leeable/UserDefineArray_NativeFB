#ifndef __ARRAYTEST_H__
#define __ARRAYTEST_H__
// PHOENIX CONTACT Software eCLR Native Library Builder version 3.0.1033.0
// ArrayTest.h native assembly header template.
// Use this file to implement and/or extend your native c++ classes.
// Insert additional private methods and member only outside of the @Begin/@End comment pair

#include "EclrInterfaces.h"

#include "ArrayTest-version.h"

// public scope class for library implementation
// use ArrayTest::init() and ArrayTest::loadLibrary() during startup 
// to make the library accessible by the managed application.

class ArrayTest
{
    // @Begin automatically generated code, do not modify !
public:
    enum LibVersion { Major=1, Minor=0, Build=0, Revision=0 };
    //library user interface
    static bool init();
    static bool isCompatible(const EclrVersion& requestedVersion);
    static bool load(ClrAppDomain* pAppDomain);
    static bool unload(ClrAppDomain* pAppDomain);
    //automatic generated loader stub
    static bool loadLibrary();
    static bool checkLayout();

    static unsigned s_modulHndl;
    // @End automatically generated code

    class EnumcType
    {
        // @Begin automatically generated code, do not modify native enums !
    public:
        enum cType
        {
        cType_sizeof=4,
        EM=0,
        sql_INT=1,
        sql_TEXT=2,
        sql_REAL=3,
        sql_FLOAT=4,
        sql_DOUBLE=5,
        sql_NUMERIC=6,
        sql_CHAR50=7,
        sql_CHAR100=8
    };
    // @End automatically generated code
    };
    typedef EnumcType::cType cType;

    struct CreateDataType
    {
        // @Begin automatically generated code, do not modify native structs !
        void Init();
        pcoslib::IecString80 sName;  // offset=0
                uint8 __pad1[2];
        cType sType;  // offset=88
        pcoslib::IecString80 sAttriibute;  // offset=92
                uint8 __pad3[2];
        // Size of structure = 180 Bytes
        // @End automatically generated code
    };

    struct IntArrayFB
    {
        // @Begin automatically generated code, do not modify native structs !
        CreateDataType get_Item(Int32 p0);
        void set_Item(Int32 p0, CreateDataType p1);
        void Init();
        CreateDataType Anchor;  // offset=0
                uint8 __pad1[3644];
        // Size of structure = 3824 Bytes
        // @End automatically generated code
    };

    //#snfunctionblock
    class ArrayCplus : public Object
    {
        // @Begin automatically generated code, do not modify inside @Begin/@End comment pair !
    public:
        void __Init();
        void __Process();
        ArrayCplus();
        void ctor();
        Int16 IN1;  // offset=4
        Int16 IN2;  // offset=6
        UInt16 OUT;  // offset=8
                uint8 __pad3[2];
        IntArrayFB ArrayFB;  // offset=12
        // @End automatically generated code
        // insert additional private methods and member here ! 
    };


}; // class ArrayTest

#endif //#ifndef __ARRAYTEST_H__
