/*
Author : Ankit Mishra
Creation : 24/01/2018
Problem 2 :  Write a program that reads from one file descriptor and and writes all the bytes to another file descriptor.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int s,char const *A[])    // for taking argument from command line
{
    int fd1,fd2,t;
    char ch[100];
    fd1=open(A[1],O_RDONLY,0644);         // first file descriptor
    fd2=open(A[2],O_WRONLY|O_CREAT,0644);  // second file descriptor
    t=read(fd1,ch,100)        // read until to EOF
    write(fd2,ch,t);     // write to the another file descriptor
    close(fd1);
    close(fd2);
}
