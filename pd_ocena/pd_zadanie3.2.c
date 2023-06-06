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

    int shmid1, shmid2;
    char *value;
    char txt1[100];
    char txt2[100];

    shmid1 = shmget(45286, MAX*sizeof(int), IPC_CREAT|0600);
    if (shmid1 == -1) {
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1);
    
    value = shmat(shmid1, NULL, 0);
    if (value == NULL) {
        perror("Przylaczenie segmentu pamieci wspoldzielonej");
        exit(1);
    }
    scanf(" %[^\n]50s", txt1);
    strcpy(value, txt1);
    }

    shmid2 = shmget(45287, MAX*sizeof(int), IPC_CREAT|0600);
    if (shmid2 == -1) {
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1);
    
    value = shmat(shmid2, NULL, 0);
    if (value == NULL) {
        perror("Przylaczenie segmentu pamieci wspoldzielonej");
        exit(1);
    }
    scanf(" %[^\n]50s", txt2);
    strcpy(value, txt2);
    }
    return 0;
}