#include <cstdlib>
#include <stdio.h>
#include "image_ppm.h"
#include <string>
using namespace std;



int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgRed[250], cNomImgGreen[250], cNomImgBlue[250];
  int nH, nW, nTaille;

  if (argc != 5) 
    {
      printf("Usage: ImageIn.ppm ImageOutRed.pgm ImageOutGreen.pgm ImageOutBlue.pgm\n"); 
      exit (1) ;
    }
  
  sscanf (argv[1],"%s",cNomImgLue) ;
  sscanf (argv[2],"%s",cNomImgRed) ;
  sscanf (argv[3],"%s",cNomImgGreen) ;
  sscanf (argv[4],"%s",cNomImgBlue) ;

  OCTET *ImgIn;
  OCTET *ImgOutY;
  OCTET *ImgOutCb;
  OCTET *ImgOutCr;

  lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
  nTaille = (nH * nW) *3;
  printf("Nom image lue : %s\n",cNomImgLue);
  printf("Largeur : %i, Hauteur %i\n", nW, nH);

  allocation_tableau(ImgIn, OCTET, nTaille);
  allocation_tableau(ImgOutY, OCTET, nTaille);
  allocation_tableau(ImgOutCb, OCTET, nTaille);
  allocation_tableau(ImgOutCr, OCTET, nTaille);

  lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
    for (int i=0; i < nH; i++) {
      for (int j=0; j < nW; j++) {
          ImgOutY[(i*nW+j)] = (0.3*ImgIn[(i*nW+j)*3] + 0.6*ImgIn[(i*nW+j)*3+1] + 0.1*ImgIn[(i*nW+j)*3+2]);
          ImgOutCb[(i*nW+j)] = -0.1687 * ImgIn[(i*nW+j)*3] -0.3313 * ImgIn[(i*nW+j)*3+1] + 0.5 * ImgIn[(i*nW+j)*3+2] + 128;
          ImgOutCr[(i*nW+j)] = 0.5 * ImgIn[(i*nW+j)*3] -0.4187 * ImgIn[(i*nW+j)*3+1] -0.0813 * ImgIn[(i*nW+j)*3+2] + 128;

      }
    }
    ecrire_image_pgm(cNomImgRed, ImgOutCr,  nH, nW);
    ecrire_image_pgm(cNomImgBlue, ImgOutCb,  nH, nW);
    ecrire_image_pgm(cNomImgGreen, ImgOutY,  nH, nW);
    free(ImgIn);
    free(ImgOutY);
    free(ImgOutCb);
    free(ImgOutCr);
  return 1;
}