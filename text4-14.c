/*************************************************************************
	> File Name: text4-14.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月04日 星期三 19时24分49秒
 ************************************************************************/

#include<stdio.h>

#define swap(t,x,y) {t temp;temp = x;x = y;y = temp;}

int main(void)
{
    int x,y;
    char a,b;

    x=5;
    y=10;
    a='A';
    b='B';

    printf("x=%d y=%d\n",x,y);
    swap(int,x,y);
    printf("x=%d y=%d\n",x,y);

    printf("a=%c b=%c\n",a,b);
    swap(char,a,b);
    printf("a=%c b=%c\n",a,b);
    return 0;
}
