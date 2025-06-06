#include <stdio.h>
#include <stdlib.h>


int main(int argc,char **argv){
    FILE *fp;
    fp = fopen("tmp.txt","r");
    if(fp == NULL)
    {
    //    printf("fopen error\n");
        perror("fopen()");
        exit(1);
    }
    fclose(fp);
    return 0;
}
