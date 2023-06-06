#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main() {

    int counter = 0;
    char buffer[100];
    int file = open("plikzad4.txt",  O_CREAT | O_RDWR, 0700);
    if (fork() == 0) {
        scanf(" %[^\n]50s", buffer);
        write(file, buffer, strlen(buffer));
        if (fork() == 0) {
            scanf(" %[^\n]50s", buffer);
            write(file, buffer, strlen(buffer));
            if (fork() == 0) {
                counter = lseek(file, 0, SEEK_END); // wynika to na podstawie ilosci przesuniecia bajtow, poniewaz jedna wartosc char to przesuniecie o 1, wiedzac o ile seek przeskoczy do konca dowiemy sie ile charow znajdowalo sie w pliku
                printf("%d", counter);        
                exit(1);
            }
            wait(NULL);
            exit(1);
        }
        wait(NULL);
        exit(1);
    }
    close(file);
    wait(NULL);
    exit(1);
    
return 0;
}