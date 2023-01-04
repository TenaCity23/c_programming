//Program initializes a value to n, which is then broken apart to find the sum of all the integers in the value.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n = 10564;
    
    //Code to calculate the sum of the five digits of n.
    
    int temp = 0; 
    int a; 
    
    while (n != 0) { 
        a = n % 10; //modulated to take the last value/int from number and store in variable a
        n = n / 10; //divided to get rid of the last value from n
        temp += a; //adds the numbers and stores in temp
    }
    
    printf("%d\n", temp);
    
    return 0;
}
