#!/bin/bash
echo -en "\x02\x07\x03\x08\x84\x86\xff\x04\x05"
exit 0

0: LDA 0x07
2: LDB 0x08
4: ADD
5: OUT
6: HLT
7: 0x04
8: 0x05
