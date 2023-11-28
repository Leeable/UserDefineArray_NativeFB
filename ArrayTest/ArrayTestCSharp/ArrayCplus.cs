using System;
using System.Iec61131Lib;
using System.Runtime.InteropServices;
using Eclr;
using Iec61131.Engineering.Prototypes.Types;
using Iec61131.Engineering.Prototypes.Variables;
using Iec61131.Engineering.Prototypes.Methods;
using Iec61131.Engineering.Prototypes.Common;
using Iec61131.Engineering.Prototypes.Pragmas;
using System.Runtime.InteropServices;





namespace ArrayTest
{

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
    [StructLayout(LayoutKind.Explicit, Size = 3822)]
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

    [Native]
    [FunctionBlock]
    public class ArrayCplus
    {
        [Input]
        public short IN1;
        [Input]
        public short IN2;
        [Output, DataType("WORD")]
        public ushort OUT;
        [InOut]
        public IntArrayFB ArrayFB;
        [Initialization]
        public void __Init()
        {
            //  No implementation in C# part; implement in native method

        }

        [Execution]
        public void __Process()
        {
            // No implementation in C# part; implement in native method
        }
    }
}
