#!/bin/bash
echo -en "\x01\x04\x86\xff"
exit 0

0: LDI 0x04
1: OUT
2: HLT
