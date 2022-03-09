#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include "calcul.h"
#include <pthread.h>
using namespace std;


struct predicatRdv {
// regroupes les données partagées entres les threads participants aux RdV :
  int waitingThread;
  pthread_mutex_t lock;
  pthread_cond_t cond;
};

struct params {
  // structure pour regrouper les paramètres d'un thread. 
  int idThread; // un identifiant de thread, de 1 à N (N le nombre total de theads secondaires)
  int num;
  struct predicatRdv* sharedVar;

};

// fonction associée a chaque thread participant au RdV.
void * participant (void * p){ 

  struct params * args = (struct params *) p;
  struct predicatRdv * predicat = args -> sharedVar;

  pthread_mutex_lock(&predicat->lock);

  // simulation d'un long calcul pour le travail avant RdV
  printf("Attente...\n");
  calcul (args -> idThread + rand() % 10); // c'est un exemple.
  int cpt = predicat->waitingThread;

  if (cpt-- == args->num) {
      printf("[Thread %i] : dernier thread je réveille tout le monde !\n", args->idThread);
      pthread_cond_broadcast(&predicat->cond);
  }

  // RdV 
  while (cpt != 0) {  // attention : le dernier arrivé ne doit pas attendre. Il doit réveiller tous les autres.
    pthread_cond_wait(&predicat->cond, &predicat->lock);
  }

  pthread_mutex_unlock(&predicat->lock);

  ...
  calcul ( ...); // reprise et poursuite de l'execution.


  ...
  pthread_exit(NULL); // fortement recommandé.
}


int main(int argc, char * argv[]){
  
  if (argc!=2) {
    cout << " argument requis " << endl;
    cout << "./prog nombre_Threads" << endl;
    exit(1);
  }


  // initialisations 
  pthread_t threads[atoi(argv[1])];
  struct params tabParams[atoi(argv[1])];


  srand(atoi(argv[1]));  // initialisation de rand pour la simulation de longs calculs

  struct predicatRdv predicat;
  predicat.waitingThread = atoi(argv[1]);

  pthread_mutex_t lock;
  pthread_cond_t cond;
  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&cond, NULL);

  // création des threards 
  for (int i = 0; i < atoi(argv[1]); i++){
    tabParams[i].idThread = i + 1;
    tabParams[i].sharedVar = &predicat;
    tabParams[i].num = atoi(argv[1]);
    predicat.lock = lock;
    predicat.cond = cond;

  }
  for (int i = 0; i < atoi(argv[1]); i++){
      tabParams->idThread = i;
      if (pthread_create(&threads[i], NULL, participant, tabParams) != 0){
        perror("erreur creation thread");
        exit(1);
      }
  }

  // Attente de la fin des threads. Partie obligatoire 
  for (int i = 0; i < atoi(argv[1]); i++) {
      pthread_join(threads[i], NULL);
  }

  printf("[Thread principal] : fin de tous les threads secondaires\n");
  
  // terminer "proprement".
  pthread_mutex_destroy(&lock);
  pthread_cond_destroy(&cond);
}