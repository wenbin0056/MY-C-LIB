


#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

using namespace std;

#define MUTEX_INIT_LOCK(mutex) \
do { \
	(void)pthread_mutex_init(&mutex, NULL); \
}while(0)

#define MUTEX_LOCK(mutex) \
do { \
	(void)pthread_mutex_lock(&mutex); \
}while(0)

#define MUTEX_UNLOCK(mutex) \
do { \
	(void)pthread_mutex_unlock(&mutex); \
}while(0)

#define MUTEX_DESTROY(mutex) \
do { \
	(void)pthread_mutex_destroy(&mutex); \
}while(0)


#define PDT_CHECK_EXPR(expr) \
        do{ \
            if (!(expr)){   \
                printf(" expr[%s] false\n", #expr); \
                return -1;  \
            }   \
        }while(0)
        

static pthread_mutex_t mutex;


int fun()
{
	MUTEX_LOCK(mutex);
	cout<<"fun"<<endl;	
	MUTEX_UNLOCK(mutex);	
}






void *thread_fun1(void *parg)
{
	while(1)
	{
		cout<<"fun1"<<endl;
		fun();
		usleep(1000*1000);
	}
	
	return NULL;
}


void *thread_fun2(void *parg)
{
	while(1)
	{
		cout<<"fun2"<<endl;
		fun();
		usleep(1000*1000);
	}
	
	return NULL;
}


void *thread_fun3(void *parg)
{
	while(1)
	{
		cout<<"fun3"<<endl;
		fun();
		usleep(1000*1000);
	}
	
	return NULL;
}


int main()
{
	int ThreadId1, ThreadId2, ThreadId3, ret;
	
	MUTEX_INIT_LOCK(mutex);

	
	ret = pthread_create((pthread_t*)&ThreadId1, NULL, thread_fun1, NULL);	
	PDT_CHECK_EXPR(0 == ret);
	ret = pthread_create((pthread_t*)&ThreadId2, NULL, thread_fun2, NULL);	
	PDT_CHECK_EXPR(0 == ret);
	ret = pthread_create((pthread_t*)&ThreadId3, NULL, thread_fun3, NULL);	
	PDT_CHECK_EXPR(0 == ret);	

	while(1);
	
	ret = pthread_join(ThreadId1, NULL);
	if(ret != 0)
		perror("\n");
	ret = pthread_join(ThreadId2, NULL);
	if(ret != 0)
		perror("\n");	
	ret = pthread_join(ThreadId3, NULL);	
	if(ret != 0)
		perror("\n");	

	MUTEX_DESTROY(mutex);
	
	return 0;
}


