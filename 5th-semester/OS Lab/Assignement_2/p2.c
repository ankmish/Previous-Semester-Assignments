#include<stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
int printdir(char *dir, int depth,char * se)
{
    DIR *dp;
    struct dirent *entry;
    if((dp = opendir(dir)) == NULL) 
    {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return 0;
    }
    while((entry = readdir(dp)) != NULL)
    {
        if(entry -> d_type == DT_DIR)   // ---------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        {
            if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
            {
                continue;
            }
            
            /* Recurse at a new indent level */
            char newpath[200]={'\0'};                       //------------------------>>>>>>>>>>>>>>>>>>>
            strcat(newpath,dir);
            strcat(newpath,"/"); 
            strcat(newpath,entry->d_name);
            printdir(newpath,depth+1,se);
            
        }
        else
        {
            if(strcmp(se,entry->d_name)==0)
            {
            	printf("\n Entry found in %s\n",dir); 
            }
          
        }   	
    }
    closedir(dp);
    return 0;
}

void  main(int argc,char ** argv)
{
    char * path = argv[1];
    char * se = argv[2];
    printdir(path,0,se);
}
