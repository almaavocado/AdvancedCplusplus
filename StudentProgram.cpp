#include <iostream>

#include <string.h>

#include <stdlib.h>
#include <iomanip>

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

  string toString();

};


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


string myDate :: toString(){
  return months[month - 1] + " " + to_string(day) + " " + to_string(year);
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


struct StudentArr {

	char name[20]; //cstring or null-terminated character array
	int StudentID; //unique random value int for later
	char grade; //char – Values A thru F
	myDate birthday; //(myDate – random value: range 1/1/2000 to 12/31/2005)
	string HomeTown; //string

};

void populate(StudentArr []);

//one for pointers one for without
void display(StudentArr []);
void display(StudentArr *[]);

void swap(StudentArr **, StudentArr **);

//Sorting methods
void sortName(StudentArr *[]);
void sortID(StudentArr *[]);
void sortGrade(StudentArr *[]);
void sortBirthday(StudentArr *[]);
void sortHomeTown(StudentArr *[]);

//function that displays the main menu when called in main
void displayMainMenu() {

    cout << "\n1) Display list sorted by Name" << endl;
    cout << "\n2) Display list sorted by Student ID" << endl;
    cout << "\n3) Display list sorted by Birthday" << endl;
    cout << "\n4) Display list sorted by Grade" << endl;
    cout << "\n5) Display list sorted by Hometown" << endl;
    cout << "\n6) Exit" << endl;

}

/**
  Populates the students
*/

void populate(StudentArr Studarr[]) {

  srand(time(0));
  int RandNum;

  //letter grades
  char grades[5] = {'A', 'B', 'C', 'D', 'F'};

  //hometowns I know
  string hometowns[10] = {"Culver City", "Venice", "Mar Vista", "Playa Vista", "Marina Del Rey", "Westwood", "Brentwood", "Santa Monica", "El Segundo", "Inglewood"};

  //my favorite shows + characters
  strcpy(Studarr[0].name, "Michael Scott" );
  strcpy(Studarr[1].name, "Dwight Schrute");
  strcpy(Studarr[2].name, "Jim Halpert");
  strcpy(Studarr[3].name, "Pam Beesly");
  strcpy(Studarr[4].name, "Andy Bernard");
  strcpy(Studarr[5].name, "Robin Scherbatsky");
  strcpy(Studarr[6].name, "Ted Mosby");
  strcpy(Studarr[7].name, "Marshall Eriksen");
  strcpy(Studarr[8].name, "Lily Aldrin");
  strcpy(Studarr[9].name, "Barney Stinson");


	for (int i= 0; i < 10; i++) {

    //from 1000 -  9999
		RandNum = rand() % (10000 - 1000) + 1000;

		if (i == 0) {
			Studarr[i].StudentID = RandNum;
		}

		else {
			for (int j = 0; j < i ; j++) {
				while (RandNum == Studarr[i].StudentID) {
          RandNum = rand() % (10000 - 1000) + 1000;
				}
			}
			Studarr[i].StudentID = RandNum;
		}

    //set grade
    Studarr[i].grade = grades[rand() % 5];


		//generates random date of birth from dates given
		Studarr[i].birthday = myDate(1, 1, 2000);
		myDate d2(12, 31, 2005);

		Studarr[i].birthday.increaseDate(rand() % Studarr[i].birthday.daysBetween(d2));


		//set hometown
		Studarr[i].HomeTown = hometowns[i];
	}
}

//swaps students -- saves time when doing bubble sort: More efficient programming
void swap(StudentArr **A, StudentArr **B) {
	StudentArr *temp;
	temp = *B;
	*B = *A;
	*A = temp;
}


//Sorts by name -- follows bubble sort
void sortName(StudentArr *ptrForName[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (strcmp(ptrForName[j]->name, ptrForName[j+1]->name) > 0) {
				swap(ptrForName[j],ptrForName[j+1]);
			}
		}	
	}
}

//Sorts by Student ID -- follows bubble sort
void sortID(StudentArr *ptrForID[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {

			if (ptrForID[j]->StudentID > ptrForID[j + 1]->StudentID) {
				swap(ptrForID[j], ptrForID[j + 1]);

			}
		}
	}
}

//Sorts by Grade -- follows bubble sort
void sortGrade(StudentArr *ptrForGrade[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {

			if (ptrForGrade[j]->grade > ptrForGrade[j + 1]->grade) {
				swap(ptrForGrade[j], ptrForGrade[j + 1]);

			}
		}
	}
}

//Sorts by Birthday -- follows bubble sort
//includes the myDate classes
void sortBirthday(StudentArr *ptrForBday[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
      
      int julianDate1 = ptrForBday[j]->birthday.Greg2Julian(ptrForBday[j]->birthday.getMonth(), ptrForBday[j]->birthday.getDay(), ptrForBday[j]->birthday.getYear());
      
      
      int julianDate2 = ptrForBday[j + 1]->birthday.Greg2Julian(ptrForBday[j + 1]->birthday.getMonth(), ptrForBday[i+1]->birthday.getDay(), ptrForBday[j + 1]->birthday.getYear());
      
      
      if(julianDate1 > julianDate2) {
      swap(ptrForBday[j], ptrForBday[j+1]);
      }
    }
  }
}

//Sorts by Home Town -- follows bubble sort
void sortHomeTown(StudentArr *ptfForHT[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if ((ptfForHT[j]->HomeTown).compare( ptfForHT[j + 1]->HomeTown)>0) {
        
				swap(ptfForHT[j], ptfForHT[j + 1]);
			}
		}
	}
}


//I have 2 display functions becuase I could figure out how to do the populate class with pointers, it was throwing my logic off so I just did a display for pointer and non pointer

void display(StudentArr StudentArr[]) {
	cout<< setw(20) << left << "Name"
      << setw(15) << left << "Student ID"
      << setw(10) << left << "Grade"
      << setw(30) << left << "Birthday"
      << setw(20) << left << "Home Town"<<endl;
	cout << setw(20) << left << "____" 
      << setw(15) << left << "__________" 
      << setw(10) << left << "_____" 
      << setw(30) << left << "________" 
      << setw(20) << left << "_________" 
      << endl << endl;

		for (int i = 0; i < 10; i++) {
			cout << setw(20) << left << StudentArr[i].name
				<< setw(15) << left << StudentArr[i].StudentID
				<< setw(10) << left << StudentArr[i].grade
				<< setw(30) << left << StudentArr[i].birthday.toString()
				<< setw(20) << left << StudentArr[i].HomeTown<<endl;
		}
}


void display(StudentArr *StudentArr[]) {
	cout << setw(20) << left << "Name" 
       << setw(15) << left << "Student ID" 
      << setw(10) << left << "Grade" 
      << setw(30) << left << "Birthday" 
      << setw(20) << left << "Home Town" 
      << endl;
	cout << setw(20) << left << "____" 
       << setw(15) << left << "__________" 
       << setw(10) << left << "_____"
       << setw(30) << left << "________"
       << setw(20) << left << "_________" 
       << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(20) << left << StudentArr[i]->name
			  << setw(15) << left << StudentArr[i]->StudentID
			  << setw(10) << left << StudentArr[i]->grade
			  << setw(30) << left << StudentArr[i]->birthday.toString()
			  << setw(20) << left << StudentArr[i]->HomeTown << endl;
	}
}


int main() {
	StudentArr arrStudents[10];
  
	StudentArr *Name[10];

	StudentArr *StudentID[10];

	StudentArr *Grade[10];

	StudentArr *Birthday[10];

	StudentArr *HomeTown[10];

  
	for (int i = 0; i < 10; i++) {

		Name[i] = &arrStudents[i];

		StudentID[i] = &arrStudents[i];

		Grade[i] = &arrStudents[i];

		Birthday[i] = &arrStudents[i];
    
		HomeTown[i] = &arrStudents[i];
	}

	populate(arrStudents);

  int choice = 0;
  
  while(choice != 6) {
    cout << "\n";
    displayMainMenu();
    cout << endl << "Please choose an option from the menu below (1-6): ";
    cin >> choice;
    
    if(choice == 1) {
      sortName(Name);
      display(Name);
    }
      
    else if (choice == 2) {
      sortID(StudentID);
      display(StudentID);
    }

    else if(choice == 3) {
      sortBirthday(Birthday);
      display(Birthday);
    }

    else if(choice == 4) {
      sortGrade(Grade);
      display(Grade);
    }
    
    else if(choice == 5) {
      sortHomeTown(HomeTown);
      display(HomeTown);
    }

    else if(choice == 6){
      cout << "Bye!" << endl;
      break;
    
    }
    
    else{
      cout << "Invalid Input "<< endl;
    }
  }
  return 0;
}



