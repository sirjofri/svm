#!/bin/bash
echo -en "\x01\x04\xaa\x01\x00\x9a\x86\xff"
exit 0

0: LDI 0x04
2: STX 0xa
3: LDI 0x00
5: LDX 0xa
6: OUT
7: HLT
