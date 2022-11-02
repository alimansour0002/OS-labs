#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv){

    int n=atoi(argv[1]);
    if(n<0){
    return 0;
    }
    for (int i=1;i<=n;i++){
        fork();
        sleep(5);
        system("pstree -p 9307");
    }
    printf("New process\n");
    return EXIT_SUCCESS;
} 
