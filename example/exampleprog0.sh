#!/bin/bash
#            0   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f
echo -en "\x01\x04\x86\xff"
exit 0

0:	LDI	0x04
1:	OUT
2:	HLT
