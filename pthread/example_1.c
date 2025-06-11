#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* func_1(void* args)
{
    char* name = (char*)args;
    for(int i = 0;i < 50;i ++)
    {
        printf("%s  %d\n",name,i);
    }
    return NULL;
}

int main()
{
    pthread_t th_1;
    pthread_t th_2;
    pthread_create(&th_1,NULL,func_1,"th_1");
    pthread_create(&th_2,NULL,func_1,"th_2");
    pthread_join(th_1,NULL);
    pthread_join(th_2,NULL);
    return 0;
}