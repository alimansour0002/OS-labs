#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main(){
    int N;
    scanf("%d",&N);
    int isNNegative = 0;
    if(N<0)isNNegative=1;
    
    if(isNNegative){
        printf("N can't be negative");
        return 1;
    }
    int *array = malloc(N * sizeof(int));
    int re = 1;
    for(int i = 0; i < N; i++){
        array[i] = re-1;
        printf("%d ", array[i]);
        re++;
    }
    printf("\n");
    free(array);
    return 0;
}
