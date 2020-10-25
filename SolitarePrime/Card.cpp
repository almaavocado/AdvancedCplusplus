// Alma Alvarado
// Class (CECS 282-01)
// Prog 1 – Solitare Prime
// September 14, 2020 @ 9pm

#include "Card.h"
#include <iostream>
using namespace std;

//constructors for the Card class
Card::Card(){
    rank = 'R';
    suit = 'S';
}

Card::Card(char r, char s){
    rank = r;
    suit = s;
}

//in java we would do this.rank = rank this is exactly like that

void Card::setCard(char r, char s){
    rank = r;
    suit = s;;
}

//this funciton shows the card by showing the characters for rank and suit

void Card::showCard(){
    if (rank != 'T') {
        cout << rank << suit << " ";
      }

    else{
        cout << 10 << suit << " ";
        }
    }
    
//We need to give ranks a number value 
int Card::getValue(){
    int value = 0;
        
    if (rank == 'A'){
        value = 1;
        }
        
    else if (rank == '2'){
        value = 2;
        }

    else if (rank == '3'){
        value = 3;
        }

    else if (rank == '4'){
        value = 4;
        }

    else if (rank == '5'){
        value = 5;
        }

    else if (rank == '6'){
        value = 6;
        }

    else if (rank == '7'){
        value = 7;
        }

    else if (rank == '8'){
        value = 8;
        }

    else if (rank == '9'){
        value = 9;
        }

    else if (rank == 'T'){
        value = 10;
        }

    else if (rank == 'J'){
        value = 10;
        }

    else if (rank == 'Q'){
        value = 10;
        }

    else if (rank == 'K'){
        value = 10;
        }
        
    return value;
}

//this function gets and returns the rank of cards 
char Card::getRank(){
    return rank;
}
    
//this function gets and returns the suit of cards
char Card::getSuit(){
    return suit;
}