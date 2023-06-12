#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Początek\n");

    if (execl("/bin/ls", "ls", "/Users/kamilgolawski/Nauka", NULL) == -1) {
        perror("Błąd uruchomienia programu");
        exit(EXIT_FAILURE);
    }

    return 0;
}