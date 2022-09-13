#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s[256];

int count(char c){
    int cnt = 0 ; 
    int i=0;
    for(;i<strlen(s);i++){
        if(s[i]==c){
            cnt++;
        }
    }
    return cnt;
}
void countall(){
    int i=0;
    for(;i<strlen(s);i++){
        printf("%c : %i\n", s[i], count(s[i]));
    }
}
int main(){
    scanf("%s", s);
    int i=0;
    for(;i<strlen(s);i++){
        s[i] = tolower(s[i]);
    }
    countall();
    return 0;
}