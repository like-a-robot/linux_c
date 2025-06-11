#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[100];
typedef struct{
    int left,right,res;
}my_args;

void* func_1(void* args)
{
    my_args* s = (my_args*) args;
    int res = 0;
    for(int i = s->left;i < s->right;i ++)
    {
        res += arr[i];
    }
    s->res = res;
    return NULL;
}


int main()
{
    pthread_t th_1;
    pthread_t th_2;
    for(int i = 0;i < 100;i ++)
        arr[i] = rand() % 50;
    my_args s1 = {0,50,0};
    my_args s2 = {50,100,0};
    pthread_create(&th_1,NULL,func_1,&s1);
    pthread_create(&th_2,NULL,func_1,&s2);
    pthread_join(th_1,NULL);
    pthread_join(th_2,NULL);
    printf("s1 = %d\ns2 = %d\ns1+s2 = %d\n",s1.res,s2.res,s1.res + s2.res);
    pthread_join(th_1,NULL);
    return 0;
}