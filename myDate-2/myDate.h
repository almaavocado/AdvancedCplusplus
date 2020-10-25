#ifndef myDate_h
#define myDate_h

#include <stdio.h>
#include <string>
using namespace std;

class myDate{
  private:
  int month;
  int day;
  int year;
  string months[12] = {"January", "February", "March",
  "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  public:
  myDate();//default constructor. This will set the date to May 11, 1959

  myDate(int M, int D, int Y); // constructor. This will set the date to the values passed in through the parameter list represented by Month, Day and Year

  void display();//display the date in the following format (May 11, 1959) Do NOT print a linefeed after the date.

  void increaseDate(int N);//increment the date by N days.

  void decreaseDate(int N);//decrement the date by N days

  int daysBetween(myDate D); //return the number of days between this date and the date D.  If date D is a future date, the return value will be a positive int.  If date D is in the past, the return value will be a negative int.

  int getMonth();//return the month in integer form

  int getDay(); // return the day of the month

  int getYear(); //return the year

  int dayOfYear(); //return the number of days since the current year began. Example Jan 1 is 1, Feb 1 is 32.
  string dayName(); //returns Monday, Tuesday, etc according to the day of the week. 

  int Greg2Julian(int month, int day, int year); // pass in the Month, Day, Year and return Julian number
  
  void Julian2Greg(int JD, int & month, int & day, int & year); // pass in the Julian Date, and get the correct Month, Day and Year through the parameter list – pass by reference

};
#endif
