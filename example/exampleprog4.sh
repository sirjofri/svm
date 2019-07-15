#!/bin/bash
echo -en "\x03\x0a\x01\x00\x84\x86\x08\x0b\x05\x04\x05\xff"
exit 0

0: LDB 0x0a
2: LDI 0x00
4: ADD
5: OUT
6: JZ  0x0b
8: JMP 0x04
a: 0x05
b: HLT
