#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
char s[1024];

int startMessging(){
 int file = open("/tmp/ex1",O_RDONLY);
 read(file,s,sizeof(s));
 printf("message received : %s\n ", s);
 close(file);
}

int main(){
        startMessging();
        
    return EXIT_SUCCESS;
}

