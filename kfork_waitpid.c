#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>          
#include <sys/wait.h>

int main()
{char order[100];
 int pid, status;
 puts("Introduce a command, Control-d by finish");
 while (fgets(order,100,stdin))
    {order[strlen(order)-1]=0; // substitute the \n by \0
     if((pid=fork())<0)
     	 puts("error in fork");
     else if (pid==0)          // child process 
         execl("/usr/bin/sh","sh","-c",order,0);
     else                      // father process 
     	 {waitpid(pid,&status,0);
     	  printf("pid= %d\n",pid);
     	  puts("Introduce a command, Control-d by finish");
     	  printf ("$ ");
     	 }
    }
    printf("\nBye\n");
    return 0;
}