# Galen Helfter
# CPSC 4160
# Makefile

SHELL = /bin/sh

CC = gcc
CFLAGS = -g -W -Wall -pedantic -O0
CLEANFILES = *.o *.out core.*
LDFLAGS = -g -W -Wall -pedantic -O0
LIBS = -lm

OBJECTS =	main.o\
		obj_parser.o


PROGS = run

all:		$(PROGS)

run:		$(OBJECTS) $(LIBS)
			$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LIBS)

# Object file dependencies
main.o: obj_parser.h

# Header file dependencies

.PHONY: clean
clean:
		rm -f $(PROGS) $(CLEANFILES)
