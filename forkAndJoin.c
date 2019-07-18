#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // exit
#include <sys/wait.h> // wait()
int main(int ac, char *av[])
{
	pid_t childPIDorZero = fork();
	if(childPIDorZero < 0){
	    perror("fork() error");
	    exit(-1);
	}

	if(childPIDorZero != 0){
	    printf("Iḿ the parent%d, my child is %d\n",getpid(), childPIDorZero);
	    wait(NULL);// wai for child process to join with this parent
	}else{
	    printf("I'm the child %d, my parent is %d\n", getpid(), getppid());
	    execl("/bin/echo", "echo"," Hello, World", NULL);
	}
	return 0;
}