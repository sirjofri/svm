#!/bin/bash
echo -en "\x02\x04\x86\xff\x04"
exit 0

0: LDA 0x04
2: OUT
3: HLT
4: 0x04
