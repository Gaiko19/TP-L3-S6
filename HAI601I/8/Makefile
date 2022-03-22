CC = gcc
CFLAGS = -Wall -Iinclude -ansi

YACC=bison
YACCFLAGS=-ydtv

BIN=bin/source
DIRG=@mkdir -p $(@D)

all: $(BIN)

clean:
	rm y.output y.tab.*
	rm -rf bin

bin/source: source.y arbin.c
	$(DIRG)
	$(YACC) $(YACCFLAGS) source.y
	$(CC) $(CFLAGS) -o $@ y.tab.c arbin.c