/* This is a calendar calculator. The first purpose of this code is to calculate whether a year entered is a leap year or not. 
The second purpose of this code is to receive a specific date and caluclate the amount of days added to it and print out a new, correct date. */

#include <stdio.h>
#include <stdbool.h>

//Function to determine whether or not the year entered is a leap year
bool is_leap_year(int year) { 
  if(year % 4 != 0) { 
    return false; 
  } else if (year % 100 != 0) { 
    return true; 
  } else if (year % 400 != 0) {
    return false; 
  } else {
    return true; //if the year is divisible by 4 and 400, but not divisible by 100, then it is a leap year
  }
}


//Array contianing the months starting from 0. Each month has its respective days
int days_in_month[] = {0, 31, 28, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31};

//Function to add days to given date
void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
  int days_left_in_month; 

  //while there is days left to add, function will loop
  while(days_left_to_add > 0) {
    days_left_in_month = days_in_month[*mm] - *dd;

    if(*mm == 2 && is_leap_year(*yy) == true) { 
      days_left_in_month++;
    }

    if(days_left_to_add > days_left_in_month) { 
      days_left_to_add -= days_left_in_month;
      days_left_to_add--;
      *dd = 1;

      if(*mm == 12) { 
        *mm = 1;
        *yy++;
      } else {
        *mm += 1;
      }
      
    } else {
      *dd += days_left_to_add;
      days_left_to_add = 0;
    }
  } 
}


int main() {
  bool check;
  int year;
  
  //First part of code: checks whether the year is a leap year
  printf("Enter a year: ");
  scanf("%i", &year);

  check = is_leap_year(year);

  if(check == true) { 
    printf("Leap Year\n");
  } else {
    printf("Not Leap Year\n");
  }

  
  //Second part of code: calculating the days added to entered date
  int mm, dd, yy, days_left_to_add; 

  printf("Please enter a date in the format mm/dd/yy: ");
  scanf("%d/%d/%d", &mm, &dd, &yy);
  printf("Enter the number of days to add to this date: "); 
  scanf("%d", &days_left_to_add);

  add_days_to_date(&mm, &dd, &yy, days_left_to_add);
  printf("%d/%d/%d\n", mm, dd, yy);

  return 0;
}
