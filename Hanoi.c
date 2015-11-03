/*************************************************************************
	> File Name: Hanoi.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月03日 星期二 21时24分34秒
 ************************************************************************/

#include<stdio.h>

void Hanoi(char a,char c,char b,int n);//把n个盘子借助b座从a座移到c座

int main(void)
{
    int n;
    printf("Please input number of dishes\n");
    scanf("%d",&n);
    Hanoi('A','C','B',n);
    return 0;
}

void  Hanoi(char a,char c,char b,int n)
{
    if(n==1)
        printf("%c-->%c\n",a,c);
    else{
        Hanoi(a,b,c,n-1);
        printf("%c-->%c\n",a,c);
        Hanoi(b,c,a,n-1);
    }
}

