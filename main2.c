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

  mkfifo("FIFO",0666);
  fdes = open("FIFO",O_RDWR);
  if(fdes < 0) { 
  printf("Open error %d \n",errno); 
  exit(1); 
  }
  lseek(fdes, 0, SEEK_SET);
  res = read(fdes, c, zapis); 
  printf("Odczytano: %s\n", c);
  close(fdes);
}