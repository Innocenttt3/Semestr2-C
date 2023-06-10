#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {

    
    int child1 = fork();
    if(child1 == 0){
        execl("/bin/pwd", "pwd", NULL);
        exit(1);
    }
    wait(NULL);

    int child2 = fork();
    if(child2 == 0){
        execl("/bin/ls", "ls", "-la", NULL);
        exit(1);
    }
    wait(NULL);
   
return 0;
}