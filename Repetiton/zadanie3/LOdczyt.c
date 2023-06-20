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
  char w[1024];
  fdes = open("FIFO",O_RDONLY | O_CREAT);
  if(fdes < 0) { 
  printf("Open error %d \n",errno); 
  exit(1); 
  }
  res = read(fdes, c, 100);
  printf("Odczytano: %s\n", c);
  
  close(fdes);
  exit(0);
} 
