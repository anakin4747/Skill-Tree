#include <stdio.h>
#include <stdlib.h>
#define ISLEAP !(year % 4) && year % 100 || !(year % 400) 

static int nonleap_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int leap_days[] = {0, 31, 29, 61, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int *daytab[] = {nonleap_days, leap_days};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(int argc, char *argv[]){

	int year = 2000, month = atoi(argv[1]), day = atoi(argv[2]), yearday;
	printf("Day = %d\n", yearday = day_of_year(year, month, day));
	int *pmonth = &month, *pday = &day;
	month_day(year, yearday, pmonth, pday);
	printf("*pmonth = %d, *pday = %d", *pmonth, *pday);
	return 0;
}

int day_of_year(int year, int month, int day){
	if(year <= 0 || year > 3000){
		printf("Invalid year");
		return -1;
	}
	if(month <= 0 || month > 12){
		printf("Invalid month");
		return -1;
	}
	// Error checking inputs
	int i;
	int *daytab_temp = *(daytab + (ISLEAP ? 1 : 0)); 
		// Save a pointer to the int array pointed to by either 
		// *daytab or *(daytab + 1) depending on ISLEAP
	for(i = 1, daytab_temp++; i < month; i++, daytab_temp++)
		// Starting at index 1 and pointer position daytab + 1
		// While i is less than month increment i and pointer to the month
		day += *daytab_temp; // Sum up the days in the months so far
	return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday){
	if(year <= 0 || year > 3000){
		printf("Invalid year");
		return;
	}
	if(yearday <= 0 || yearday > 365){
		printf("Invalid yearday");
		return;
	}
	// Error checking inputs
	char i;
	int *daytab_temp = *(daytab + (ISLEAP ? 1 : 0));
		// Save a pointer to the int array pointed to by either 
		// *daytab or *(daytab + 1) depending on ISLEAP
	for(i = 0; yearday > *daytab_temp; i++)
		yearday -= *daytab_temp++;
		// While yearday is greater than the months of 
		// the current year, subtract those days from 
		// the total and increase daytab_temp to the next month
	*pmonth = i; 
		// Save the number of months you when through
	    // in the address of pmonth
	*pday = yearday; 
		// Save the number of remaining days you
		// had in the month in the address of pday
}
