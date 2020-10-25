// Alma Alvarado
// Class (CECS 282-01)
// Project Name (Prog 2 – myDate)
// September 28, 2020

#include "myDate.h"
#include <iostream>
#include <string>

using namespace std;

/*
pass in the Julian Date, and get the correct Month, Day and Year through the parameter list – pass by reference
** Used Atronomical Application to find equations**
*/
void myDate:: Julian2Greg(int JD, int &month, int &day, int &year) {

    int I, J, K, L, N;

    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N-49) + I + L;
    
    year = I;
    month = J;
    day = K;
}

/*
This is the Greg2Julian function. It will pass in the Month, Day, Year and it job is to convert to a julian date.
@param int month, int day, and int year
@return this function will return Julian number as an integer
** Used Atronomical Application to find equations**
*/

int myDate:: Greg2Julian(int month, int day, int year) {
    int y = year; 
    int m = month; 
    int d = day; 
    
    int julianDate = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
    
    return julianDate;
}

/*
default constructor. This will set the date to May 11, 1959
*/
myDate:: myDate() {
    month = 5;
    day = 11;
    year = 1959;
}


/*
  This is the myDate function. This function will set the date to the values passed in through the parameter list represented by Month, Day and Year.
  @param: intgers M, D, and Y which represent month, date, and year
*/
myDate::myDate(int M, int D, int Y){
    int month1, day1, year1, julianDate;
    
    month1 = M;
    day1 = D;
    year1 = Y;
    julianDate = Greg2Julian(M, D, Y);
    Julian2Greg(julianDate, M, D, Y);

    if (M == month1 && D == day1 && Y == year1){
        month = M;
        day = D;
        year = Y;
    }

    else{
        month = 5;
        day = 11;
        year = 1959;
    }
}

/*
  This is the myDate function. It is in charge of displaying the date in the following format (May 11, 1959 aka (month day, year) ** Do NOT print a linefeed after the date. **
*/

void myDate:: display() {
    string sMonth;
    sMonth = months[month - 1];
    cout << " " << sMonth << " " << day << ", " << year << " ";
}

/**
  This is the decreaseDate function. It is in charge of incrementing the date by N days.
  @param int N 
*/
void myDate:: increaseDate(int N) {
    int increaseJD = Greg2Julian(month, day, year);
    increaseJD = increaseJD + N;
    Julian2Greg(increaseJD, month, day, year);
}

/**
  This is the decreaseDate function. It is in charge of decrementing the date by N days.
  @param int N 
*/

void myDate:: decreaseDate(int N) {
    int decreaseJD = Greg2Julian(month, day, year);
    decreaseJD = decreaseJD - N;
    Julian2Greg(decreaseJD, month, day, year);
}

/**
  This is the myDate function. The function returns the number of days between this date and the date D.  If date D is a future date, the return value will be a positive int.  If date D is in the past, the return value will be a negative int
  @param myDate D
  @return an integer
*/
int myDate::daysBetween(myDate D){
    int julianD, julian;

    julianD = Greg2Julian (D.getMonth(),D.getDay(), D.getYear());
    julian = Greg2Julian(month, day, year);
    
    return julianD - julian;
}

//returns the month in integer form
int myDate:: getMonth() {
    return month;
}

//returns the day of the month in integer form
int myDate:: getDay() {
    return day;
}
// returns the year in integer form
int myDate:: getYear() {
    return year;
}

//returns the number of days since the current year began. Example Jan 1 is 1, Feb 1 is 32.
int myDate::dayOfYear(){

    int GtoJ = Greg2Julian(month, day, year) - Greg2Julian(1, 1, year) + 1;

    return GtoJ;

}

/*
returns Monday, Tuesday, etc according to the day of the week
*/
string myDate:: dayName() {

    int julianD = Greg2Julian(month, day, year);
    int dayIs = julianD % 7;
    string Days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    return Days[dayIs];
}
