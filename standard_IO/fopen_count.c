#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int count = 0;
    while(1){
        fp = fopen("tmp.txt","r");
        if(fp == NULL)
        {
            perror("fopen()");
            break;
        }
        count ++;
    }
    printf("the maximum fopen file number =%d\n",count);
    return 0;

    // ulimit -a
}
