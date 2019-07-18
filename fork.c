#include <unistd.h>
#include <stdio.h>

int main()
{
	int x = 1; 
	if (fork() == 0) {
		    // only child executes this
		    printf("Child, x = %d\n", ++x);
	} else {
		 // only parent executes this
		 printf("Parent, x = %d\n", --x);
	}
	// parent and child execute this
	printf("Exiting wiht x = %d\n", x);
	return 0;
}