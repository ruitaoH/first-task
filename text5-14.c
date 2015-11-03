/*************************************************************************
	> File Name: text5-14.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月01日 星期日 19时00分11秒
    >功能：1.-n输出前n行（默认输出正着输出全部）
    >      2.-r倒着输出全部
    >      3.-nr倒着输出倒数n行
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define TRUE 1
#define FALSE 0

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int flines,int llines);
void rwritelines(char *lineptr[],int flines,int llines);

void qsort(char *lineptr[],int left,int right);

int main(int argc,char *argv[])
{
    int c,n=0;
    int nlines;
    int isin=FALSE;
    while(--argc>0&&(*++argv)[0]=='-')
    {
        while(c=*++argv[0])
        {
            if(isdigit(c))
            {
                isin=TRUE;
                n=n*10+(c-'0');
            }
            switch(c)
            {
                case 'r':
                    if((nlines=readlines(lineptr,MAXLINES))>=0)
                    {
                        if(isin)
                            rwritelines(lineptr,nlines-n,nlines);
                        else
                            rwritelines(lineptr,0,nlines);
                        return 0;
                    }else{
                        printf("error:input too big to sort\n");
                        return 1;
                    }break;
            }
        }
    }
    
    if((nlines=readlines(lineptr,MAXLINES))>=0)
    {
        if(isin)
            writelines(lineptr,0,n);    
        else
            writelines(lineptr,0,nlines);
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
//#define MAXLINE 1000
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

void rwritelines(char *lineptr[],int flines,int llines)
{
    int i;
    for(i=llines;i>flines;i--){
        printf("%s\n",lineptr[i-1]);
    }
}

/*void qsort(char *v[],int left,int right)
{
    int i,last;
    void swap(char *v[],int i,int j);
    if(left>=right)
        return;
    swap(v,left,(left+right)/2);
    last=left;
    for(i=left+1;i<=right;i++)
        if(strcmp(v[i],v[left])<0)
            swap(v,++last,i);
    swap(v,left,last);
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}

void swap(char *v[],int i,int j)
{
    char *temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}*/
