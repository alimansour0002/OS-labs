#include <stdio.h>   
#include <stdlib.h>
int foo(int age){
  int result=age;
  return 2022-result;
}
int main()
{
    const int x = 10 ;
    int *q = &x;
    const int *const p = malloc(5*sizeof(const int)); 
    int *pointer=p;
    for(int i=0;i<5;i++)
    {
        *pointer=x;
        pointer++;
    }
    pointer=p;
    for(int i=0;i<5;i++)
    {
        int b;
        scanf("%d", &b);
        *pointer=b;
        pointer++;
    }
    pointer=p;
    for(int i=0;i<5;i++)
    {
        int b = *pointer;
        *pointer=foo(b);
        printf("%d \n",*pointer);
        pointer++;
    }
    free(p);
    return EXIT_SUCCESS;
}