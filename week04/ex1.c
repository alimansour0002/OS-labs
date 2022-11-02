#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>
void print(clock_t t){
	printf("process pid is: %d  process parent: %d execution time in milliseconds is: %lf\n",(int)getpid(),(int)getppid(),(((double)clock()-t)/CLOCKS_PER_SEC*1000));
} 
int main(void)
{

    pid_t mainID=getpid();
    pid_t child1 = fork();
    
    if (getpid()!=mainID){
        print(clock());
    }
    else{
	wait(NULL);
        pid_t child2=fork();
        if(getpid()==mainID)
        {
        	wait(NULL);
        }
        print(clock());
    }
    return EXIT_SUCCESS;
}
