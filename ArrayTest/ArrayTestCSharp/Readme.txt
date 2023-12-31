This project creates an eCLR library DLL.

Adding a Native Function / Native Function Block
=================================================================

1. Select the project in the solution explorer.
2. Open the item "Project" from the main menu or right-click the csharp project.
3. Select the menu item "Add New Item ..."
4. Choose the category "Visual C# Project Items\PLCnext Technology"
5. Select one of the following project items:

    "PLCnext Native Function"
    "PLCnext Native Function Block"
    
6. Enter the name of the class.
7. Perform a click on the button "Add" to complete 
   this procedure. For native functions a wizard appears
   to ask you for the return type of the function.

The following table shows how the IEC 61131-3 data types
are mapped to the .NET-Framework and to C#, respectively.
Variables of data types that are marked in the column "DataType Attribute" with
a '+' must have the optional attribute "DataType" for an unambiguous assignment.

+-------------------+--------------------------------+--------+-----------+
| IEC 61131-3       | .NET Framework                 | C#     | DataType  |
|                   |                                |        | Attribute |
+-------------------+--------------------------------+--------+-----------+
|    BOOL           | System.Boolean                 | bool   |     -     |
|    SINT           | System.SByte                   | sbyte  |     -     |
|    INT            | System.Int16                   | short  |     -     |
|    DINT           | System.Int32                   | int    |     -     |
|    LINT           | System.Int64                   | long   |     -     |
|    USINT          | System.Byte                    | byte   |     -     |
|    UINT           | System.UInt16                  | ushort |     -     |
|    UDINT          | System.UInt32                  | uint   |     -     |
|    ULINT          | System.UInt64                  | ulong  |     -     |
|    REAL           | System.Single                  | float  |     -     |
|    LREAL          | System.Double                  | double |     -     |
|    TIME           | System.Int32                   | int    |     +     |
|    LTIME          | System.Int64                   | long   |     +     |
|    LDATE          | System.Int64                   | long   |     +     |
|    LTIME_OF_DAY   | System.Int64                   | long   |     +     |
|    LDATE_AND_TIME | System.Int64                   | long   |     +     |
|    BYTE           | System.Byte                    | byte   |     +     |
|    WORD           | System.UInt16                  | ushort |     +     |
|    DWORD          | System.UInt32                  | uint   |     +     |
|    LWORD          | System.UInt64                  | ulong  |     +     |
|    STRING         | System.Iec61131Lib.IecStringEx | ------ |     -     |
|    WSTRING        | System.Iec61131Lib.IecWString  | ------ |     -     |
|    ANY            | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_MAGNITUDE  | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_NUM        | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_INT        | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_SIGNED     | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_UNSIGNED   | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_REAL       | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_BIT        | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_ELEMENTARY | System.Iec61131Lib.Any         | ------ |     +     |
|    ANY_STRING     | System.Iec61131Lib.Any         | ------ |     +     |
+-------------------+--------------------------------+--------+-----------+

Optional files for PLCnext Engineer Libraries
=============================================

Library Description
-------------------
The template contains the file "LibraryDescription.xml". 
This file contains additional description for the POUs and their formal
parameters which are shown as tool tips. 
It enables also the structuring of POUs into groups.
For the description of POUs use the elements "ProgramOrganizationUnit".
For structuring the element "ToolboxCategory" is used which must be referred in 
the "ProgramOrganizationUnit".

Localization
For supporting different languages the description file can be localized. For 
each language a separate file has to be created and added into the folder 
"ProjectItems". The file name must have the format 
LibraryDescription[.<culture>].xml where <culture> represents the culture, e.g. 
en, en-US, de, fr, zh-CN.
As default the 'neutral' file without the culture is used 
LibraryDescription.xml.

Help Files
----------
Libraries can include help files that contain a help page for each POU.
A culture can be set for the help, e.g. en, en-US, de, fr, zh-CN.
The neutral help without the culture is used when no help file matches the 
current language of the engineering tool.
The format of the help file can be chm or HTML5.

chm:
The format of the help file name is <library name>[_culture]_FBFun.chm
where <culture> represents the culture, e.g. en, en-US, de, fr, zh-CN.
Leaving out the culture part creates the neutral help.
The engineering tool searches for the library function and function blocks 
through their names. If the help is generated with the "HTML Help Workshop" 
then these names must be defined as keys in the *.hhk file.
Insert help files into the project's folder "Help" and set the property 
"Build Action" to "Content".
Please note: The help file must be copied physically into the project's "Help" 
directory. Do not insert it as link.

HTML5:
An itemtemplate for creating a HTML5 help culture is available at
Project -> Add New Item... -> Installed -> Visual C# Items -> 
PLCnext Technology -> PLCnext HTML5 Help
After selecting 'Add' a wizard opens, in which the name of the function or 
function block the help is for and the culture can be entered.
If nothing is entered in the culture field, the neutral help will be created
in the folder 'default'.
Please note: Use the template only if a new culture should be added to the 
project. To add a help file for an additional function or function block to an
existing culture, the <FunctionName>.htm of an existing function or function 
block can be duplicated and adapted accordingly.

Debugging the Library
=====================

For debugging an application on the device it is important that the actual C# 
code is executed on the PLC. Therefore first the C# project must be built and 
then build the Engineering project containing the C# library. All must be 
downloaded to the PLC.

Debugging an eCLR Device requires an unsecured TCP/IP connection. If the device
is secured then open a port for debugging. Refer the PLCnext community for more 
information: https://www.plcnext-community.net

1. In the Project Menu choose "Attach to Process...".
2. For transport choose "eCLR Device".
3. Click on "Browse" to choose the qualifier.
3a.) Enter the IP address of the device
3b.) Select the eCLR application image file that should be
     used for debugging.
4. Press "Attach" to start debugging the project on the eCLR
