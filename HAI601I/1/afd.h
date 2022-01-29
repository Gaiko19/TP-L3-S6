/**
 * @file afd.h     
 * @author Michel Meynard
 * @brief Définition d'un AFD
 */
#define EINIT 0
#define EENT 1
#define EFLOT 2
#define E2 3
#define EI 4
#define EIF 5
#define EID 6
#define EP 7
#define EB 8
#define ES 9
#define ESS 10
#define ECOMCPP 11
#define ESE 12
#define ESSE 13
#define ECOMC 14        
#define NBETAT 15

#define ID = 1
#define IF
#define LITENT
#define LITFLOT
#define EMPTY = -1
#define COMCPP = -2
#define COMC = -3


int TRANS[NBETAT][256];		/* table de transition : état suivant */
int JETON[NBETAT];		/* jeton à retourner */

/** construit un ensemble de transitions de ed à ef pour un intervale de char
*@param ed l'état de départ
*@param ef l'état final
*@param cd char de début
*@param cf char de fin
*/

void classe(int ed, int cd, int cf, int ef) {
  for(char c = cd; c <= cf; c++) {
    TRANS[ed][c] = ef;
  }
}


int creerAfd(){			/* Construction de l'AFD */
  int i;int j;			/* variables locales */
  for (i=0;i<NBETAT;i++){
    for(j=0;j<256;j++) TRANS[i][j]=-1; /* init vide */
    JETON[i]=0;			/* init tous états non finaux */
  }
  /* Transitions de l'AFD */

  // Décimaux et flottants
  classe( EINIT,'1','9',EENT);
  classe(EENT, '0','9',EENT);
  TRANS[EENT]['.']=EFLOT;
  classe(EFLOT,'0','9',EFLOT);
  TRANS[EINIT]['0'] = E2;
  TRANS[E2]['.'] = EFLOT;
  TRANS[EINIT]['.'] = EP;

  JETON[EENT]=LITENT;
  JETON[EFLOT]=LITFLOT;
  JETON[E2]=LITENT;
  
  // IF ID
  classe(EINIT, 'a', 'z', EID);
  classe(EINIT, 'A', 'Z', EID);
  TRANS[EINIT]['_'] = EID;
  TRANS[EINIT]['i'] = EI;
  TRANS[EI]['f'] = EIF;
  classe(EIF, 'a', 'z', EID);
  classe(EIF, 'A', 'Z', EID);
  TRANS[EIF]['_'] = EID;
  classe(EID, 'a', 'z', EID);
  classe(EID, 'A', 'Z', EID);
  classe(EID, '0', '9', EID);
  TRANS[EID]['_'] = EID;

  JETON[EI] = JETON[EID] = ID;
  JETON[EIF] = IF;

  // Espaces et commentaires
  TRANS[EINIT]['/'] = ES;
  TRANS[EINIT]['\n'] = TRANS[EINIT]['\t'] = TRANS[EINIT][' '] = EB;
  TRANS[EB]['\n'] = TRANS[EB]['\t'] = TRANS[EB][' '] = EB;
  TRANS[ES]['/'] = ESS;

  // ASCII
  classe(ESS, 0, 255, ESS);
  TRANS[ESS]['\n'] = ECOMCPP;
  TRANS[ES]['*'] = ESE;
  classe(ESE, 0, 255, ESE);
  TRANS[ESE]['*'] = ESSE;
  classe(ESSE, 0, 255, ESE);
  TRANS[ESSE]['/'] = ECOMC;
  TRANS[ESSE]['*'] = ESSE;

  JETON[EB] = EMPTY;
  JETON[ECOMCPP] = COMCPP;
  JETON[ECOMC] = COMC;
  return 0;
}



