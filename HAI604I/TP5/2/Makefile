########################################
#~ définitions
########################################

BIN=bin/rdv  bin/suppr

# liste des fichiers sources
SRCS0=rdv.c
SRCS1=supprimeSem.c

default: $(BIN)

########################################
#~ regles pour l'executable
########################################

obj/%.o: %.c
	g++ -Wall -Iinclude -c $< -o $@

bin/rdv: $(SRCS0:%.c=obj/%.o)
	g++ -o $@ $+

bin/suppr: $(SRCS1:%.c=obj/%.o)
	g++ -o $@ $+



clean:
	rm -f $(BIN) obj/*.o *~
