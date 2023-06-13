#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>


int main() {

    char* output;

    int shmid = shmget(2115, sizeof(int), IPC_CREAT|0600);
    if (shmid == -1) {
        perror("blad towrzenia segmentu pamieci");
        exit(1);
    }
    output = shmat(shmid, NULL, 0);
    if (output == NULL) {
        perror("blad przylaczenia segmentu");
        exit(1);
    }
    printf("tekst z pamieci: %s", output);





    return 0;
}