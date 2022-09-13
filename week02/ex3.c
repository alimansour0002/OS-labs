#include<stdio.h>
void convert (long long x,int source,int target)
{
    if(target>10||target<2||source>10||source<2){
        printf("cannot convert!");
        return;
    }
    long long y=x;
    long long numberInDecimal=0;
    long long counter=1;
    while(y>0)
    {
        if(y%10>=source)
        {
        printf("cannot convert!");
        return;
        }
        numberInDecimal+=counter*(y%10);
        y/=10;
        counter*=source;
    }

    counter =0;
    char ans [256];
    while(numberInDecimal>0)
    {
        ans[counter]='0'+(numberInDecimal%target);
        numberInDecimal/=target;
        counter++;
    }
    for(int i=counter-1;i>-1;i--)
    {
        printf("%c",ans[i]);
    }
}
int main()
{
    long long number;
    int target,source;
    scanf("%lli%i%i",&number,&source,&target);
    convert(number,source,target);
}