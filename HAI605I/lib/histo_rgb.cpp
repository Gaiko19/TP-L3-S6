// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"
using namespace std;

int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomTxtEcrite[250];
  int nH, nW, nTaille;
  
  if (argc != 3) 
     {
       printf("Usage: ImageIn.pgm histo.dat\n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomTxtEcrite);


   OCTET *ImgIn;

   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
	
   //   for (int i=0; i < nTaille; i++)
   // {
   //  if ( ImgIn[i] < S) TxtOut[i]=0; else TxtOut[i]=255;
   //  }

    int TxtOutR[256] = {0};
    int TxtOutG[256] = {0};
    int TxtOutB[256] = {0};
    FILE* file_output;
    if((file_output = fopen(cNomTxtEcrite,"w")) == NULL) {
        exit(EXIT_FAILURE);
    };

    for (int i=0; i < nH; i++) {
        for (int j=0; j < nW; j++)
        {
        TxtOutR[ImgIn[(i*nW+j)*3]]++;
        TxtOutG[ImgIn[(i*nW+j)*3+1]]++;
        TxtOutB[ImgIn[(i*nW+j)*3+2]]++;
        }
    }

    for (int i = 0; i < 256; i++) {
        fprintf(file_output, "%d\t%d\t%d\t%d\n", i, TxtOutR[i], TxtOutG[i], TxtOutB[i]);
    }

    fclose(file_output);
    free(ImgIn);

   return 1;
}