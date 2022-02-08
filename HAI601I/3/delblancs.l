%{ /* analflex.l */
/* ZONE DE DEFINITION (OPTIONNELLE) */
/* ZONE DES REGLES apres le double pourcent (OBLIGATOIRE) */
%}
chiffre        ([0-9])
lettre        ([a-zA-Z])
%%
^[\t ]*\n {/*ne rien faire, filtrer les blancs*/}
^[\t ]+ {/*ne rien faire, filtrer les blancs/*/}
[\t ]+$ {/*ne rien faire, filtrer les blancs*/}
[\t ]+ {int c;
    if ((c=input())!=EOF && c!=0){
    //printf("<CHAR %c (%d)>", c,c); // débogage
    unput(c); //rejet du char diff de EOF
    putchar('_'); /* à changer en espace */
    }
}

%%
/* ZONE DES FONCTIONS C */
int main() {int i; while((i=yylex()));}
