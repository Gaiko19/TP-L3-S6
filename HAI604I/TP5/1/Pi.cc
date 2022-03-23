#include <stdlib.h>
#include <sys/types.h>
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>//perror
using namespace std;

struct strMonMsg {
    long monetiquette ;
    int data ;
} ;


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
        
    int msgid = msgget(cle, 0666);
    if(msgid==-1) {
        perror("erreur msgget récupération de la file : ");
        exit(2);
    }
    cout << "msgget ok" << endl;
    strMonMsg msg;
    msg.data = 50;
    msg.monetiquette = 10;


    int depot = msgsnd(msgid, &msg, sizeof(msg.data), 0);
    if(depot==-1) {
        perror("erreur envoi du msg : ");
        exit(2);
    }
    cout << "Message envoyé\n" << endl;

    
    return 0;
}
