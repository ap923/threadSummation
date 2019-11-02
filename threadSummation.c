#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<time.h>

int main(int argc, char*argv[])
{
	int n = strtol(argv[2],NULL,10);
	int mypipefd[2];
	int ret;
	ret = pipe(mypipefd);
	if(ret == -1){
		perror("Pipe fail");
		exit(1);
	}
	pid_t pids[n];
	int i;
	for(i = 0; i < n; ++i){
	  if((pids[i] = fork()) < 0){
	    perror("fork failed");
	    abort();
	  }else if(pids[i] == 0){
		 // sleep(1);
	srand(time(NULL) ^ getpid());  
	int b;
	b = rand()% (100 - -100 +1  )-100;
	printf("%d\n",b);
	close(mypipefd[0]);
	write(mypipefd[1],&b,sizeof(b));
	exit(0);
	    }
        }

	int status;
	pid_t pid;
	int sum=0;
	
	while(n > 0 ){
		int tmp;
		close(mypipefd[1]);
		read(mypipefd[0],&tmp,sizeof(tmp));
		sum += tmp;
		pid = wait(&status);

	--n;
	}
	close(mypipefd[1]);
	printf("%d\n",sum);

	return 0;
}
