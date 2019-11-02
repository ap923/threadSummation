#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
int sum =0;
void *sumFunc(){

int b;
b = rand()%(100 - -100 +1) - 100;
printf("%d\n",b);
sum += b;
}
int main(int argc, char *argv[])
{
	int n = strtol(argv[2],NULL,10);
	pthread_t threads[n];
	srand(time(NULL));
	for(int i = 0; i < n; ++i){
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&threads[i], &attr,sumFunc,NULL);
	}	

	for(int i = 0; i < n; ++i){
		pthread_join(threads[i], NULL);

	}
	printf("%d\n",sum);


}

