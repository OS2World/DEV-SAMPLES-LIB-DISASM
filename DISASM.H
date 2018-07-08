/*==========================================================================*/
/* DISASM.H - 386 Code Disassembly Engine Include File                      */
/*==========================================================================*/
/*                                                                          */
/*    History:                                                              */
/*                                                                          */
/* 11-25-90 - Created this file                                             */
/* 01-02-92 - Added code to handle additional opcodes                       */
/*                                                                          */
/*           (C)Copyright 1990 J.P. Cossette, All rights reserved.          */
/*==========================================================================*/

/*--------------------------------------------------------------------------*/
/* Application Data Structure Definition                                    */
/*--------------------------------------------------------------------------*/
typedef  struct _DISASM
{
    VOID           *csip;              /* CS:IP                                          */
    USHORT         ilen;               /* Instruction length                             */
    UCHAR          longoper;           /* YES/NO value. Is instr in 32 bit operand mode? */
    UCHAR          longaddr;           /* YES/NO value. Is instr in 32 bit address mode? */
    UCHAR          fp_flag;            /* Is register a FLOATING POINT reg ???           */
    UCHAR          buf[80];            /* String holding disassembled instruction        */
} DISASM;

/*--------------------------------------------------------------------------*/
/* .DLL Entry Point                                                         */
/*--------------------------------------------------------------------------*/
SHORT    APIENTRY  DisAssemble(DISASM*, USHORT, SHORT);

