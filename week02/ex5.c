#include<stdio.h>

long long tribonacci( int n){
    if(n<=0){
        return 0; 
    }
    if(n==1 || n==2){
        return 1; 
    }
    int i=3;
    long long trib0 = 0 ; 
    long long trib1 = 1 ; 
    long long trib2 = 1 ; 
    
    for(;i<=n;i++){
        long long var = trib0 + trib1 + trib2;
        trib0 = trib1;
        trib1 = trib2;
        trib2 = var;
    }
    return trib2;
}
int main(){
    printf("tribonacci(4)= %lld\ntribonacci(36)= %lld" , tribonacci(4), tribonacci(36));
    return 0;
}