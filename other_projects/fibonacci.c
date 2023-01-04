// This program calculates and prints the first 15 fibonacci sequence.

#include <stdio.h>

int main() {
  
    int a[15];
    int i;

    a[0] = 0;
    printf("fib_num[0] = 0\n");

    a[1] = 1;
    printf("fib_num[1] = 1\n");
    
    for (i = 2; i < sizeof(a)/sizeof(a[0]); i++) {
        a[i] = a[i-1] + a[i-2];
        printf("fib_num[%d] = %d\n", i, a[i]);
    }

    return 0;
}
