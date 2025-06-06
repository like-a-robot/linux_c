#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    if(argc < 3)
    {
        printf("the argument is less 3\n");
        exit(1);
    }
    FILE *fps,*fpd;
    int ch;
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
    while(1)
    {
        ch = fgetc(fps);
        if(ch == EOF)
            break;
        fputc(ch,fpd);
    }
    fclose(fpd);
    fclose(fps);
    return 0;
}
