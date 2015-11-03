/*************************************************************************
	> File Name: Demo.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月30日 星期五 21时50分07秒
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
#define MAXLINE 100

double factorial(int base,int n)
{
    int i;
    double result;

    result=1.0;
    if(n>0)
    {
        for(i=0;i<n;i++)
        {
            result*=base;
        }
    }else if(n<0){
        for(i=0;i>n;i--)
        {
            result/=base;
        }
    }else
        ;
    return result;
}
double atof(char s[]){
    double val,power;
    int i,sign,nsign,n;

    n=0;
    for(i=0;isspace(s[i]);i++)
        ;
    sign=(s[i]=='-')?-1:1;
    if(s[i]=='+'||s[i]=='-')
        i++;
    for(val=0.0;isdigit(s[i]);i++)
        val=10.0*val+(s[i]-'0');
    if(s[i]=='.')
        i++;
    for(power=1.0;isdigit(s[i]);i++){
        val=10.0*val+(s[i]-'0');
        power*=10.0;
    }
    if(s[i]=='e')
    {
        i++;
        nsign=(s[i]=='-')?-1:1;
        while(isdigit(s[++i]))
        {
            n=n*10+(s[i]-'0');
        }
        return sign*val/power*factorial(10,n*nsign);
    }
    return sign*val/power;
}    
int mygetline(char s[],int lim)
{
    int c,i;

    i=0;
    while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
    {
        s[i++]=c;
    }
    if(c=='\n')
    {
        s[i++]=c;
    }
    s[i]='\0';
    return i;

}
/*简单计算器程序*/
main(){
    double sum,atof(char []);
    char line[MAXLINE];

    sum = 0;
    while (mygetline(line, MAXLINE)>0)
        printf("\t%g\n",sum+=atof(line));
    return 0;
}
