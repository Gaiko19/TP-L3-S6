%{
#include <stdio.h>
#include <stdlib.h>
#include "arbin.h"
void yyerror(char*);
int yylex();
%}
%union { 
    int c;
    Arbin a;
}
%token<c> SYMBOLE
%type<a> S E T F

%left '|'
%left CONCAT
%left '*'
%%
expr : '('expr ')'{$$ = $2;}
| expr expr %prec CONCAT { $$= ab_construire('.',$1,$2);}
| expr '|'expr {$$= ab_construire('|',$1,$3);}
| expr '*'{$$= ab_construire('*',$1,ab_creer());}
| SYMBOLE {$$=ab_construire(yylval.i, ab_creer(), ab_creer());}
;

%%
int yylex(){
    int i=getchar();
    if ((i>='a' && i<='z')||i=='@'||i=='0'){
        yylval.c=i;
        return SYMBOLE;
    }
    else return i;
}
void yyerror(char *s) {
    fprintf(stderr,"ERREUR : %s\n",s);
}
int main(){
    return yyparse();
}