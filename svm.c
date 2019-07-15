#include <stdio.h>
#include <stdlib.h>

#ifndef MEMORY
#define MEMORY 1024
#endif

#define LDI 0x01
#define LDA 0x02
#define LDB 0x03
#define ADD 0x84
#define JMP 0x05
#define OUT 0x86
#define HLT 0xff

char *argv0;

unsigned char a, b;
unsigned int pc = 0;

unsigned char memory[MEMORY];

int
eval(unsigned char input)
{
	unsigned char param = 0;
	unsigned char cmd = input;
	unsigned char loadnext = input & 0x80;
	if (!loadnext) {
		param = memory[pc++];
	}

	switch (cmd) {
	case LDI:
		a = param;
		break;
	case LDA:
		a = memory[param];
		break;
	case LDB:
		b = memory[param];
		break;
	case ADD:
		a = a + b;
		break;
	case JMP:
		pc = param;
		break;
	case OUT:
		printf("%d", a);
		break;
	case HLT:
		return 0;
	default:
		fprintf(stderr, "invalid command!\n");
		return 0;
	}
	return 1;
}

void
clockloop()
{
	unsigned char input;
	do {
		input = memory[pc++];
	} while (eval(input));
}

void
usage()
{
	fprintf(stderr, "usage: %s\n", argv0);
	exit(1);
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
	clockloop();
	return 0;
}
