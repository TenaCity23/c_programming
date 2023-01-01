//If the number is either a multiple of 3 or 5 or even both, the program will print out Fizz, Buzz, and Fizzbuzz respectively.

#include <stdio.h> 

int main () { 
  for (int i = 1; i <= 100; i++) {
    int three = i % 3;
    int five = i % 5; 
    int both = i % 15;

    if (both == 0) { 
      printf("FizzBuzz\n");
    } else if (five == 0) { 
      printf("Buzz\n");
    } else if (three == 0) { 
      printf ("Fizz\n");
    } else {
      printf("%d\n", i);
    }
  }

  return 0;
}
