#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
char s[1024];
void startMessging(int n){
    printf("Write your message :");
    scanf("%s" , s);
    int fd = open("/tmp/ex1", O_WRONLY);
    
    for(int i=1;i<=n;i++){
        write(fd, s, sizeof(s));
    }
    close(fd);
    
    startMessging(n);
}

int main(int argc, char* argv[]){
    
    int n =  strtol(argv[1], NULL, 10);
    mkfifo("/tmp/ex1", 0666);
    startMessging(n);
    return 0;
}

