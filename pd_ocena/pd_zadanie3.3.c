#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10


int numberConverter(char *data) {
    int result = 0;
    for (int i = 0; i < strlen(data); i++) {
        if(data[i] < 58 && data[i] > 47){
        result = result *  10;
        result = result + data[i] - '0'; //odjecie 0 zamineia wartosc z chara na wartosc liczbowa na podstawie tablicy ascii ;
        }
        else{ printf("%s", data);}
        break;
    } 
    return result;
}
int main(){

    int sumOfAll;
    int shmid1, shmid2, shmid3, shmid4;  
    char *buf1, *buf2, *buf3, *buf4;  
    shmid1 = shmget(45281, MAX*sizeof(int), IPC_CREAT|0600);  
    if (shmid1 == -1)
    {    
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1); 
    }   

    buf1 = shmat(shmid1, NULL, 0);  
    if (buf1 == NULL)
    {
           perror("Przylaczenie segmentu pamieci wspoldzielonej");
           exit(1); 
    } 
    printf("%s", buf1);

    shmid2 = shmget(45282, MAX*sizeof(int), IPC_CREAT|0600);  
    if (shmid2 == -1)
    {    
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1); 
    }   

    buf2 = shmat(shmid2, NULL, 0);  
    if (buf1 == NULL)
    {
           perror("Przylaczenie segmentu pamieci wspoldzielonej");
           exit(1); 
    } 
    printf("%s", buf2);

    shmid3 = shmget(45286, MAX*sizeof(int), IPC_CREAT|0600);  
    if (shmid3 == -1)
    {    
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1); 
    }   

    buf3 = shmat(shmid3, NULL, 0);  
    if (buf3 == NULL)
    {
           perror("Przylaczenie segmentu pamieci wspoldzielonej");
           exit(1); 
    } 
    printf("%s", buf3);

    shmid4 = shmget(45287, MAX*sizeof(int), IPC_CREAT|0600);  
    if (shmid4 == -1)
    {    
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1); 
    }   

    buf4 = shmat(shmid4, NULL, 0);  
    if (buf4 == NULL)
    {
           perror("Przylaczenie segmentu pamieci wspoldzielonej");
           exit(1); 
    } 
    printf("%s", buf4);
    
    sumOfAll = numberConverter(buf1) + numberConverter(buf2) + numberConverter(buf3) + numberConverter(buf4);
    printf("%d", sumOfAll);
    return 0;
} 


