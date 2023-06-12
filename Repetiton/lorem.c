#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {

    int file;
    char lorem[] = "Lorem\n";
    file = open("Lorem.txt", O_CREAT | O_RDWR, 0700);
    for (int i = 0; i < 15; i++) {
    write(file, lorem, strlen(lorem));
    }


    close(file);
    return 0;
}