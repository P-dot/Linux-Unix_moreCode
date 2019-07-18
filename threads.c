#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

//This program creates a thread that writes x lines in a text file.

void *thread_routine(void *arg)
{   
    int nr_lines = *((int*)arg);
    int fd;
    char buf[] = "New line \n";
    printf("The thread begins to execute... \n");

    for(int i = 0; i< nr_lines; i++)
    {
        fd = open("/home/usuario/Proyectos/Linux_projects/filethread.txt", O_WRONLY|O_APPEND);
        write(fd, buf, sizeof(buf)-1);
        close(fd);
    }
}

int main(int argc, char *argv[])
{   
	pthread_t thread1;
	int value = atoi(argv[1]);

	if(0 != pthread_create(&thread1, NULL, thread_routine, &value));
	  return -1;

	pthread_join(thread1, NULL);

    return 0;
}