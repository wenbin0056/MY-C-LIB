


#include <pthread.h>
#include <iostream>

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




static pthread_mutex_t mutex;


int fun()
{
	MUTEX_LOCK(mutex);
	cout<<"fun"<<endl;	
	MUTEX_UNLOCK(mutex);	
}













int main()
{
	MUTEX_INIT_LOCK(mutex);
	
	fun();
	return 0;
}


