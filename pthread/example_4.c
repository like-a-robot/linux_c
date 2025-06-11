#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;
int s = 0;

void* func(void* args)
{
    pthread_mutex_lock(&lock);
    for(int i = 0;i < 100;i ++)
    {
        //pthread_mutex_lock(&lock);
        s ++;
        //pthread_mutex_unlock(&lock);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main()
{
    pthread_t th1;
    pthread_t th2;
    pthread_mutex_init(&lock,NULL);

    pthread_create(&th1,NULL,func,NULL);
    pthread_create(&th2,NULL,func,NULL);

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    printf("s = %d\n",s);
    return 0;
}