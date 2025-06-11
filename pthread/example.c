#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* func(void* args)
{
    for(int i = 0;i < 50;i ++)
    {
        printf("%d\n",i);
    }
    return NULL;
}

int main()
{
    pthread_t th_1;
    pthread_t th_2;
    pthread_create(&th_1,NULL,func,NULL);
    pthread_create(&th_2,NULL,func,NULL);
    pthread_join(th_1,NULL);
    pthread_join(th_2,NULL);
    return 0;
}

