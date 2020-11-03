// 
// upDate.cpp
// Author: Alma Alvarado
// Program #4 due date: 11/2/2020
// 

#include "upDate.h"
#include <iostream>


int upDate:: count = 0;

/*
This is the Greg2Julian function. It will pass in the Month, Day, Year and it job is to convert to a julian date.
@param int month, int day, and int year
@return this function will return Julian number as an integer
** Used Atronomical Application to find equations**
*/

int upDate:: Greg2Julian(int month, int day, int year) {
  int y = year; 
  int m = month; 
  int d = day; 
    
  int julianDate = d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 * (m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m - 14) / 12) / 100) / 4;
    
  return julianDate;
}

/*
pass in the Julian Date, and get the correct Month, Day and Year through the parameter list – pass by reference
** Used Atronomical Application to find equations**
*/

void upDate:: Julian2Greg(int JD, int &month, int &day, int &year) {
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

//An integer to represent Julian date
int upDate:: julian() {
  int jd = Greg2Julian(ptr[0], ptr[1], ptr[2]);
  return jd;
}

/* 
This is the default constructor. 
This will set the date to May 11, 1959 
(A very important date!!!)
*/
upDate:: upDate() {
  ptr = new int[3];

  ptr[0] = 5;
  ptr[1] = 11;
  ptr[2] = 1959;
    
  count++;
}

 /*
 Overloaded Constructor. This will set the date to the values passed in through the parameter list represented by Month, Day and Year. If any one of the parameters is out of range, the date is set to the default date.
 */

upDate:: upDate(int M, int D, int Y) {

  ptr = new int[3];
    
  ptr[0] = M;
  ptr[1] = D;
  ptr[2] = Y;
    
  //first we have to convert to julian and then back to greg
  int JD = Greg2Julian(M, D, Y);
  Julian2Greg(JD, M, D, Y);
    
  if(ptr[0] != M || ptr[1] != D || ptr[2] != Y) {
    ptr[0] = 5;
    ptr[1] = 11;
    ptr[2] = 1959;
  }
    
  count++;
}

/*
 overloaded constructor – create a date using the Julian date
 */
upDate:: upDate(int jd) {
  ptr = new int[3];
    
  int month, day, year;
    
  Julian2Greg(jd, month, day, year);
    
  ptr[0] = month;
  ptr[1] = day;
  ptr[2] = year;
    
  count++;
}


upDate:: upDate(const upDate &d) {
  ptr = new int[3];
  ptr[0] = d.ptr[0];
  ptr[1] = d.ptr[1];
  ptr[2] = d.ptr[2];
      
  count++;
}

/*
  deconstructor to deallocate any memory that was allocated in the constructor
*/
upDate:: ~upDate() {
  delete [] ptr;
  count--;
}

/*
  upDate function. This function will set the date to the values passed in through the parameter list represented by Month, Day and Year.
  @param: intgers M, D, and Y which represent month, date, and year
*/

void upDate:: setDate(int M, int D, int Y) {
  ptr[0] = M;
  ptr[1] = D;
  ptr[2] = Y;
    
  int julianDate = Greg2Julian(M, D,Y);
  Julian2Greg(julianDate, M, D, Y);
    
  if(ptr[0] != M || ptr[1] != D || ptr[2] != Y) {
    ptr[0] = 5;
    ptr[1] = 11;
    ptr[2] = 1959;
    }
}

/*
This function will return the month
*/
int upDate:: getMonth() {
  return ptr[0];
}

/*
This function will return the day of the month
*/
int upDate:: getDay() {
  return ptr[1];
}

/*
This function will return the year
*/
int upDate:: getYear() {
  return ptr[2];
}

/*
This function will return the name of the month as a string
*/
string upDate:: getMonthName() {
  return months[ptr[0] - 1];
}

//A method that returns the number of upDate objects that currently exist
int upDate:: GetDateCount() {
  return count;
}


upDate upDate:: operator=(upDate d) {
  ptr[0] = d.ptr[0];
  ptr[1] = d.ptr[1];
  ptr[2] = d.ptr[2];
 return (*this);
}


upDate upDate:: operator+=(int n) {
  int JD = julian() + n;

  Julian2Greg(JD, ptr[0], ptr[1], ptr[2]);

  return (*this);
}

upDate upDate::operator-=(int n) {
  int JD = julian() - n;

  Julian2Greg(JD, ptr[0], ptr[1], ptr[2]);

  return (*this);
}


upDate upDate:: operator+(int n) {

  int JD = julian() + n;
    
  int month,day,year;
    
  Julian2Greg(JD, month, day, year);
    
  upDate temp(month, day, year);
  return temp;
}

upDate operator+(int n, upDate d) {
  
  upDate temp;

  temp = d;

  int JD = d.julian() + n;

  temp.Julian2Greg(JD, temp.ptr[0], temp.ptr[1], temp.ptr[2]);

  return temp;
}


upDate upDate:: operator++() {
  
  int JD = julian();

  JD++;

  Julian2Greg(JD, ptr[0], ptr[1], ptr[2]);

  return (*this);

}

upDate upDate:: operator++(int n) {
  upDate temp(*this);
  int jd = temp.julian() + n;
  Julian2Greg(jd, temp.ptr[0], temp.ptr[1], temp.ptr[2]);
  return temp;
}


upDate upDate:: operator-(int n) {
    int jd = julian() - n;;
    
    int month, day, year = 0;
  
    Julian2Greg(jd, month, day, year);
    
    upDate d(month, day, year);
    return d ;
}


upDate upDate:: operator--() {
    int jd = julian();

    jd--;

    Julian2Greg(jd, ptr[0], ptr[1], ptr[2]);

    return (*this);
}

upDate upDate:: operator--(int n) {
    upDate temp(*this);
    int jd = temp.julian() - n;
    Julian2Greg(jd, temp.ptr[0], temp.ptr[1], temp.ptr[2]);
    return temp;
}

int upDate:: operator-(upDate d) {
    int jd1 = julian();
    int jd2 = d.julian();
    
    int result = jd1 - jd2;

    return result;
}

  //---Comparison Operators-----
bool upDate:: operator==(upDate d) {
  upDate flag;

  flag = d;

  if(julian() - flag.julian() == 0 ){
    return true;
  }
  return false;
}

bool upDate:: operator<(upDate d) {
  upDate flag;

  flag = d;

  if(julian() - flag.julian() < 0){
    return true;
  }
  return false;
}

bool upDate:: operator>(upDate d) {
  upDate flag;

  flag = d;

  if(julian() - flag.julian() > 0){
    return true;
  }
  return false;
}

ostream& operator<<(ostream &str, const upDate &date) {
  str << date.ptr[0] << "/" << date.ptr[1] << "/" << date.ptr[2];
  return str;
}


