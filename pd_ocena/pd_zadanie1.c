#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <pthread.h> 
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define MAX 10

void* function1(void *arg) {
    char str[100];
    scanf(" %[^\n]100s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("%s\n", str);
    return NULL;
}

int main() {

    mkdir("katalog1", 0700);
    mkdir("./katalog1/katalog2", 0700);
    creat("./katalog1/plik1", 0700);

    int shmid;
    char *value;
    shmid = shmget(45281, MAX*sizeof(int), IPC_CREAT|0600);
    
    if (shmid == -1) {
        perror("Utworzono pamiec wspoldzielona");
        exit(1);
    }

    value = shmat(shmid, NULL, 0);
    if (value == NULL) {
        perror("Przylaczono segment pamieci ");
        exit(1);
    }
    char *txt;
    scanf(" %s", txt);
    strcpy(value, txt);

 pthread_t thread;
    if (pthread_create(&thread, NULL, function1, NULL)) {
        printf("błąd tworzenia wątku.");
        abort();
    }

    if (pthread_join(thread, NULL)) {
        printf("błąd kończenia wątku.");
        abort(); 
    }
  
    int shmid2;  
    char *buf;  
    shmid2 = shmget(45281, MAX*sizeof(int), IPC_CREAT|0600);  
    if (shmid2 == -1)
    {    
        perror("Utworzenie segmentu pamieci wspoldzielonej");
        exit(1); 
    }   

    buf = shmat(shmid, NULL, 0);  
    if (buf == NULL)
    {
           perror("Przylaczenie segmentu pamieci wspoldzielonej");
           exit(1); 
    } 
    FILE *file;
    file = fopen("/Users/kamilgolawski/Nauka/Programowanie/C/katalog1/plik1", "w");
    if (file == NULL) {
        printf("Blad otwierania pliku");
    }
    else {
    fprintf(file, "%s", buf);
    fclose(file);
    }
    int writePermisson = access("./katalog1/plik1", W_OK);
    int readPermisson = access("./katalog1/plik1", R_OK);
    int Permission = access("./katalog1/plik1", X_OK);
    if (writePermisson == 0) {
        printf("Proces ma dostęp do zapisu pliku \n");
        chmod("./katalog1/plik1", 0500);
    } else {
        printf("Proces nie ma dostępu do zapisu pliku \n");
        chmod("./katalog1/plik1", 0700);
    }
    int isRemoved = remove("./katalog1/plik1");
    if (isRemoved == 0) {
        printf("Plik zostal usuniety \n");
    }

    //Za pomoca remove nie da sie usunac katalogu/folderu poniewaz jest ona przeznaczona jedynie do plikow, aby usunac folder mozna uzyc funkcji rmdir
    
    return 0;
}