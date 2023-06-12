#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>


int main() {

    int randomNumber = 5;
    char *txt;
    char *toCopy = "napis";    
    int schmid = shmget(2115, sizeof(int), IPC_CREAT|0600);
    if (schmid == -1) {
        perror("utowrzenie pamieci");
        exit(1);
    }

    txt = shmat(schmid, NULL, 0);
    if (txt == NULL) {
        perror("przylaczenie segmentu pamieci");
        exit(1);
    }
    for (int i = 0; i < 5; i++) {
        printf("tekst z pamieci: %s \n", txt); 
    }
  


    return 0;
}
