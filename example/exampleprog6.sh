#!/bin/bash
echo -en "\x01\x04\x09\x0a\x01\x00\x02\x0a\x86\xff"
exit 0

0: LDI 0x04
2: STA 0x0a
4: LDI 0x00
6: LDA 0x0a
8: OUT
9: HLT
a:            // a is empty
