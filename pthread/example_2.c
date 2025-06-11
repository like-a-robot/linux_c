#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[100];
int s1,s2;

void* func_1(void* args)
{
    for(int i = 0;i < 50;i ++)
    {
        s1 += arr[i];
    }
    return NULL;
}
void* func_2(void* args)
{
    for(int i = 50;i < 100;i ++)
    {
        s2 += arr[i];
    }
    return NULL;
}

int main()
{
    pthread_t th_1;
    pthread_t th_2;
    for(int i = 0;i < 100;i ++)
        arr[i] = rand() % 50;
    pthread_create(&th_1,NULL,func_1,NULL);
    pthread_create(&th_2,NULL,func_2,NULL);
    pthread_join(th_1,NULL);
    pthread_join(th_2,NULL);
    printf("%d\n%d\n%d\n",s1,s2,s1 + s2);
    return 0;
}