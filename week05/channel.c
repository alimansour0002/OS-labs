#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
int fd[2];
void processParent(int x,int y){
	close(fd[x]);
        char s[1024];
        printf("please enter a message : ");
        scanf("%s", s);
        write(fd[y], &s, sizeof(char) * strlen(s));
        close(fd[1]);
}
void processChild(int x,int y){
	close(fd[x]);
        char s[1024];
        int i = 0 ;
        while( read(fd[y], &s[i++],sizeof(char)));
        close(fd[y]);
        printf("The message is : %s\n",s);
}

int main(){
    pipe(fd);
    pid_t mainID= getpid();
    fork();
    
    if(getpid() == mainID){
    	processParent(0,1);
    } else { 
        processChild(1,0);
    }
}
