#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>


int main() {

    int randomNumber = 5;
    char *txt;
    char *output; 
    int schmid = shmget(2137, sizeof(int), IPC_CREAT|0600);
    if (schmid == -1) {
        perror("utowrzenie pamieci");
        exit(1);
    }

    txt = shmat(schmid, NULL, 0);
    if (txt == NULL) {
        perror("przylaczenie segmentu pamieci");
        exit(1);
    }
    strcpy(output, txt);
    printf("output: %s", output);
    if (strcmp(output, "bye") == 0){
         if (shmdt(txt) == 0) {
            printf("\n odlaczono segment pamieci");
         };
         if (shmctl(schmid,IPC_RMID,NULL) == 0){
            printf("\n usunieto segment pamieci");
         }  ;
    }


    return 0;
}
