#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int a, b, sizeOfArray;
int *arr;

void* multi(void *arg) {
    printf("%d \n", a * 2);
    return NULL;
}


void* printPart1(void *arg) {
    for (int i = 0; i < sizeOfArray/2; i++ ) {
        arr[i] = a;
    }
    return NULL;
}

void* printPart2(void *arg) {
    for (int y = sizeOfArray/2; y < sizeOfArray; y++ ) {
        arr[y] = b;
    }
    return NULL;
}

int main() {

    pthread_t writerPart1;
    pthread_t writerPart2;

    printf("podaj wielksoc tablicy: ");
    scanf("%d", &sizeOfArray);

    arr = (int*)malloc(sizeOfArray * sizeof(int));

    printf("podaj 1 wartosc tablicy \n");
    scanf("%d", &a);

    printf("podaj 2 wartosc tablicy \n");
    scanf("%d", &b);
    
    if (pthread_create(&writerPart1, NULL, printPart1, NULL)) {
        printf("błąd tworzenia wątku.");
        abort();
    }
    if (pthread_create(&writerPart2, NULL, printPart2, NULL)) {
        printf("błąd tworzenia wątku.");
        abort();
    }
    int part1 = pthread_join(writerPart1, NULL);
    int part2 = pthread_join(writerPart2, NULL);

    for (int x = 0; x < sizeOfArray; x++) {
        printf("wartosci tabeli %d -> %d \n", x, arr[x]);
    }
}