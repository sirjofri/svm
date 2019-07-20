#!/bin/bash
#            0   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f
echo -en "\x01\x04\x09\x0a\x01\x00\x02\x0a\x86\xff"
exit 0

0:	LDI	0x04
2:	STA	0x0a
4:	LDI	0x00
6:	LDA	0x0a
8:	OUT
9:	HLT
