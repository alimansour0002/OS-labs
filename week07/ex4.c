#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
    return ((a > b) ? b : a);
}

void * _realloc(void *ptr, int size, int newSize){
    if(ptr == NULL){
        return malloc(size);
    }
    if(newSize == 0 ){
        free(ptr);
        return NULL;
    }
    char *ptr2= ptr;
    
    char * array = malloc(newSize);
    
    int mn=newSize;
    if(mn>size)mn=size;
    
    for(int i=0;i< mn ; i++){
        array[i] = ptr2[i];
    }
    free(ptr);
    return array;
}

int main(){
    printf("Enter the initial size:");
    int n1=0;
    scanf("%d",&n1);
    int *array = _realloc(NULL ,sizeof(int) * n1 , 0);
    for(int i=0;i<n1;i++){
        array[i] = 10 ;
    }
    printf("Enter the new Size:");
    int n2=0;
    scanf("%d",&n2);
    array = _realloc(array, sizeof(int)*n1, sizeof(int)* n2);
    for(int i=0;i<n2;i++){
        printf("%d ", array[i]);
    }
    	printf("\n");
    return 0;

}
