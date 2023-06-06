

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <pthread.h> 
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

char* temp;
int shmid;
char txt[] = "test123";

void* funIN(void *arg) {
    shmid = shmget(45281, strlen(txt), IPC_CREAT|0600);  
    if (shmid == -1)
    {    
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1); 
    }   

    char *buf = shmat(shmid, NULL, 0);  
    if (buf == NULL)
    {
           perror("Przylaczenie segmentu pamieci wspoldzielonej");
           exit(1); 
    } 
    strcpy(buf, txt);
    return NULL;
}

void* funOUT(void *arg) {
    shmid = shmget(45281, strlen(txt), IPC_CREAT|0600);  
    if (shmid == -1)
    {    
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1); 
    }   

    char *buf = shmat(shmid, NULL, 0);  
    if (buf == NULL)
    {
           perror("Przylaczenie segmentu pamieci wspoldzielonej");
           exit(1); 
    } 
    temp = buf;
    printf("%s\n", buf);
    return NULL;
}

void* funCOUNT(void *arg) {
    int counter = 0;
    char letter;
    scanf("%c", &letter);
    for (int i = 0; i < strlen(temp); i++)
    {
        if(temp[i] == letter) { counter++; }
    }
    printf("%d", counter);
    return NULL;
}

int main(){

    pthread_t firstThread;
    pthread_t secondThread;
    pthread_t thirdThread;
    if(pthread_create(&firstThread, NULL, funIN, NULL)) {
        pthread_join(firstThread, NULL);
        printf("błąd tworzenia wątku.");
        abort();

    }

    if(pthread_create(&secondThread, NULL, funOUT, NULL)) {
        printf("błąd tworzenia wątku.");
        abort();

    }
    if(pthread_create(&thirdThread, NULL, funCOUNT, NULL)) {
        printf("błąd tworzenia wątku.");
        abort();

    }

    pthread_join(firstThread, NULL);
    pthread_join(secondThread, NULL);
    pthread_join(thirdThread, NULL);
    return 0;
} 


