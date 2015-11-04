/*************************************************************************
	> File Name: text4-14.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月01日 星期日 17时11分41秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int flines,int llines);

void qsort(char *lineptr[],int left,int right);

int main(int argc,char *argv[])
{
    int c,putlines,in;
    in=0;
    putlines=0;
    while(--argc>0&&(*++argv)[0]=='-')
    {
        in=1;
        while(c=*++argv[0])
        {
            putlines=10*putlines+(c-'0');
        }
    }
    if(in==0)
    {
        putlines=10;
    }
    int nlines;

    if((nlines=readlines(lineptr,MAXLINES))>=0)
    {
       // qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines-putlines,nlines);
        return 0;
    }else{
        printf("error:input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;
char *alloc(int n)
{
    if(allocbuf+ALLOCSIZE-allocp>=n)
    {
        allocp+=n;
        return allocp-n;
    }else{
        return 0;
    }
}
#define MAXLINE 1000
int mygetline(char s[],int lim)
{
    int c,i;;

    for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++)
        s[i]=c;
    if(c=='\n')
    {
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    return i;
}

int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAXLEN];

    nlines=0;
    while((len=mygetline(line,MAXLEN))>0)
    {
        if(nlines>=maxlines||(p=alloc(len))==NULL)
            return -1;
        else{
            line[len-1]='\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[],int flines,int llines)
{
    int i;
    for(i=flines;i<llines;i++){
        printf("%s\n",lineptr[i]);
    }
}
