// Alma Alvarado
// Class (CECS 282-01)
// Prog 1 – Solitare Prime
// September 14, 2020 @ 9pm

#include "Card.h"
#include <string>
#ifndef DECK_H
#define DECK_H
using namespace std;

class Deck{
  private:
    Card storage[52];
    int topIndex;

  public:
    Deck(); //empty constructor

    void refreshDeck();
    
    int cardsLeft();

    Card deal();

    void shuffle();

    void showDeck();
};
#endif