#include <stdio.h>
#define ISLEAP !(year % 4) && year % 100 || !(year % 400) 

static int daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
// External char table to store small integers
// An appropriate use of chars instead ints to reduce storage

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(){

	int year = 4000, month = 13, day = 27, yearday;
	day_of_year(year, month, day);
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
	int i, leap;
	leap = ISLEAP;
	for(i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
	if(year <= 0 || year > 3000){
		printf("Invalid year");
		return;
	}
	if(yearday <= 0 || yearday > 365){
		printf("Invalid year");
		return;
	}
	char i, leap;
	leap = ISLEAP;
	printf("%d\n", leap);
	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;

}
