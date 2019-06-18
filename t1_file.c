#include <stdio.h>

int g = 100;    // intialized global variables
int h;          // uninitialized global variable 
static int s;   // static global variable

int main(int argc, char *argc[])
{
    int a, b;            // automatic local variables 
    static int c = 3;    // static local variable
    b = 2; 
    c = mysum(a,b);        // call mysum
    printf("sum=%d\n", c);  // call printf

    return 0;
}
