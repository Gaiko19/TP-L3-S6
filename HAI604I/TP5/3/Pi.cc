#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
using namespace std;

void calcul() {
    int wait = rand()%10 + 1;
    sleep(wait);
}

union semun{
    int val;
    struct semid_ds * buf;
    ushort * array;
} valinit;

int main(int argc, char * argv[]){

    if (argc!=5) {
        cout<<"Nbre d'args invalide, utilisation :"<< endl;
        cout << argv[0] << " fichier-pour-cle-ipc entier-pour-cle-ipc nb-zones num-traitement"<< endl;
        exit(0);
    }

    int nbSem = atoi(argv[3]);
    int numProc = atoi(argv[4]);
    key_t cle=ftok(argv[1], atoi(argv[2]));
    if (cle==-1) {
        perror("Erreur ftok : ");
        exit(2);
    }

    cout << "ftok ok" << endl;

    int semid = semget(cle, nbSem, 0666);
    if(semid==-1) {
        perror("erreur msgget récupération de la file : ");
        exit(2);
    }
    cout << "msgget ok" << endl;

    for (int i =0; i < nbSem; i++) {
        struct sembuf op[] = {
            {(ushort)i, (short)(numProc-1),0},
            {(ushort)i, (short)(numProc),0},
        };
        // Vérif de l'accés à la ressource
        if (semop(semid,op, 1) == -1) {
            perror("Vous n'avez pas accés\n");
            exit(EXIT_FAILURE);
        }
        printf("Calcul n°%i sur la zone %i.\n", numProc, i);
        calcul();

        printf("Calcul n°%i terminé sur la zone %i.\n", numProc, i);
        // On ajoute 1 au tableau de sémaphores car ce processus a terminé son traitement
        if (semop(semid, op+1, 1) == -1) {
            exit(EXIT_FAILURE);
        }

        // Récupération de semaphores[i] pour affichage
        int semValue = semctl(semid, 0, GETVAL, (semun){ .val = 0 });
        if (semValue == -1) 
            exit(EXIT_FAILURE);
        printf("Valeur actuelle de la sémaphore : %i\n", semValue);

        // Tant que semaphores[i] n'est pas à 0, on attend.
        if (semop(semid, op + 1, 1) == -1)
            exit(EXIT_FAILURE);
    }

    return 0;
}
