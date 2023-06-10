#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main() {
  int fdes, res, zapis;
  char c[1024];
  //char w[1024];
  // Utworzenie pliku FIFO 
  /* if ((mkfifo("myfifo",0666))==-1){
        printf("fifo error \n");
        exit(1);
    };*/
  fdes = open("FIFO",O_WRONLY);
  if(fdes < 0) { 
  printf("Open error %d \n",errno); 
  exit(1); 
  }
        zapis = write(fdes,"Ala ma kota",11);
        close(fdes);
    
    return 0;

}  
