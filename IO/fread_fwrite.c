#include <stdio.h>
#include <stdlib.h>
#define BufSize 1024
/*  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
 *
 *  size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
 */
int main(int argc,char **argv)
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    FILE *fps,*fpd;
    char ch[BufSize];
    int n;
    fps = fopen(argv[1],"r");
    if(fps == NULL)
    {
        perror("fopen()");
        exit(1);
    }
    fpd = fopen(argv[2],"w");
    if(fpd == NULL)
    {
        fclose(fps);
        perror("fopen()");
        exit(1);
    }
    while((n = fread(ch,1,BufSize,fps)) > 0)
    {
            fwrite(ch,1,n,fpd);
    }
    fclose(fpd);
    fclose(fps);
    return 0;
}
