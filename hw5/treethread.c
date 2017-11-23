#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *thread(void *vargp);

struct args {
	long long thread_num;
	long long levels_left;
	pthread_t* tid;
};



int main(int argc, char** argv){
	pthread_t* tid = 0;
	long long levels = atoll(argv[1])-1;
	struct args argss[3];
	if(levels > 0){
		tid = malloc(sizeof(pthread_t)*(1<<levels));
		argss[1].thread_num = 1;
		argss[1].levels_left = levels-1;
		argss[1].tid = tid;
		argss[2].thread_num = 2;
		argss[2].levels_left = levels-1;
		argss[2].tid = tid;
		pthread_create(&tid[1], 0, thread, (void*) (&argss[1]));
		pthread_create(&tid[2], 0, thread, (void*) (&argss[2]));
		pthread_join(tid[1], 0);
		pthread_join(tid[2],0);
		
	}
	printf("Thread 0 done\n");
	exit(0);
}


int main2(int argc, char** argv){
	

}

void *thread(void *vargp){
	struct args* argssloc = (struct args*)vargp;
	if(argssloc->levels_left > 0) {
		long long thread_num_left = (argssloc->thread_num)*2 +1;
		pthread_t* tidChildLeft = &(argssloc->tid[thread_num_left]);
		pthread_t* tidChildRight =  &(argssloc->tid[thread_num_left+1]);		

		struct args *argssChildLeftp = malloc (sizeof(struct args));
		struct args *argssChildRightp = malloc (sizeof(struct args));
		

		struct args argssChildLeft = *argssChildLeftp;
		argssChildLeft.thread_num = thread_num_left;
		argssChildLeft.levels_left = argssloc->levels_left - 1;
		argssChildLeft.tid = argssloc->tid;
		
		struct args argssChildRight = *argssChildRightp;
		argssChildRight.thread_num = thread_num_left+1;
		argssChildRight.levels_left = argssloc->levels_left - 1;
		argssChildRight.tid = argssloc->tid;
		
		pthread_create(tidChildLeft, 0, thread, &argssChildLeft);
		pthread_join(*tidChildLeft, 0);
		free(argssChildLeftp);

		pthread_create(tidChildRight, 0, thread, &argssChildRight);
		pthread_join(*tidChildRight, 0);
		free(argssChildRightp);
	}

		printf("Thread %d done\n", argssloc->thread_num );
	
	return 0;
}