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
#define JC  0x07
#define JZ  0x08
#define HLT 0xff

#define F_ZERO  0x01
#define F_CARRY 0x02

char *argv0;

unsigned char a, b;
unsigned char flags;
unsigned int pc = 0;

unsigned char memory[MEMORY];

unsigned char
add(unsigned char a, unsigned char b)
{
	unsigned char result = a + b;
	if (result < a && result < b)
		flags |= F_CARRY;
	if (result == 0)
		flags |= F_ZERO;
	return result;
}

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
		a = add(a, b);
		break;
	case JMP:
		pc = param;
		break;
	case OUT:
		printf("%u", a); // change u to c later
		break;
	case JC:
		if (flags & F_CARRY)
			pc = param;
		break;
	case JZ:
		if (flags & F_ZERO)
			pc = param;
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
