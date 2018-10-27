/*
Author : Ankit Mishra
Creation : 24/01/2018
Problem 3: program that reads a file in reverse order (starting from the last word) and copies the content to another file in the same order.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int x,char const *A[])   // take argument from command line
{
    int fd1,fd2,n,pos;
    char c;
    fd1=open(A[1],O_RDONLY,0644);
    fd2=open(A[2],O_WRONLY|O_CREAT,0644);
    pos=lseek(fd1,0,SEEK_END);
    while(pos--)
    {
        n=read(fd1,&c,1);
        write(fd2,&c,n);
        lseek(fd1,-2,SEEK_CUR);   
    }
    close(fd1);
    close(fd2);
}
