#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {

    char buf[1024];
    char readingFromBuf[1024];
    char duplicator[1024];
    char readingFromP2[1024];
    int child1 = fork();
    if (child1 == 0) {
        int file1 = open("/Users/kamilgolawski/Nauka/Programowanie/Semestr2-C/sandbox-C/P1.txt", O_RDWR | O_CREAT, 0700);
        creat("/Users/kamilgolawski/Nauka/Programowanie/Semestr2-C/sandbox-C/P2.txt", 0700);
        int child1point1 = fork();
        if (child1point1 == 0) {
            read(1, buf, 1024);
            write(file1, buf, strlen(buf));
            exit(1);
        }
        wait(NULL);

        int child1point2 = fork();
        
        if (child1point2 == 0) {
            int file1Copy = dup(file1);
            lseek(file1Copy, 0, SEEK_SET);
            read(file1Copy, readingFromBuf, 1024);
            printf("Tekst z pliku: %s", readingFromBuf);
            exit(1);
        }
        wait(NULL);
        close(file1);

    exit(1);
    }
    wait(NULL);

    int child2 = fork();
    if (child2 == 0) {
       int file1ForChild2 = open("/Users/kamilgolawski/Nauka/Programowanie/Semestr2-C/sandbox-C/P1.txt", O_RDONLY, 0700);
       int file2ForChild2 = open("/Users/kamilgolawski/Nauka/Programowanie/Semestr2-C/sandbox-C/P2.txt", O_RDWR, 0700);
       lseek(file2ForChild2, 0, SEEK_SET);
       read(file1ForChild2, duplicator, 1024);
       printf("Tekst do skopiowania z  pliku: %s", duplicator);
       write(file2ForChild2, duplicator, strlen(duplicator));
       int child2point1 = fork();
       if (child2point1 == 0){
            int file2ForChild2Copy = dup(file2ForChild2);
            lseek(file2ForChild2Copy, 0, SEEK_SET);
            read(file2ForChild2, readingFromP2, 1024);
            printf("Napis z pliku P2: %s", readingFromP2);
            exit(1);
       }
        wait(NULL);
        close(file1ForChild2);
        close(file2ForChild2);

       int child2point2 = fork();
       if (child2point2 == 0){
        printf("sprawdza czywchodzi");
            if (access(file2ForChild2, X_OK) == 0){
                printf("plik ma juz mozliwosc wykonywania\n");
            } else {
                chmod(file2ForChild2, 0700);
                 printf("plik zostal zmieniony i ma juz mozliwosc wykonywania\n");
            }
            exit(1);
       }
    
    exit(1);   
    }
    wait(NULL);
    
    int child3 = fork();
    if (child3 == 0) {
        int zombie1 = fork();
        if (zombie1 > 0){ sleep(50);} else { exit(0); }
        int zombie2 = fork();
        if (zombie2 > 0){ sleep(50);} else { exit(0); }
        }
    wait(NULL);
 return 0;
}