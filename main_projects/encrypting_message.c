// This program asks a user to enter a sentence to encrypt. 
// How it encrypts the message is by shifting the letters by a user-defined amount. 

#include <stdio.h> 
#define SIZE 80

int main() 
{
    int i = 0;
    char message[SIZE];
    char encrypt[SIZE] = {0};
    int character = 0;
    int shift = 0;

    puts("Enter the message:");

    while ( (i <= SIZE-1) && ( (character = getchar()) != '\n') ) {
        message[i++]= character;
    }

    puts("Enter the shift amount: ");
    scanf("%d", &shift);

    i = 0;
    while ( (i < SIZE-1) && (message[i] != '\n') ) {
        if ( (message[i] >= 'A') && (message[i] <= 'Z') ) {
            encrypt[i] = ( ( ( (message[i] - 'A') + shift) % 26) + 'A');
        } else if ( (message[i] >= 'a') && (message[i] <= 'z') ) {
            encrypt[i] = ( ( ( (message[i] - 'a') + shift) % 26) + 'a');
        } else {
            encrypt[i] = message[i];
        }

        i++;
    }

    encrypt[i] = '\0' ;
    puts("The encrypted message is:");
    puts(encrypt);

    return 0;
}
