/** @file analdesc.c        
 *@author Michel Meynard
 *@brief Analyse descendante récursive d'expression arithmétique
 *
 * Ce fichier contient un reconnaisseur d'expressions arithmétiques composée de 
 * littéraux entiers sur un car, des opérateurs +, * et du parenthésage ().
 * Remarque : soit rediriger en entrée un fichier, soit terminer par deux 
 * caractères EOF (Ctrl-D), un pour lancer la lecture, l'autre comme "vrai" EOF.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
                             /* les macros sont des blocs : pas de ';' apres */
#define AVANCER {jeton=getchar();numcar++;}
#define TEST_AVANCE(prevu) {if (jeton==(prevu)) AVANCER else ERREUR_SYNTAXE}
#define ERREUR_SYNTAXE {printf("\nMot non reconnu : erreur de syntaxe \
au caractère numéro %d \n",numcar); exit(1);} 


int E();int R(int x);int T();int S(int x);int F(); /* déclars */

int jeton;                       /* caractère courant du flot d'entrée */
int numcar=0;                    /* numero du caractère courant (jeton) */
int somme=0;

int E(){
  return (R(T()));                          /* regle : E->TR */
}
int R(int x){
  if (jeton=='+') {             /* regle : R->+TR */
    AVANCER
    return R(x + T());
  }
    return x;                       /* regle : R->epsilon */
}
int T(){
  return S(F());                 /* regle : T->FS */
}
int S(int x){
  if (jeton=='*') {             /* regle : S->*FS */
    AVANCER
    return S(F() * x);
  }
    return x;                    /* regle : S->epsilon */
}
int F(int x){
  if (jeton=='(') {             /* regle : F->(E) */
    AVANCER
    TEST_AVANCE(')')
    return E();
  }
  else 
    if (isdigit(jeton)) {         /* regle : F->0|1|...|9 */
        char str[] = {jeton, '\0'};
        int jetonChar = atoi(str);
      AVANCER
        return jetonChar;
    }
    else ERREUR_SYNTAXE
}
int main(void){                 /* Fonction principale */
  AVANCER			/* initialiser jeton sur le premier car */
  int res = E();                          /* axiome */
  if (jeton==EOF)               /* expression reconnue et rien après */
    printf("\nMot reconnu : %i\n", res); 
  else ERREUR_SYNTAXE           /* expression reconnue mais il reste des car */
  return 0;
}
