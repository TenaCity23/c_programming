// This program asks the user to input a number. The output will showcase any numbers that were repeated. 

#include <stdio.h> 
#define max 10

int main() {
    int digits_array[max] = {0};
    int digit, i; 
    long inputs, j;

    while (1) {
        printf("Enter a number (0 to terminate): ");
        scanf("%ld", &inputs);
        j = inputs; 

        while (j!=0) {
          digit = j % 10;
          digits_array[digit]++;
          j = j/10;
        }
      
        if (inputs == 0) {
          break;
        }
    }

    printf("Digit:     ");
    for (i = 0; i < max; i++)
      printf("%3d", i);

    printf("\nOccurences:");
    for (i = 0; i < max; i++)
      printf("%3d", digits_array[i]);

    printf("\n");
    
    return 0;
}
