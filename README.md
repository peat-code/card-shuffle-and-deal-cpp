# card-shuffle-and-deal-cpp
A program to shuffle and deal a deck of cards consisting of class Card, class DeckOfCards and driver function in C++

### Class Card
Card class has two data members face and suit, and a display function.

### Class DeckOfCards
DeckOfCards class has vector of Cards called deck.
A currentCard representing the next card to deal.
The constructor initializes the deck.
A dealCard function that returns the next Card object from the deck.
A bool function moreCards that returns true if more cards are present.
The shuffle function iterates through the entire deck and for each card randomly selects card to swap with.

### Random number generator
The random number is generated using mt19937. 
