/* File: 1_5_6.c
 * Author: Brendon Walter
 * Date: 2014.09.06
 *
 * Problem 1.5. "Write a function which, given two date structures, d1 and d2, 
 * returns -1 if d1 comes before d2, 0 if d1 is the same as d2, and 1 if d1 
 * comes after d2."
 *
 * Problem 1.6. "Write a function which, given two date structures, d1 and d2, 
 * returns the number of days that d2 is ahead of d1. If d2 comes before d1, 
 * return a negative value."
 */

#include <stdio.h>

typedef struct {
	int day;
	int month;
	int year;
} Date;

/* function for problem 1.5 */
int checkDates(Date d1, Date d2) {

	/* check which year is the most recent. If the years are the same, check 
	 * months. If months are the same, check days. If days are the same, it's 
	 * the same date. 
	 */

	if (d1.year < d2.year)
		return -1;
	else if (d1.year > d2.year)
		return 1;
	else {
		if (d1.month < d2.month)
			return -1;
		else if (d1.month > d2.month)
			return 1;
		else {
 			if (d1.day < d2.day)
				return -1;
			else if (d1.day > d2.day)
				return 1;
			else return 0;

			return 0;
		} 
		return 0;
	}

}

/* start functions for problem 1.6 */

int dateDifference(Date d1, Date d2) {

	if (checkDates(d1, d2) == 0)	// dates are the same
		return 0;		
	
	else {
		int yearDiff = d2.year - d1.year;
		int monthDiff = d2.month - d1.month;
		int dayDiff = d2.day - d1.day;
		printf("%d %d %d\n", yearDiff, monthDiff, dayDiff);

		// difference just between years
		int totYearDiff = 365 * yearDiff + isLeapYear(d1.year, d2.year);
		/* this works great if there are no leap years between the two years,
		 * but what if there are? What if it's an eight year difference?
		 * this should be looked at.
		 * it also doesn't take into account that leap year should not be
		 * counted in a year where the month it's starting from is after feb.
		 */

		// difference between months
		int i;
		int totMonthDiff = 0;

		for (i=d1.month;i<d2.month;i++) 
			totMonthDiff += numDays(i, d1.year);

		/* Currently this really only works when d2 comes after d1. It should
		 * give the right negative number when only the days and the years are
		 * different (though it might be off by a few days due to leap year...)
		 * but when the months are different, you start getting funny numbers.
		 */
 
		/*
		for (i=d2.month;i<d1.month;i++)
			totMonthDiff += numDays(i, d1.year);
		*/

		// difference between days
		int totDayDiff = dayDiff;

		printf("%d %d %d\n", totYearDiff, totMonthDiff, totDayDiff);
		int totDiff = totYearDiff + totMonthDiff + totDayDiff;

		return totDiff;
	}
}

int numDays(int month, int year) {
	// checks the number of days in the month

	/* 30 days has september, april, june, and november
	 * all the rest have 31
	 * except february which has 28
	 * except on leap year
	 * when it has 29 
	 * (the poem kind of falls apart at the end, doesn't it?)
	 */
	if (month == 9 || month == 4 || month == 6 || month == 11)
		return 30;
	else if (month == 2) {
		if (isLeapYear(year))	// check if leap year
			return 29;
		else return 28;
	}
	else if (month > 12 || month < 1)
		return -1; // checked for a month that doesn't exist
	else
		return 31;

}

int isLeapYear(int year1, int year2) {
	/* checks two years to see if they're leap years.
	 * if both are, return 2
	 * if one is, return 1
	 * if neither of them are, return 0
	 */

	// a year is a leap year if year % 4 and year % 400 = 0, but not year % 100

	if (year1%400 == 0) {
		if (year2%400 == 0)
			return 2;   
		return 1;
	}
	else if (year1%100 == 0) {
		if (year2%100 == 0)
			return 0;
    	return 1;
	}
  	else if (year1%4 == 0) {
		if (year2%4 == 0)
			return 2;
    	return 1;
	}
  	else
    	return 0;
}

/* end functions for problem 1.6 */

int main(void) {

	// create date #1
	Date d1;
	d1.day = 7;
	d1.month = 10;
	d1.year = 2015;
	// create date #2
	Date d2;
	d2.day = 30;
	d2.month = 10;
	d2.year = 2015;

	printf("%d\n", dateDifference(d1, d2));
}
