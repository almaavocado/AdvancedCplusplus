// 
// upDate.h
// Author: Alma Alvarado
// Program #4 due date: 11/2/2020
// 

#ifndef upDate_h
#define upDate_h
#include <string>

using namespace std;

class upDate {

private:
  int *ptr; //pointer
  static int count;
  string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

public:  
  static int Greg2Julian(int month, int day, int year);

  static void Julian2Greg(int JD, int &month, int&day, int &year);
  
  upDate(); //default constructor. This will set the date to May 11, 1959 (A very important date!!!)
  upDate(int m, int d, int y); //overloaded constructor. This will set the date to the values passed in through the parameter list represented by Month, Day and Year. If any one of the parameters is out of range, the date is set to the default date.
  upDate(int jd); //– overloaded constructor – create a date using the Julian date
  ~upDate(); //destructor. Be sure to de-allocate any memory that was allocated in the constructor.
  void setDate(int m, int d, int y); //works just like the constructor 
  int getMonth(); //return the month in integer form
  int getDay(); //return the day of the month
  int getYear(); //return the year
  string getMonthName(); //return the name of the month

  //Extra necessary functions: Add the necessary class methods (functions):

  int julian(); //An integer to represent Julian date

  upDate(const upDate &d); //this is the copy constructor

  //Function to support: D1 = D2
  upDate operator=(upDate d);

  //Function to support: D1+=5
  upDate operator+=(int n);

  //Function to support: D1 -= 7;
  upDate operator-=(int n);

  //Function to support: add days
  upDate operator+(int n);

  //Function to support: D3 = 5 + D2;
  friend upDate operator+(int n, upDate d);

  //Function to support: D3 = D2 - 11;
  upDate operator-(int n);

  //Function to suporrt: ++D1;
  upDate operator++();

  //Function to support: D1++;
  upDate operator++(int n);

  //Function to support: --D1;
  upDate operator--();

  //Function to support: ++D1;
  upDate operator--(int n);

  // int x = D5 - D4;
  int operator-(upDate d);

  //A function to print the Julian integer represented by D1
  friend std :: ostream& operator<<(std :: ostream &str, const upDate &date);

  //A static method that returns the number of upDate objects that currently exist
  static int GetDateCount();

  //Comparison Operators
  bool operator==(upDate d); // EQUAL: if(D1 == D2)
   
  bool operator<(upDate d); // LESS THAN: if(D1 < D2)

  bool operator>(upDate d);// GREATER THAN: if(D1 > D2)

};

#endif 