#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



int main() {
    
    int reader, reading;
    char output[100];

    reader = open("FIFO", O_RDONLY);
    if (reader < 0) {
        printf("error opening fifo %d \n", errno);
        exit(1);
    }
    reading = read(reader, output, 100);
    printf("tekst: %s", output);
    
    close(reader);
    int schmid;
    char *value;
    schmid = shmget(2115, sizeof(int), IPC_CREAT|0600);

    if (schmid == -1){
        perror("utworzono segment pamieci\n");
        exit(1);
    }

    value = shmat(schmid, NULL, 0);
    if (value == NULL) {
        perror("przylaczono segment pamieci\n");
        exit(1);
    }
    strcpy(output, value);
    printf("ciekawe co tu bd: %s", output);


    return 0;
}