#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
  if(year % 4 != 0) {
    return false;
  } else if (year % 100 != 0) {
    return true;
  } else if (year % 400 != 0) {
    return false;
  } else {
    return true;
  }
}


int days_in_month[] = {0, 31, 28, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31};

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
  int days_left_in_month; 

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

  printf("Enter a year between 1800 and 10000: ");
  scanf("%i", &year);

  check = is_leap_year(year);

  if(check == true) { 
    printf("Leap Year\n");
  } else {
    printf("Not Leap Year\n");
  }

  
  int mm, dd, yy, days_left_to_add; 

  printf("Please enter a date between the years 1800 and 10000 in the format mm/dd/yy: ");
  scanf("%d/%d/%d", &mm, &dd, &yy);
  printf("Enter the number of days to add to this date: "); 
  scanf("%d", &days_left_to_add);

  add_days_to_date(&mm, &dd, &yy, days_left_to_add);
  printf("%d/%d/%d\n", mm, dd, yy);

}
