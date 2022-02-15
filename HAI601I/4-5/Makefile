.SUFFIXES:.cc .h .fl .l+ .y+ .fl+

CPP=g++
CC=gcc
CFLAGS=-g -ansi -Wall
CPPFLAGS=-g -ansi -Wall

LEX=flex
LEXLIBRARY=-lfl
YACC=bison
YACCFLAGS=-ydtv
#-y a la yacc : y.tab.c; -d genere y.tab.h; -t debogage possible; -v verbose

clean :
	rm lex.yy.c y.tab.c calc

calc :	calc.y calc.l
	# d'abord yacc pour y.tab.h puis lex puis gcc
	@echo debut $(YACC)-compil : calc.y
	$(YACC) $(YACCFLAGS) calc.y
	@echo debut $(LEX)-compil : calc.l
	$(LEX) calc.l
	@echo debut compil c avec edition de liens
	$(CC) -o calc y.tab.c lex.yy.c -lm   # lib math
	@# attention l'option -g (debug) fait planter
	@echo fin compil : vous pouvez executer calc

#regles de suffixe
.h.c:
	@echo regle de suffixe : .h modifie donne .c modifie
	touch $*.c

.c.o:
	@echo debut compil c sans edition de liens de $<
	$(CC) $(CFLAGS) -c $<
	@echo fin compil de $<

.c:
	@echo debut compil c complete de $<
	$(CC) $(CFLAGS) -o $* $<
	@echo fin compil de $< en $*

.h.cc:
	@echo regle de suffixe : .h modifie donne .cc modifie
	touch $*.cc

.cc.o:
	@echo debut compil c++ sans edition de liens de $<
	$(CPP) -c $(CPPFLAGS) $<
	@echo fin compil de $<

.cc:
	@echo debut compil c++ complete de $<
	$(CPP) -o $* $(CPPFLAGS) $<
	@echo fin compil de $< en $*

.l:	# avec la librairie LEX
	@echo debut $(LEX)-compil : $<
	$(LEX) $<
	@echo debut compil c avec edition de liens de lex.yy.c
	$(CC) $(CFLAGS) -o $* lex.yy.c $(LEXLIBRARY)
	@echo fin $(LEX)-compil de : $<
	@echo Vous pouvez executer : $*
.fl:	# sans librairie (seulement flex) -> main et yywrap
	@echo debut flex-compil : $<
	flex $<
	@echo debut compil c avec edition de liens de lex.yy.c
	$(CC) $(CFLAGS) -o $* lex.yy.c
	@echo fin flex-compil de : $<
	@echo Vous pouvez executer : $*
.l+:	# C++ avec la librairie LEX
	@echo debut $(LEX)-compil : $<
	$(LEX) $<
	@echo debut compil c++ avec edition de liens de lex.yy.c
	$(CPP) $(CPPFLAGS) -o $* lex.yy.c $(LEXLIBRARY)
	@echo fin $(LEX)-compil de : $<
	@echo Vous pouvez executer : $*
.fl+:	# C++ sans librairie (seulement flex) -> main et yywrap
	@echo debut $(LEX)-compil : $<
	$(LEX) $<
	@echo debut compil c++ avec edition de liens de lex.yy.c
	$(CPP) $(CPPFLAGS) -o $* lex.yy.c
	@echo fin $(LEX)-compil de : $<
	@echo Vous pouvez executer : $*
.y:
	@echo debut $(YACC)-compil : $<
	$(YACC) $(YACCFLAGS) $<
	@echo debut compil c avec edition de liens de y.tab.c
	$(CC) $(CFLAGS) -o $* y.tab.c
	@echo fin $(YACC)-compil de : $<
	@echo Vous pouvez executer : $*
.y+:
	@echo debut $(YACC)-compil : $<
	$(YACC) $(YACCFLAGS) $<
	@echo debut compil c++ avec edition de liens de y.tab.c
	$(CPP) $(CPPFLAGS) -o $* y.tab.c
	@echo fin $(YACC)-compil de : $<
	@echo Vous pouvez executer : $*
