#!/bin/bash
echo -en "\x01\xf0\x03\x07\x84\x86\xff\x13"
exit 0

0: LDI 0xf0
2: LDB 0x07
4: ADD
5: OUT
6: HLT
7: 0x13
