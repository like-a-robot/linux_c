#include <stdio.h>
#include <stdlib.h>
#define BufSize 1024

int main(int argc,char **argv)
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    FILE *fps,*fpd;
    char ch[BufSize];
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
    while(fgets(ch,BufSize,fps) != NULL)
    {
            fputs(ch,fpd);
    }
    fclose(fpd);
    fclose(fps);
    return 0;
}
