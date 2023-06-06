#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    int fd[2];
    int ft;
    int i = 0;
    char userTxt[50];
    char readTxt[50];
    // int counter = 0;

    if (pipe(fd) < 0) {
        perror("Blad tworzenia lacza nienazwanego");
        exit(10);
    }

    scanf("%[^\n]50s", userTxt);
    if (fork() == 0) {
        wait(NULL);
        close(fd[0]);
        write(fd[1], userTxt, strlen(userTxt) + 1);
        close(fd[1]);
        exit(1);
    }

    if (fork() == 0) {
        wait(NULL);
        close(fd[1]);
        int counter = read(fd[0], readTxt, 50);
        counter--;
        close(fd[0]);
        printf("%d", counter);
        exit(1);
    }
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    ft = open(myfifo, O_WRONLY);
    write(fd, readTxt, strlen(readTxt)+1);
    close(fd);


    return 0;
}