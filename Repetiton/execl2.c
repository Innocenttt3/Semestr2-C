#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("poczatek listy \n");
    if (execl("/bin/ps", "ps", "-u kamilgolawski", NULL) == -1) {
        perror("Błąd uruchomienia programu");
        exit(EXIT_FAILURE);
    }
    printf("koniec listy \n");

    return 0;
}