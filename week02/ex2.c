#include <stdio.h>

const int MX = 256;

int main(){
    char s[MX];
    fgets(s, sizeof(s), stdin);
    for(int i=0;i<strlen(s);i++)
    {if(s[i]=='.'||i==strlen(s)-1){
	for(int j=0;j< i/ 2;j++){
		char tmp = s[i - j - 1];
		s[i - j - 1] = s[j];
		s[j] = tmp;
	}
    break;
    }
    }
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')break;
        printf("%c",s[i]);
    }
	return 0;
}