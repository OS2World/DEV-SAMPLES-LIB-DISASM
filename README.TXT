
  (C) Copyright J.P. Cossette 1992. All rights reserved.


  DISASM is a "disassembly engine". Usage is relatively straightforward,
and a sample test program has been provided.

  Zipfile contents:

   disasm.lib   - This is for usage in static link applications.
   disasm.dll   - This is for usage in dynamic link applications.
   disasmd.lib  - Stub library for dynamic link applications.
   disasm.h     - Application include file.
   test.c       - Test program showing usage.

  It currently uses the sprintf() function in the C library.
  It was compiled using MSC 6.00A.
  The .DLL is serialized for multiple thread usage. The static link version
  should be able to run on any OS, provided you have the sprintf() function.

  DISASM is copyrighted by J.P. Cossette, and is released as "ShareWare".

  You may copy the program and distribute it without charge.  You may
  not sell or otherwise charge for DISASM.  However, users' groups may
  charge a small fee (not to exceed $7) for media and postage.

  This program is provided AS IS without any warranty, expressed or
  implied, including but not limited to fitness for a particular
  purpose.

  J.P. Cossette is not responsible for anything that may happen when
  you use DISASM.


                        Joseph P. Cossette
                     1280 South Powerline Rd.
                            Suite 171
                     Pompano Beach, Fl. 33069
                            76130,2321
