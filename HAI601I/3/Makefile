all:
	flex markdownHTML.l
	gcc -o markdown lex.yy.c -lfl
	rm lex.yy.c
