#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void computeLPS(char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0)
                len = lps[len-1];
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMP(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPS(pat, M, lps);
    int i = 0; 
    int j  = 0; 
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
 
        if (j == M)
        {
            printf("Found pattern at index %d ", i-j);
            j = lps[j-1];
            break;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
 
int main()
{
    char pat[1000] ;
	long lSize;
	char * txt;
	FILE * fp = fopen ( "demo.txt" , "rb" );

	fseek( fp , 0L , SEEK_END);
	lSize = ftell( fp );
	rewind( fp );
	txt = calloc( 1, lSize+1 );

	/* copy the file into the buffer */
	if( 1!=fread( txt , lSize, 1 , fp) )
		  fclose(fp),free(txt),fputs("entire read fails",stderr),exit(1);

    printf("\nEnter the pattern :");
    scanf("%s", pat);
    KMP(pat, txt);
    fclose(fp);
	free(txt);
    return 0;
}