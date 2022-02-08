/* Zone de définition */

%{
    #include <stdio.h>
%}
%option noyywrap
/* Zone des règles */

%%
([^"*"]) | ([^"-"])            {fputc("<ul><li>")}
[\t]+ [^"*"] | [^"-"]      {fputc("</li><ul><li>")}
%%

/* Zone des fonctions C */

int main() {
    int j;

    while ((j=yylex()));
    
}
