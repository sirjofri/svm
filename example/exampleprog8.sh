#!/bin/bash
#            0   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f
echo -en "\x3a\x04\x9a\x86\xff"
exit 0

0:	LXI 0xa	0x04
2:	LDX 0xa
3:	OUT
4:	HLT
