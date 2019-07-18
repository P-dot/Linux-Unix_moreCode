#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
char *line = "testing named pipe";

int main()
{
  int fd;
  mknod("mypipe", I_SFIFO, 0);    // create a named pipe
  fd = open("mypipe", O_WRONLY); // open named pipe for write 
  write (fd, line, strlen(line));  // write to pipe
  close (fd);
}