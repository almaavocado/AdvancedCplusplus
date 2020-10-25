// Alma Alvarado
// Class (CECS 282-01)
// Prog 1 – Solitare Prime
// September 14, 2020 @ 9pm

#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;

void choice(Deck deck);

bool isPrime(int n);

void playSolitare(Deck deck);

int main() {
  Deck deck;

  choice(deck);

  return 0;
}

bool isPrime(int n ){
  if(n <= 1){
    return false;
    //not prime

  }
  for(int i = 2; i < n; i++ ){
    if(n % i == 0){

      return false;
    }
  }

  return true;
}

void playSolitare(Deck deck){
  cout << "Playing Solitare Prime!!" << endl;

  Card yourCards [52];
  int totalCards = 52;

  int count = 0 ;
  int sum = 0 ;


  for(int i = 0; i < totalCards; i++){
    yourCards[i] = deck.deal();
    yourCards[i].showCard();
		sum = sum + yourCards[i].getValue();

		if (isPrime(sum)){
			cout << "Prime: " << sum << endl;
			count++;
      
      if (deck.cardsLeft() == 0) {
				cout << "Winner in " << count << " piles!" << "" << endl;
				return;
			}

			sum = 0;
			i = 0;
		}


		if (deck.cardsLeft() == 0) {
			cout << "\nLoser!" << "" << endl;
			return;

    }
  }
  
}

void choice(Deck deck){

  int userChoice;

  cout << "\nWelcome to Soltitare Prime!" << endl;
  cout << "1. New Deck " << endl;
  cout << "2. Display Deck" << endl;
  cout << "3. Shuffle Deck" << endl;
  cout << "4. Play Solitare Prime" << endl;
  cout << "5. EXIT" << endl;

  cin >> userChoice;

  if (userChoice == 1){
    deck.refreshDeck();
  }

  else if(userChoice == 2){
    deck.showDeck();
  }

  else if(userChoice == 3){
    deck.shuffle();
  }

  else if(userChoice == 4){
    playSolitare(deck);
    exit(0);
  }
  else if(userChoice == 5){
    exit(0);
  }
  
  else{
    cout << "Input does not exist. Please choose from menu." << endl;
  }

  choice(deck);

}
