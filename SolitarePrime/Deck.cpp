// Alma Alvarado
// Class (CECS 282-01)
// Prog 1 – Solitare Prime
// September 14, 2020 @ 9pm

#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Deck::Deck(){
    char suits[] = {'H', 'D', 'S', 'C'}; 
    //Hearts, Dimonds, Spades, Clubs
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    //T = 10 because if we put "10 it gives us an error because it is a char not a string"
    
    topIndex = 0;

    int temp = 0;
        
    //we have to create the cards - taken from lab assigment
    for (int suitsl = 0; suitsl < 4; suitsl++){
      //there are 4 suits to chose from
        for (int ranksl = 0; ranksl < 13; ranksl++){
          //there are 13 different cards to chose from
            storage[temp++].setCard(ranks[ranksl], suits[suitsl]);
        }
    }
};


//shows deck of cards
void Deck::showDeck(){
    
    int cardShow = 0;
    cout << "The deck of cards : " << "";

    while (cardShow < 52) {

        storage[cardShow++].showCard();

        cout << " " << "";
        
        if(cardShow % 13 == 0){
            cout << " " << "";
        }
    }
};





void Deck::refreshDeck(){
    char suits[] = {'H', 'D', 'S', 'C'}; 
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
   
    topIndex = 0;
    int temp = 0;
        
    for (int suitsl = 0; suitsl < 4; suitsl++){
        for (int ranksl = 0; ranksl < 13; ranksl++){
            storage[temp++].setCard(ranks[ranksl], suits[suitsl]);
        }
    }
}





//this will shuffle the deck of cards
void Deck::shuffle(){
    
    srand(time(0));
    
    for (int i = 0; i < 1000; i++){
        int a = rand()%52;
        int b = rand()%52;
        
        //takes care of the swapping
        Card temp = storage[a];
        storage[a] = storage[b];
        storage[b] = temp;
    }
}


//deal a card from the top
Card Deck::deal(){
    return storage[topIndex++];
}

//returns the number of cards left in the deck
int Deck::cardsLeft(){
    int cardsLeft = 52 - topIndex;
    return cardsLeft;
}



