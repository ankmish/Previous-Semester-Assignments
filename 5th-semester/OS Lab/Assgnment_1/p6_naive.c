#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i,j;
    for (i = 0; i <= N - M; i++) 
    {
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M) {
            printf("Pattern found at index : %d \n", i);
            break;
        }
    }
}
int main()
{
    char pat[1000];
    long lSize;
    char * txt;
    FILE * fp = fopen ( "demo.txt" , "rb" );

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );
    txt = calloc( 1, lSize+1 );
    if( 1!=fread( txt , lSize, 1 , fp) )
          fclose(fp),free(txt),fputs("entire read fails",stderr),exit(1);

    printf("\nEnter the pattern :");
    scanf("%s", pat);
    search(pat, txt);
    fclose(fp);
    free(txt);
    return 0;
}
