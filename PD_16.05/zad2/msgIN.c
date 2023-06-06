#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 10

int main() {

    srand(time(NULL));
    int shmid;
    char *value;
    int p = 10;
    shmid = shmget(45281, MAX*sizeof(int), IPC_CREAT|0600);
    
    if (shmid == -1) {
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1);
    }

    value = shmat(shmid, NULL, 0);
    if (value == NULL) {
        perror("Przylaczenie segmentu pamieci wspoldzielonej");
        exit(1);
    }
    char *txt = {"Bye"};
    strcpy(value, txt);
}