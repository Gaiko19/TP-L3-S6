.SUFFIXES:.l
CC=gcc
CFLAGS=-g
LEX=flex
.l: # sans librairie
@echo début $(LEX)-compil : $<
$(LEX) $<
@echo début compil C de lex.yy.c
$(CC) $(CFLAGS) -o $* lex.yy.c
@echo fin $(LEX)-compil : $<
@echo Vous pouvez exécuter : $*
