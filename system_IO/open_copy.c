#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BufSize 1024

int main(int argc,char **argv)
{
    if(argc < 3)
    {
        fprintf(stderr,"Usage...\n");
        exit(1);
    }
    int fp,fp1;
    char str[BufSize];
    int len;
    fp = open(argv[1],O_RDONLY);
    if(fp == -1)
    {
        perror("open()");
        exit(1);
    }
    fp1 = open(argv[2],O_WRONLY|O_CREAT,O_TRUNC,0600);
    if(fp1 == -1)
    {
        close(fp);
        perror("open()");
        exit(1);
    }
    while(1)
    {
        len = read(fp,str,BufSize);
        if(len < 0)
        {
            perror("read()");
            exit(1);
        }
        else if(len == 0)
            break;
        write(fp1,str,len);
    }
    close(fp1);
    close(fp);
    return 0;
}
