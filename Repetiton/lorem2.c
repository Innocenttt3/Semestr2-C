#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    char txtFromFile[1024];
    int file = open("temp.txt", O_RDWR, 0700);
    read(file, txtFromFile, sizeof(txtFromFile));
    printf("odczyt z pliku: %s§", txtFromFile);

  
    return 0;
}