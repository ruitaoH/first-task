/*************************************************************************
	> File Name: text5-16.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月03日 星期二 17时24分15秒
    > 功能：1.正常按字典顺序排序字符
            2.-n排序数字
            3.-f按字典顺序排序但是无视大小写
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlinse); 
void maopao(char *lineptr[],int nlines,int (*comp)(void *,void *));
int numcmp(const char *,const char *);
int mystrcmp(char *s,char *t);
void swap(char *v[],int i,int j); 
char change(char c);

int main(int argc,char *argv[])
{
    int c;
    int nlines=readlines(lineptr,MAXLINES);
    while(--argc>0&&(*++argv)[0]=='-')
    {
        while(c=*++argv[0])
        {
            switch(c)
            {
                case 'n':
                    if(nlines>=0)
                    {
                        maopao(lineptr,nlines,(int (*)(void *,void *))numcmp);
                        writelines(lineptr,nlines);
                        return 0;
                    }
                case 'f':
                    if(nlines>=0)
                    {
                        maopao(lineptr,nlines,(int (*)(void *,void *))mystrcmp);
                        writelines(lineptr,nlines);
                        return 0;
                    }    
            }
        }
    }

    if(nlines>=0)
    {
        maopao(lineptr,nlines,(int (*)(void *,void *))strcmp);
        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("input too big to sort\n");
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

void writelines(char *lineptr[],int nlines)
{
    int i;
    for(i=0;i<nlines;i++)
    {
        printf("%s\n",lineptr[i]);
    }
}

void swap(char *v[],int i,int j)
{
    char *temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

int numcmp(const char *s1,const char *s2)
{
    double v1,v2;

    v1=atof(s1);
    v2=atof(s2);
    return v1-v2;
}

int mystrcmp(char *s,char *t)
{
    int i;
    for(i=0;s[i]==t[i] || change(s[i])==t[i];i++)
    {
        if(s[i]=='\0')
            return 0;
    }
    return change(s[i])-t[i];
}

char change(char c)
{
    if(c>='a'&&c<='z')
        c+='A'-'a';
    if(c>='A'&&c<='Z')
        c+='a'-'A';
    return c;
}

void maopao(char *lineptr[],int nlines,int (*comp)(void *,void *))
{
    int i,j;
    for(i=0;i<nlines-1;i++)
    {
        for(j=0;j<nlines-1-i;j++)
        {
            if((*comp)(lineptr[j],lineptr[j+1])>0)
                swap(lineptr,j,j+1);
        }
    }
}

