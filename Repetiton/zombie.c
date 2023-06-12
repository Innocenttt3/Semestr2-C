// A C program to demonstrate Zombie Process. 
// Child becomes Zombie as parent is sleeping
// when child process exits.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int pid1 = fork();
    if(pid1 > 0) {
        sleep(50);
    }
    else
        exit(0);
        
    return 0;
}