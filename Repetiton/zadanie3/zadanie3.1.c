#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>           
#include <sys/stat.h>
#include <unistd.h>

int main() {

    int fdes, saving;
    char input[100];
    scanf("%[ ^\n]100s", input);


    mkfifo("FIFO", 0666);
    fdes = open("FIFO", O_RDWR);
    if (fdes < 0) {
        printf("opening Error");
        exit(1);
    }
    saving = write(fdes, input, strlen(input));
    close(fdes);


    return 0;
}