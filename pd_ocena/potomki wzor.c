#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
printf("Pid programu: %d\n", getpid());
if(fork()==0){
    printf("Pid potomka: %d, Pid macierzystego: %d\n", getpid(), getppid());
    if(fork()==0){
        printf("Pid potomka: %d, Pid macierzystego: %d\n", getpid(), getppid());
        exit(0);
    }
        if(fork()==0){
        printf("Pid potomka: %d, Pid macierzystego: %d\n", getpid(), getppid());
        sleep(1);
        exit(0);
        }
    sleep(1);
    exit(0);
}
sleep(1);
}
