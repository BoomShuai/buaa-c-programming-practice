CC = cc
CFLAGS = -std=c11 -O2 -Wall -Wextra -Wpedantic -Werror
PYTHON = python3
PROGRAMS = A B C D E F G H
BINARIES = $(addprefix build/,$(PROGRAMS))

.PHONY: all test clean
all: $(BINARIES)

build:
	mkdir -p build

build/%: %.c | build
	$(CC) $(CFLAGS) $< -o $@

test: all
	$(PYTHON) tests/smoke.py --bin-dir build

clean:
	rm -rf build
