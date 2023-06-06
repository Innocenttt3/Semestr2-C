#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main() {

int fd[2];
int rd;
int counter = 0;
int i = 0;

 if(pipe(fd) < 0) {
      perror("Lacze ");

 exit(10); 
 } 

  char userTxt[100];
  char readTxt[100];

  if (fork() == 0){
    wait(NULL);
    close(fd[0]);
    scanf(" %[^\n]100s", userTxt);
    write(fd[1], userTxt, strlen(userTxt));
    close(fd[1]);
    exit(1);
    }
    
  if (fork() == 0){
    wait(NULL);
    close(fd[1]);
    do {
       rd = read(fd[0], readTxt, strlen(readTxt));
     } while(rd > 0);
     close(fd[0]);
     while(readTxt[i]){
      counter++;
      i++;
     }
    printf("%d", counter);
    exit(1);
  }
return 0;
}
