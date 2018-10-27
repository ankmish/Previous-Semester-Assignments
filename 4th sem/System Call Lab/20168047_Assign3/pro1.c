/*
Author : Ankit Mishra
Creation : 24/01/2018
Problem 1 : write a program that displays the content of a file in upper case. The filename is to be supplied as command line argument.
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

int main(int v,char const *argv[])  // take the argument from command line
{
    int fd,n;
    char c;

    fd=open(argv[1],O_RDONLY,0644);

    while (read(fd,&c,1)>0)  // while file does not end
    {
        if(islower(c))    // if match found , change it to upper case
            c=toupper(c);

	printf("%c",c);
    }
    close(fd);
    return 0;
}
