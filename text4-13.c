/*************************************************************************
	> File Name: text4-13.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月31日 星期六 20时31分34秒
 ************************************************************************/

#include<stdio.h>
#include<ctype.h>
#define MAXSIZE 100
void reverse(char s[],int size)
{
    int i;

    if(size==1)
    {
        putchar(s[0]);
    }else{
        if(isspace(s[size-1]))
            reverse(s,size-1);
        else{
            putchar(s[size-1]);
            reverse(s,size-1);
        }
    }
}
int main(void)
{
    int i,c;
    char s[MAXSIZE];
    for(i=0;i<MAXSIZE&&(c=getchar())!=EOF;i++)
        s[i]=c;
    for(;i<MAXSIZE;i++)
        s[i]=' ';
    reverse(s,MAXSIZE);
    return 0;
}

