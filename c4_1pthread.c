#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define  N  4
int A[N][N], sum[N];

void *func(void *arg)
{
   int j, row;
   pthread_t tid = pthread_self(); // get thread ID number
   row = (int)arg;              // get row number from arg
   printf("Tread %d [%lu] computes sum of row %d\n", row, tid, row);
   for (j=0; j<N; j++)    // compute sum of A[row]in global sum[row]
   	   sum[row] += A[row][j];
   printf("Thread %d [%lu] done: sum[%d] = %d\n", row, tid, row, sum[row]);
   pthread_exit((void*)0); // thread exit: 0=normal termination
}

int main (int argc, char *argv[])
{
   pthread_t thread[N];       // thread IDs
   int i, j, r, total = 0;
   void *status;
   printf("Main: intialize A matrix\n");
   for (i=0; i<N; i++){
   	 sum[i] = 0;
   	 for (j=0; j<N; j++){
   	   A[i][j] = i*N + j + 1;
   	   printf("%4d ", A[i][j]);
   	 }
   	 printf("\n");
   }
   printf("Main: create %d threads\n", N);
   for(i=0; i<N; i++) {
   	  pthread_create(&thread[i], NULL, func, (void *)i);
   }
   printf("Main: try to join with threads\n");
   for(i=0; i<N; i++) {
   	  pthread_join(thread[i], &status);
   	  printf("Main: joined with %d [%lu]: status=%d\n", i, thread[i], (int)status);
   }
   printf("Main: compute and print total sum: ");
   for (i=0; i<N; i++)
   	   total += sum[i];
   printf("total = %d\n", total);
   pthread_exit(NULL);
}