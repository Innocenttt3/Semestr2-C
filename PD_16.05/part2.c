#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 10
int main(){

    int shmid, i;  
    int *buf;  
    shmid = shmget(45281, MAX*sizeof(int), IPC_CREAT|0600);  
    if (shmid == -1)
    {    
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1); 
    }   

    buf = (int*)shmat(shmid, NULL, 0);  
    if (buf == NULL)
    {
           perror("Przylaczenie segmentu pamieci wspoldzielonej");
           exit(1); 
    }   
    printf("%d", *buf);
    return 0;
} 


