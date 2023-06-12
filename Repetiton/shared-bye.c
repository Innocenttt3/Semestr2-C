#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>


int main() {

    char *byeTxt = "bye";
    char *memoryMsg;

    int schmid = shmget(2137, sizeof(int), IPC_CREAT|0600);
    if (schmid == -1) {
        perror("blad towrzenia pamieci");
        exit(1);
    }

    memoryMsg = shmat(schmid, NULL, 0);
    if(memoryMsg == NULL) {
        perror("blad przylaczenia pamieci");
        exit(1);
    }
    strcpy(memoryMsg, byeTxt);
    return 0;
}