/*==========================================================================*/
/* TEST.C - 386 Code Disassembly Engine Test Program                        */
/*==========================================================================*/
/*                                                                          */
/* Created by: J.P. Cossette                                                */
/*                                                                          */
/*    History:                                                              */
/*                                                                          */
/* 11-25-1990 - Created this file                                           */
/*                                                                          */
/*           (C)Copyright 1990 J.P. Cossette, All rights reserved.          */
/*==========================================================================*/
#define   INCL_DOS
#include  <os2.h>
#include  <stdlib.h>
#include  <stdio.h>
#include  <memory.h>
#include  <string.h>
#include  <disasm.h>

/*--------------------------------------------------------------------------*/
/* Local Definitions                                                        */
/*--------------------------------------------------------------------------*/
#define  DISASM_CODESIZ     0x02500

/*--------------------------------------------------------------------------*/
/* Function prototypes                                                      */
/*--------------------------------------------------------------------------*/
VOID     cdecl     main(VOID);
VOID     cdecl     TestProc(USHORT);
VOID     APIENTRY  PlmProc(USHORT);
VOID     cdecl     dummy(VOID);

/*--------------------------------------------------------------------------*/
/*  Local Data                                                              */
/*--------------------------------------------------------------------------*/
DISASM   d;
VOID     *start_addr;
VOID     *stop_addr;

UCHAR    b_dumbuf[512];
USHORT   w_dumbuf[512];
ULONG    d_dumbuf[512];

/*==========================================================================*/
/* main()                                                                   */
/*==========================================================================*/
VOID     cdecl     main()
{
    SHORT          rc;
    USHORT         i;
    UCHAR          buf[64];
    UCHAR          *p;

    TestProc(0);

    d.csip = start_addr;
    for (; d.csip < stop_addr;)
    {
        p = (UCHAR*)d.csip;
        if ((rc = DisAssemble(&d, 0, 0)) != 0)
        {
            printf("\nError: rc=%d...", rc);
            exit(-1);
        }
        memset(buf, 0, sizeof(buf));
        memset(buf, ' ', (sizeof(buf) - 1));
        for (buf[0] = 0x00, i = 0; i < d.ilen; i++)
        {
            sprintf(&buf[(strlen(buf))], "%02X", p[i]);
        }
        buf[(strlen(buf))] = ' ';
        buf[19] = 0x00;
        printf("\n%04X:%04X %s %s", SELECTOROF(p), OFFSETOF(p), buf, d.buf);
    }
}
/*==========================================================================*/
/*  TestProc() - disassemble this function                                  */
/*==========================================================================*/
VOID     cdecl     TestProc(parm1)
USHORT             parm1;
{
    ULONG          la[2];
    USHORT         i, j;
    UCHAR          c, *p;

//    start_addr = TestProc;
//    stop_addr  = dummy;

    start_addr = DisAssemble;
    stop_addr  = MAKEP((SELECTOROF(DisAssemble)), ((OFFSETOF(DisAssemble)) + DISASM_CODESIZ));

    return;
    i = 1;
    la[i] = 1L;
    i = i * 111;
    i = i >> 10;
    i = i << 10;
    i = i / 3;
    i ^= 5;
    i = ~i;
    i++;
    i--;
    i += 5;
    i += 512;
    i -= 5;
    i -= 512;
    i = i | j;
    i = i | 0x05;
    i = i | 0x0512;
    i = i ^ j;
    i = i ^ 5;
    i = i ^ 512;
    i = i & j;
    i = i & 5;
    i = i & 512;

    for (i = 0; i < 1024; i++, j++)
    {
         b_dumbuf[i] = j;
         b_dumbuf[i+j] = i;
         b_dumbuf[i+j] = 5;
         b_dumbuf[i+j] = 512;

         w_dumbuf[i] = j;
         w_dumbuf[i+j] = i;
         w_dumbuf[i+j] = 5;
         w_dumbuf[i+j] = 512;

         d_dumbuf[i] = j;
         d_dumbuf[i+j] = i;
         d_dumbuf[i+j] = 5;
         d_dumbuf[i+j] = 512;
         d_dumbuf[i+j] = 0x10001000;

         p = b_dumbuf;
         p[i] = j;
         p[i+j] = i;
         p[i+j] = 5;
         p[i+j] = 512;
    }
    PlmProc(i);
    PlmProc(512);
}
/*==========================================================================*/
VOID     APIENTRY  PlmProc(parm1)
USHORT             parm1;
{
}
/*==========================================================================*/
VOID     cdecl     dummy()
{
}
/*==========================================================================*/
