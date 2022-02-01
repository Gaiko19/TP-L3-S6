%{ /* analflex.l */
/* ZONE DE DEFINITION (OPTIONNELLE) */
/* ZONE DES REGLES apres le double pourcent (OBLIGATOIRE) */
%}
chiffre ([0-9])
lettre ([a-zA-Z])
%%
if {return 300; /* ret un jeton */ }
then {return 301; /* ret un jeton */ }
else {return 302; /* ret un jeton */}
throw {return 303; /* ret un jeton */}
0[0-7]+ {return 304;}
0x[0-9A-Fa-f]+ {return 305;}
[1-9]{chiffre}* {return 306; /* ret un jeton */}
{lettre}({lettre}|{chiffre}|_)* {return 307; /* ret un jeton */}
({chiffre}+\.{chiffre}*|\.{chiffre}+)([eE][-+]?{chiffre}+)? {return 308; /* ret un jeton */}
[\t\n]+ {/*ne rien faire, filtrer les blancs}
"//".*\n {/*ne rien faire, filtrer les commentaires c++*/}
"/*"([^*]|"*"+[^*/])*"*"+"/" {/*ne rien faire filtrer les commentaires C*/}
. {return yytext[0];}
%%
/* ZONE DES FONCTIONS C */
main()
{int j; 
char *invite="Saisissez un(des) mot(s) SVP :";
printf(invite);
while ((j=yylex())!=0) printf("\nJeton : %i; de lexeme %s\n%s",j,yytext,invite);}