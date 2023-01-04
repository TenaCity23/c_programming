//This program takes in 3 inputs, being a character, a word, and a sentence. Then, it prints out the entered message to the user. 
//With the sentence, I had to use a unique format specifier to read in the sentence and print out the input. 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char ch;
    char s[100];
    char sen[100];
    
    scanf("%c", &ch); //takes input of 'C'
    printf("%c\n", ch);
    
    scanf("%s", &s); //takes input of 'Langauge'
    printf("%s\n", s);
    
    scanf("\n%[^\n]%*c", &sen); //takes input of 'Welcome to C!!'
    printf("%s\n", sen);

    return 0;
}
