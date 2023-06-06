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

int a, b;
void* sum(void *arg) {
    printf("%d \n", a+b);
    return NULL;
}

void* gap(void *arg) {
    printf("%d \n", a-b);
    return NULL;
}

void* multi(void *arg) {
    printf("%d \n", a * b);
    return NULL;
}

int main() {

    pthread_t sumThread;
    pthread_t gapThread;
    pthread_t multiThread;
    scanf("%d %d", &a, &b);

    if (pthread_create(&sumThread, NULL, sum, NULL)) {
        printf("błąd tworzenia wątku.");
        abort();
    }

    if (pthread_create(&gapThread, NULL, gap, NULL)) {
        printf("błąd tworzenia wątku.");
        abort();
    }

    int sumResult = pthread_join(sumThread, NULL);
    int gapResult = pthread_join(gapThread, NULL);

    if (gapResult == 0 && sumResult == 0) {
        printf("Pierwsze dwa watki zakonczone.\n");
        if (pthread_create(&multiThread, NULL, multi, NULL)) {
        printf("błąd tworzenia wątku.");
        abort();
    }
    } else {
        printf("Błąd podczas oczekiwania na zakończenie wątkow.\n");
    }    
    return 0;
}