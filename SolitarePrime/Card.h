// Alma Alvarado
// Class (CECS 282-01)
// Prog 1 – Solitare Prime
// September 14, 2020 @ 9pm

#include <string>
#ifndef CARD_H
#define CARD_H
using namespace std;

class Card{
  private: 
    char rank;
    char suit;

    public:
    Card(); // empty constructor
    Card(char r, char s);

    void setCard(char r, char s);

    int getValue();

    void showCard();

    char getRank();

    char getSuit();
};
#endif
