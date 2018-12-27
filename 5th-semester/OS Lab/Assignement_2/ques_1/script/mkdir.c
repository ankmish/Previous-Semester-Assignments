#include <sys/stat.h>
#include <sys/types.h>
#include<stdio.h>
int main(int argc,char ** argv)
{
 	int result = mkdir(argv[1], 0777);
}
