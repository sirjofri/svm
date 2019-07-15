CFLAGS=-std=c99 -pedantic -D_POSIX_C_SOURCE=200809L -Wall -g
LDFLAGS=

EXAMPLES=$(basename $(shell ls example/*.sh))

svm: svm.c

all: svm examples

examples: $(EXAMPLES:%.sh=%)

$(EXAMPLES): %: %.sh
	./$< > $@

.PHONY: all examples
