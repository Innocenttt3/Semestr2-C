#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/shm.h>
#include <errno.h>
#include <ctype.h>
#include <pthread.h>

void* funct(void* arg) {
    char txt[100];
    char txtUpper[100];
    printf("podaj tekst do podmianki: ");
    scanf(" %[^\n]100s", txt);
    for (int i = 0; i < strlen(txt); i++) {
        txtUpper[i] = toupper(txt[i]);
    }
    printf("%s", txtUpper);
    return NULL;
}

int main() {

    char* value;
    char* userInput;

    mkdir("./katalog1", 0700);
    mkdir("./katalog1/katalog2", 0700);
    
    int file1 = open("./katalog1/plik1", O_CREAT | O_RDWR, 0700);
    close(file1);

    int shmid = shmget(2115, sizeof(int), IPC_CREAT|0600);
    if (shmid == -1) {
        perror("nie utowrzono segmentu pamieci");
        exit(1);
    }
    value = shmat(shmid, NULL, 0);
        if (value == NULL){
            perror("nie przylaczono segmentu pamieci");
            exit(1);
        }
    scanf("%s", userInput);
    strcpy(value, userInput);    
    printf("tekst wpisany do pamieci: %s", value);
    // if (shmdt(value) == 0) {
    //     printf("odlaczono segment pamieci \n");
    // }

    // if (shmctl(shmid, IPC_RMID, NULL) == 0) {
    //     printf("usuniecie segmentu pamieci \n");
    // } 

    // pthread_t thread1;

    // if (pthread_create(&thread1, NULL, funct, NULL)){
    //     printf("blad towrzenia watku");
    //     abort();
    // }
    // if (pthread_join(thread1, NULL)){
    //     printf("blad konczenia watku");
    //     abort();
    // }



    return 0;
}