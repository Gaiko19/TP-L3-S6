#include <stdlib.h>
#include <sys/types.h>
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>//perror
using namespace std;

struct sMsg {
    long etiq ; 
    int mot;
};

int main(int argc, char * argv[]){

    if (argc!=3) {
        cout<<"Nbre d'args invalide, utilisation :"<< endl;
        cout << argv[0] << " fichier-pour-cle-ipc entier-pour-cle-ipc"<< endl;
        exit(0);
    }
        
    key_t cle=ftok(argv[1], atoi(argv[2]));

    if (cle==-1) {
        perror("Erreur ftok : ");
        exit(2);
    }

    cout << "ftok ok" << endl;
        
    int msgid = msgget(cle, IPC_CREAT| IPC_EXCL| 0666);
    if(msgid==-1) {
        perror("erreur msgget création de la file : ");
        exit(2);
    }
    cout << "msgget ok" << endl;

    sMsg vMsg;
    int ret = msgrcv(msgid, &vMsg, (size_t)sizeof(vMsg.mot), (long) vMsg.etiq, 0);
    if (ret == -1) {
        perror("Problème réception message.\n");
    }
    else {
        cout << "Message : " << vMsg.mot<< endl;
    }




    return 0;
}
