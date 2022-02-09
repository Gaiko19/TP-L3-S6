#include <netinet/in.h>
#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 146980

int main(int argc, char *argv[]) {

  if (argc != 5){
    printf("utilisation : client ip_serveur port_serveur port_client nom_fichier\n Remaque : le parametre nom_fichier correspond au nom d'un fichier existant dans le répertoire emission\n");
    exit(0);
  }

  /* etape 1 : créer une socket */   
  int ds = socket(PF_INET, SOCK_STREAM, 0);
   if (ds == -1){
    perror("[Client] : pb creation socket :\n");
    exit(1);
  }
  printf("[Client] : creation de la socket réussie \n");
  /* etape 1.2 : nommage de la socket client */
  struct sockaddr_in sock_clt;
  socklen_t size =sizeof(struct sockaddr_in);
  sock_clt.sin_family = AF_INET;
  sock_clt.sin_addr.s_addr = INADDR_ANY;
  sock_clt.sin_port = htons((short)atoi(argv[3]));
  getsockname(ds, (struct sockaddr *)&sock_clt, &size);
  
  int res = bind(ds, (struct sockaddr*) &sock_clt, sizeof(sock_clt));
  if (res == -1){
      perror("[Client] : pb nommage socket :\n");
      exit(1);
  }
  /* etape 2 : designer la socket du serveur */
  struct sockaddr_in sock_srv;
  sock_srv.sin_family = AF_INET;
  sock_srv.sin_addr.s_addr = inet_addr(argv[1]);
  sock_srv.sin_port = htons(atoi(argv[2]));

  /* etape 3 : demander une connexion */
  int dsConnect = connect(ds, (struct sockaddr*)&sock_srv, sizeof(sock_srv));
  if (dsConnect == -1){
      perror("[Client] : pb connexion serveur :\n");
      exit(1);
  }
  printf("[Client] : connexion réussie\n");
  /* etape 4 : envoi de fichier : attention la question est générale. Il faut creuser pour définir un protocole d'échange entre le client et le serveur pour envoyer correctement un fichier */


  int totalSent = 0; // variable pour compter le nombre total d'octet effectivement envoyés au serveur du début à la fin des échanges.


 
  /* le bout de code suivant est une lecture de contenu d'un fichier dont le nom est passé en paramètre.
      - pour lire un fichier, il faut l'ouvrir en mode lecture
      - la lecture se fait par blocs d'octets jusqu'à la fin du fichier.
      - la taille d'un bloc est définie par la constante MAX_BUFFER_SIZE que vous pouvez modifier.

      Le code est à compléter pour mettre en place l'envoi d'un fichier.
  */

  // construction du nom du chemin vers le fichier
  int filename_size = strlen(argv[4]);
  //char* file_name[filename_size] = argv[3];

  char* filepath = malloc(strlen(argv[4]) + 16); // ./emission/+nom fichier +\0
  filepath[0] = '\0';
  strcat(filepath, "../emission/");
  strcat(filepath, argv[4]);

  printf("Client: je vais envoyer %s\n", filepath);

  // obtenir la taille du fichier
  struct stat attributes;
  if(stat(filepath, &attributes) == -1){
    perror("Client : erreur stat");
    free(filepath);
    exit(1);
  }


  int file_size = attributes.st_size; // cette copie est uniquement informer d'où obtenir la taille du fichier.
  
  printf("Client : taille du fichier : %d octets\n", file_size);
  
  // lecture du contenu d'un fichier
  FILE* file = fopen(filepath, "rb");
  if(file == NULL){
    perror("Client : erreur ouverture fichier \n");
    free(filepath);
    exit(1);   
  }
  free(filepath);

  int total_lu = 0;
  char buffer[MAX_BUFFER_SIZE];
  while(total_lu < file_size){
    
    size_t read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file);
    ssize_t envoi = send(ds, file, file_size, 0);

    if (envoi == -1) {
      perror("[CLIENT] : Problème lors de l'envoi \n");
      exit(1);
    }
    if(read == 0){
      if(ferror(file) != 0){
        perror("Client : erreur lors de la lecture du fichier \n");
        fclose(file);
        exit(1);
      }
      else{
        printf("Client : arrivé a la fin du la lecture du fichier\n");// fin du fichier
	      break;
      }
    }
    printf("Client : j'ai lu un bloc du fichier \n");  
    total_lu += envoi;
  }

  // fermeture du fichier
  fclose(file); 
   
  printf("Client : j'ai lu au total : %d octets \n", total_lu);  
 
  // fermeture socket
  if (close(ds) == -1) {
    printf("[Client] : pb fermeture socket\n");
    exit(1);
  }
  printf("Client : socket fermée !\n");
  printf("Client : c'est fini\n");

  return 0;
}