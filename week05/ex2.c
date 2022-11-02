#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

struct Thread{
	pthread_t id;
	int i ; 
	char message[256];
};

void * thread_print(void * arg){
	struct Thread* thread = arg;
	printf("%s id of thread is : %u\n", thread->message, thread->id);
	printf(" Thread %d is exiting\n", thread->i);
}
int main(){
	int n ; 
	scanf("%d" , &n);
	
	struct Thread* threads = malloc(sizeof(struct Thread) * n);
	
	for(int i=0;i<n;i++){
		threads[i].i = i;
		sprintf(threads[i].message, "Hello from thread %d", i);
		pthread_create(&threads[i].id, NULL, &thread_print, &threads[i]);
		printf(" Thread %d is created\n", i);
		pthread_join(threads[i].id, NULL);
	}
	return 0;
}
