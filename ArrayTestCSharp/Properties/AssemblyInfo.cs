using System.Reflection;
using Eclr;
using Iec61131.Engineering.Library;

// General Information about an assembly is controlled through the following 
// set of attributes. Change these attribute values to modify the information
// associated with an assembly.
[assembly: AssemblyTitle("ArrayTest")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("")]
[assembly: AssemblyCopyright("")]

// Version information for an assembly consists of the following four values:
//
//      Major Version
//      Minor Version 
//      Build Number
//      Revision
//
// You can specify all the values or you can default the Build and Revision Numbers 
// by using the '*' as shown below:
// [assembly: AssemblyVersion("1.0.*")]
[assembly: AssemblyVersion("1.0.0.0")]
[assembly: AssemblyFileVersion("1.0.0.0")]

// search path for the shared native library, see readme.txt 
[assembly: NativeDll(@"")]
// file name of the shared native library without file extension
[assembly: NativeDllFileName("libArrayTest")]
// The shared native library attribute flags
[assembly: NativeDllFlags(NativeDllFlagsAttribute.LibraryModes.DomainAffinityExplicit)]

[assembly: Library]
[assembly: UseDotNetNamespace]