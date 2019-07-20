#!/bin/bash
#            0   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f
echo -en "\x01\xf0\x03\x07\x84\x86\xff\x13"
exit 0

0:	LDI	0xf0
2:	LDB	0x07
4:	ADD
5:	OUT
6:	HLT
7:	0x13
