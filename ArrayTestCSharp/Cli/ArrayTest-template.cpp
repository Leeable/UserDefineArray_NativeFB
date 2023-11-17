// ArrayTest.cpp native assembly code template.
// PHOENIX CONTACT Software embedded CLR native assembly builder tool generated source file.
// use this file to implement your own native code

#include "eclr.h"
#include "ArrayTest.h"

bool ArrayTest::init()
{
    // If necessary, insert some initialization code for the ArrayTest library here!
    // Call ArrayTest::init() somewhere before ArrayTest::loadLibrary() is called.
    // loadLibrary() has to be called after the ClrContoller object is instantiated.
    // For detailed information see the native library builder documentation
    return true;
}

bool ArrayTest::isCompatible(const EclrVersion& requestedVersion)
{
    // This function is called by the runtime if an application will be bound
    // to this library with the requested version.
    // return true means that this library fits to the requested interface.
    // return false forces the runtime to search for other libraries with the same name by calling isCompatible().
    // If no libraries could be found, the runtime breaks the loading process with linker-error
    // for multiple library version support read the documentation.
    return true;
}

bool ArrayTest::load(ClrAppDomain* pAppDomain)
{
    // This function is called by the runtime if an application will be started.
    // pAppDomain is the domain object which hosts the current application process.
    // At this point, the firmware library is able to initialize some internal objects.
    // If the initialization is done ok, return true
    // otherwise return false.
    return true;
}

bool ArrayTest::unload(ClrAppDomain* pAppDomain)
{
    // This function is called by the runtime if an application will be terminated.
    // pAppDomain is the domain object which hosts the current application process.
    // At this point, the firmware library is able to finalize some internal objects.
    // If the finalization is done ok, return true
    // otherwise return false.
    return true;
}

