/*************************************************************************
	> File Name: text5-16.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月03日 星期二 17时24分15秒
    > 功能：1.正常按字典顺序排序字符
            2.-f按字典顺序排序但是无视大小写
            3.-d只对字母、数字和空格进行比较
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

//输入和输出
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlinse);
//排序
int maopao(char *lineptr[],int nlines,int (*comp)(void *,void *));

int mycmp(char *,char *);
int mystrcmp(char *s,char *t);
void swap(char *v[],int i,int j); 
char change(char c);

int main(int argc,char *argv[])
{
    int c;
    int nlines=readlines(lineptr,MAXLINES);
    int result;
    if(argc>1&&strcmp(argv[1],"-d")==0)
    {
        printf("-d\n");
        if(nlines>=0)
        {
            //不加这个只输入一行且有标点时无法报错
            if(nlines==1)
            {
                if(mycmp(lineptr[0],lineptr[0])==-1)
                {
                    return 0;
                }
            }
            result=maopao(lineptr,nlines,(int (*)(void *,void *))mycmp);
            if(result==-1)
            {
                return 0;
            }else{
                writelines(lineptr,nlines);
            }
            return 0;
        }
    }
    if(argc>1&&strcmp(argv[1],"-f")==0)
    {
        printf("-f\n");
        if(nlines>=0)
        {
            maopao(lineptr,nlines,(int (*)(void *,void *))mystrcmp);
            writelines(lineptr,nlines);
            return 0;
        }
    } 
    if(argc==3||(argc==2&&(strcmp(argv[1],"-df")==0||strcmp(argv[1],"-fd")==0)))
    {
        printf("-df\n");
        int i;
        for(i=0;i<nlines;i++)
        {
            if(mycmp(lineptr[i],lineptr[i])==-1)
                return 0;
        }
        if(nlines>=0)
        {
            maopao(lineptr,nlines,(int (*)(void *,void *))mystrcmp);
            writelines(lineptr,nlines);
            return 0;
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

int maopao(char *lineptr[],int nlines,int (*comp)(void *,void *))
{
    int i,j;
    for(i=0;i<nlines-1;i++)
    {
        for(j=0;j<nlines-1-i;j++)
        {
            if((*comp)(lineptr[j],lineptr[j+1])==-1){
                return -1;
            }
            if((*comp)(lineptr[j],lineptr[j+1])>0){
                swap(lineptr,j,j+1);  
            }
        }
    }
    return 0;
}

int mycmp(char *s,char *t)
{
    int i;
    //判断是否有除空格、数字和字母之外的字符
    for(i=0;isspace(s[i])||isdigit(s[i])||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z');i++);
    if(s[i]=='\0')
    {
        for(i=0;isspace(t[i])||isdigit(t[i])||(t[i]>='a'&&t[i]<='z')||(t[i]>='A'&&t[i]<='Z');i++);
        if(t[i]=='\0')
        {
            for(i=0;s[i]==t[i];i++)
            {
                if(s[i]=='\0')
                {
                    return 0;
                }
            }
            return s[i]-t[i];
        }else{
            printf("input error\n");
            return -1;
        }
    }else{
        printf("input error\n");
        return -1;
    }
}  

