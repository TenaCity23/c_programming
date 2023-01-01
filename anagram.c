//This code takes two given strings and compares them (excluding whitespaces) to see if they are anagrams or not. 
//The results are printed and only the first four letters of the alphabet are counted. 

#include<stdio.h>
#include<string.h> 

int main () { 
  
  //Initialize both counters to 0
  int counter1[] = {0,0,0,0};
  int counter2[] = {0,0,0,0};

  char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
  char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";

  //Counter process for both strings 
  for (int i = 0; i < strlen(s1); i++) { 
    if(s1[i] == 'a') { 
      counter1[0]++;
    } else if (s1[i] == 'b') { 
      counter1[1]++;
    } else if (s1[i] == 'c') { 
      counter1[2]++;
    } else if (s1[i] == 'd') { 
      counter1[3]++;
    } 
  }

 for (int i = 0; i < strlen(s2); i++) { 
    if(s2[i] == 'a') { 
      counter2[0]++;
    } else if (s2[i] == 'b') { 
      counter2[1]++;
    } else if (s2[i] == 'c') { 
      counter2[2]++;
    } else if (s2[i] == 'd') { 
      counter2[3]++;
    } 
  }

  //Used as a bool
  int flag = 0; 

  //Compares the number of letters counted for each string
  for (int i = 0; i < 4; i++) { 
    if(counter1[i] != counter2[i]) { 
      flag = 1; 
      break;
    }
  }

  //If counters match, it is an Anagram
  if (flag == 1) { 
    printf("Not Anagram!");
  } else { 
    printf("Anagram!");
  }

  return 0;
}
