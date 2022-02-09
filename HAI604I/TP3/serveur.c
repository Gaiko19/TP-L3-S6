#include <netinet/in.h>
#include <stdio.h>//perror
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>//close
#include <stdlib.h>
#include <string.h>


#define MAX_BUFFER_SIZE 146980


int main(int argc, char *argv[])
{
  /* etape 0 : gestion des paramètres si vous souhaitez en passer */
  if (argc > 2) {
    printf("Utilisation : [port_serveur]\n");
    exit(1);
  }
  struct sockaddr_in socket_srv;
  struct sockaddr_in socket_clt;
  socklen_t size =sizeof(struct sockaddr_in);
  /* etape 1 : creer une socket d'écoute des demandes de connexions*/
  int srv = socket(PF_INET, SOCK_STREAM, 0);
  if (srv == -1) {
    perror("Serveur : problème lors de la création de la socket");
    exit(1);
  }
  printf("Serveur : création de la socket réussi !\n");
  /* etape 2 : nommage de la socket */
  socket_srv.sin_family = AF_INET;
  socket_srv.sin_addr.s_addr = INADDR_ANY;
  socket_srv.sin_port = htons((short)atoi(argv[1]));
  int res = bind(srv, (struct sockaddr *)&socket_srv, sizeof(socket_srv));
  getsockname(srv, (struct sockaddr *)&socket_srv, &size);

  if (res == -1) {
    perror("Serveur : problème lors du nommage de la socket");
    exit(1);
  }

  /* etape 3 : mise en ecoute des demandes de connexions */
  int srvListen = listen(srv, 10);
  if (srvListen == -1) {
      perror("Serveur : problème lors de la mise en écoute de la socket");
      exit(1);
  }
  printf("Serveur : socket serveur sur écoute.\n");
  /* etape 4 : plus qu'a attendre la demadne d'un client */

  int ds_client = accept(srv, (struct sockaddr*)&socket_clt, &size);
  if (ds_client == -1) {
    perror("Serveur : problème lors de la connection d'un client");
    exit(1);
  }
  printf("Serveur : connexion du client (%s:%i)\n", inet_ntoa(socket_clt.sin_addr), ntohs((short) socket_clt.sin_port));

  
  int totalRecv = 0; // un compteur du nombre total d'octets recus d'un client
  
  /* le protocol d'echange avec un client pour recevoir un fichier est à définir. Ici seul un exemple de code pour l'écriture dans un fichier est founi*/
  
  char* filepath = "../reception/toto"; // cette ligne n'est bien-sur qu'un exemple et doit être modifiée : le nom du fichier doit être reçu.
   
  // On ouvre le fichier dans lequel on va écrire
  FILE* file = fopen(filepath, "wb");
  if(file == NULL){
    perror("Serveur : erreur ouverture fichier: \n");
    exit(1);  
  }

  char * buffer ="ceci est un exemple de contenu a ecrire dans un fichier\n";
  size_t written = fwrite(buffer, sizeof(char), strlen(buffer)+1, file);
  if(written < strlen(buffer)+1){  // cette ligne est valide uniquement pour ce simple exemple
    perror("Serveur : Erreur a l'ecriture du fichier \n");
    fclose(file); 
  }

  printf("Serveur : ecriture dans fichier reussie. Vous pouvez vérifier la création du fichier et son contenu.\n");
  // fermeture du fichier
  fclose(file);
    
  printf("Serveur : c'est fini\n");
}








