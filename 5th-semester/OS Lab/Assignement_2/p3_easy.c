#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
int search(char * path)
{
	DIR *dir;
	struct dirent * p;

	if((dir=opendir(path))==NULL)
	{
		printf("\n Not able to open directory");
		return -1;
	}
	while((p=readdir(dir))!=NULL)
	{
		if(p->d_type == DT_DIR)
		{
			if(strcmp(p->d_name,".")==0 || strcmp(p->d_name,"..")==0)   // for such dont recur
			{
				continue;
			}

			char newpath[200]= {'\0'};
			strcat(newpath,path);
			strcat(newpath,"/");
			strcat(newpath,p->d_name);
			printf("\n Newpath is : %s ",newpath);
			search(newpath);
		}
		else
		{
			char newpath[200]= {'\0'};
			strcat(newpath,path);
			strcat(newpath,"/");
			strcat(newpath,p->d_name);
			printf("\n Newpath is : %s ",newpath);
			printf("\n Newpath is : %s ",newpath);
			unlink(newpath);
		}
	}
	closedir(dir);
	rmdir(path);

}
int main(int arrgc,char ** argv)
{
	char * dir;
	dir = argv[1];
	int p = search(dir);
}
