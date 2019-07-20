#include <stdio.h>
#include <stdlib.h>

#define MEMORY 256

#define LDX 0x90
#define STX 0xa0
#define LXI 0x30

#define LDI 0x01
#define LDA 0x02
#define LDB 0x03
#define ADD 0x84
#define JMP 0x05
#define OUT 0x86
#define JC  0x07
#define JZ  0x08
#define STA 0x09
#define HLT 0xff

char *argv0;
unsigned char memory[MEMORY];

void
usage()
{
	fprintf(stderr, "Usage: %s\n", argv0);
	exit(1);
}

void
printout()
{
	unsigned char input;
	int c = 0;
	int goon;
loop: while (c < MEMORY) {
		input = memory[c];
		printf("%02x:  ", c);
		goon = 0;

		switch (input & 0xf0) {
		case LDX:
			printf("LDX 0x%02x     0x%02x\n", input & 0x0f, input);
			break;
		case STX:
			printf("STX 0x%02x     0x%02x\n", input & 0x0f, input);
			break;
		case LXI:
			printf("LXI 0x%02x val 0x%02x\n", input & 0x0f, input);
			break;
		default:
			goon = 1;
		}

		if (!goon) {
			++c;
			goto loop;
		}
		
		switch (input) {
		case LDI:
			printf("LDI value    0x%02x\n", input);
			break;
		case LDA:
			printf("LDA address  0x%02x\n", input);
			break;
		case LDB:
			printf("LDB address  0x%02x\n", input);
			break;
		case ADD:
			printf("ADD          0x%02x\n", input);
			break;
		case JMP:
			printf("JMP address  0x%02x\n", input);
			break;
		case OUT:
			printf("OUT          0x%02x\n", input);
			break;
		case JC:
			printf("JC  address  0x%02x\n", input);
			break;
		case JZ:
			printf("JZ  address  0x%02x\n", input);
			break;
		case STA:
			printf("STA address  0x%02x\n", input);
			break;
		case HLT:
			printf("HLT          0x%02x\n", input);
			break;
		default:
			printf("             0x%02x\n", input);
		}
		++c;
	}
}

int
main(int argc, char **argv)
{
	if (argc > 1) {
		argv0 = argv[0];
		usage();
	}
	if (fread(memory, sizeof(unsigned char), MEMORY, stdin) <= 0) {
		fprintf(stderr, "Error reading from stdin\n");
		exit(2);
	}
	printout();
	return 0;
}
