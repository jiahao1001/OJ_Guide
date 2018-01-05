#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

typedef int Semaphore;
Semaphore chopstick[5] = {1, 1, 1, 1, 1};
Semaphore mutex = 1;

void P(int *S)
{
	while ((*S) <= 0);
	(*S) --;
}

void V(int *S)
{
	(*S) ++;
}

void *phi(void *arg){
	while (1) {
		long i = (long)arg;
		P(&mutex);
		P(&chopstick[i]);
		printf("%ld phi get left chopstick\n", i);
		P(&chopstick[(i+1) % 5]);
		printf("%ld phi get right chopstick\n", i);
		V(&mutex);
		printf("%ld phi is eating\n", i);
		sleep(3);
		V(&chopstick[i]);
		printf("%ld phi left left chopstick\n", i);
		V(&chopstick[(i+1) % 5]);
		printf("%ld phi left right chopstick\n", i);
		printf("%ld phi is thinking\n", i);
		sleep(rand() % 11);
	}
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	pthread_t p[5];
	int err;
	for (int i = 0; i < 5; ++i)
	{
		err = pthread_create(&p[i], NULL, phi, (void *)i);
		if (err != 0)
			printf("cannot thread: \n");
	}
	for (int i = 0; i < 5; ++i)
		pthread_join(p[i], NULL);

	return 0;
}