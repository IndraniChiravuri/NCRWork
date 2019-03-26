
//  Microsoft (R) .NET Framework IL Disassembler.  Version 4.6.1055.0
//  Copyright (c) Microsoft Corporation.  All rights reserved.



// Metadata version: v4.0.30319
.assembly extern mscorlib
{
  .publickeytoken = (B7 7A 5C 56 19 34 E0 89 )                         // .z\V.4..
  .ver 4:0:0:0
}
.assembly Conversion
{
  .custom instance void [mscorlib]System.Runtime.CompilerServices.CompilationRelaxationsAttribute::.ctor(int32) = ( 01 00 08 00 00 00 00 00 ) 
  .custom instance void [mscorlib]System.Runtime.CompilerServices.RuntimeCompatibilityAttribute::.ctor() = ( 01 00 01 00 54 02 16 57 72 61 70 4E 6F 6E 45 78   // ....T..WrapNonEx
                                                                                                             63 65 70 74 69 6F 6E 54 68 72 6F 77 73 01 )       // ceptionThrows.

  // --- The following custom attribute is added automatically, do not uncomment -------
  //  .custom instance void [mscorlib]System.Diagnostics.DebuggableAttribute::.ctor(valuetype [mscorlib]System.Diagnostics.DebuggableAttribute/DebuggingModes) = ( 01 00 07 01 00 00 00 00 ) 

  .custom instance void [mscorlib]System.Reflection.AssemblyTitleAttribute::.ctor(string) = ( 01 00 0A 43 6F 6E 76 65 72 73 69 6F 6E 00 00 )    // ...Conversion..
  .custom instance void [mscorlib]System.Reflection.AssemblyDescriptionAttribute::.ctor(string) = ( 01 00 00 00 00 ) 
  .custom instance void [mscorlib]System.Reflection.AssemblyConfigurationAttribute::.ctor(string) = ( 01 00 00 00 00 ) 
  .custom instance void [mscorlib]System.Reflection.AssemblyCompanyAttribute::.ctor(string) = ( 01 00 00 00 00 ) 
  .custom instance void [mscorlib]System.Reflection.AssemblyProductAttribute::.ctor(string) = ( 01 00 0A 43 6F 6E 76 65 72 73 69 6F 6E 00 00 )    // ...Conversion..
  .custom instance void [mscorlib]System.Reflection.AssemblyCopyrightAttribute::.ctor(string) = ( 01 00 12 43 6F 70 79 72 69 67 68 74 20 C2 A9 20   // ...Copyright .. 
                                                                                                  20 32 30 31 39 00 00 )                            //  2019..
  .custom instance void [mscorlib]System.Reflection.AssemblyTrademarkAttribute::.ctor(string) = ( 01 00 00 00 00 ) 
  .custom instance void [mscorlib]System.Runtime.InteropServices.ComVisibleAttribute::.ctor(bool) = ( 01 00 00 00 00 ) 
  .custom instance void [mscorlib]System.Runtime.InteropServices.GuidAttribute::.ctor(string) = ( 01 00 24 65 34 38 64 32 64 66 35 2D 33 62 66 62   // ..$e48d2df5-3bfb
                                                                                                  2D 34 30 39 31 2D 39 35 30 39 2D 62 61 39 38 30   // -4091-9509-ba980
                                                                                                  35 37 39 66 65 33 38 00 00 )                      // 579fe38..
  .custom instance void [mscorlib]System.Reflection.AssemblyFileVersionAttribute::.ctor(string) = ( 01 00 07 31 2E 30 2E 30 2E 30 00 00 )             // ...1.0.0.0..
  .custom instance void [mscorlib]System.Runtime.Versioning.TargetFrameworkAttribute::.ctor(string) = ( 01 00 1C 2E 4E 45 54 46 72 61 6D 65 77 6F 72 6B   // ....NETFramework
                                                                                                        2C 56 65 72 73 69 6F 6E 3D 76 34 2E 35 2E 32 01   // ,Version=v4.5.2.
                                                                                                        00 54 0E 14 46 72 61 6D 65 77 6F 72 6B 44 69 73   // .T..FrameworkDis
                                                                                                        70 6C 61 79 4E 61 6D 65 14 2E 4E 45 54 20 46 72   // playName..NET Fr
                                                                                                        61 6D 65 77 6F 72 6B 20 34 2E 35 2E 32 )          // amework 4.5.2
  .hash algorithm 0x00008004
  .ver 1:0:0:0
}
.module Conversion.exe
// MVID: {9513B9E9-A2B1-457C-A72D-793D5C3F0961}
.imagebase 0x00400000
.file alignment 0x00000200
.stackreserve 0x00100000
.subsystem 0x0003       // WINDOWS_CUI
.corflags 0x00020003    //  ILONLY 32BITPREFERRED
// Image base: 0x00B90000


// =============== CLASS MEMBERS DECLARATION ===================

.class private auto ansi beforefieldinit Conversion.Program
       extends [mscorlib]System.Object
{
  .field private string name
  .method private hidebysig instance string 
          getName() cil managed
  {
    // Code size       12 (0xc)
    .maxstack  1
    .locals init ([0] string V_0)
    IL_0000:  nop
    IL_0001:  ldarg.0
    IL_0002:  ldfld      string Conversion.Program::name
    IL_0007:  stloc.0
    IL_0008:  br.s       IL_000a

    IL_000a:  ldloc.0
    IL_000b:  ret
  } // end of method Program::getName

  .method private hidebysig static void  Main(string[] args) cil managed
  {
    .entrypoint
    // Code size       73 (0x49)
    .maxstack  2
    .locals init ([0] class Conversion.Program p,
             [1] int32 x,
             [2] float32 y)
    IL_0000:  nop
    IL_0001:  newobj     instance void Conversion.Program::.ctor()
    IL_0006:  stloc.0
    IL_0007:  ldc.i4.s   21
    IL_0009:  stloc.1
    IL_000a:  ldc.r4     21.5
    IL_000f:  stloc.2
    IL_0010:  ldloc.1
    IL_0011:  conv.r4
    IL_0012:  stloc.2
    IL_0013:  ldloc.1
    IL_0014:  call       void [mscorlib]System.Console::WriteLine(int32)
    IL_0019:  nop
    IL_001a:  ldloc.2
    IL_001b:  call       void [mscorlib]System.Console::WriteLine(float32)
    IL_0020:  nop
    IL_0021:  ldloc.0
    IL_0022:  ldstr      "Joey Tribbianne"
    IL_0027:  stfld      string Conversion.Program::name
    IL_002c:  ldstr      "Name: "
    IL_0031:  ldloc.0
    IL_0032:  callvirt   instance string Conversion.Program::getName()
    IL_0037:  call       string [mscorlib]System.String::Concat(string,
                                                                string)
    IL_003c:  call       void [mscorlib]System.Console::WriteLine(string)
    IL_0041:  nop
    IL_0042:  call       int32 [mscorlib]System.Console::Read()
    IL_0047:  pop
    IL_0048:  ret
  } // end of method Program::Main

  .method public hidebysig specialname rtspecialname 
          instance void  .ctor() cil managed
  {
    // Code size       8 (0x8)
    .maxstack  8
    IL_0000:  ldarg.0
    IL_0001:  call       instance void [mscorlib]System.Object::.ctor()
    IL_0006:  nop
    IL_0007:  ret
  } // end of method Program::.ctor

} // end of class Conversion.Program


// =============================================================

// *********** DISASSEMBLY COMPLETE ***********************
// WARNING: Created Win32 resource file C:\Users\admin\Desktop\NCRWork\Dot Net\DotNetClass\Conversion\bin\Debug\ilfile.res
