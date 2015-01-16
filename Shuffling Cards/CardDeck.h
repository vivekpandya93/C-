//
//  CardDeck.h
//  HW8
//
//  Created by Vivek Pandya on 12/6/13.
//  Copyright (c) 2013 Vivek Pandya. All rights reserved.
//



#include <iostream>
#include "File.h" 
#include <cstdlib> 
#include <ctime> 
#include <iomanip> 
#include <vector>

using namespace std;


class CardDeck
{
public:
    CardDeck(); // default constructor
   
    ~CardDeck(); // destructor
 
    
    /* Returns the Card pointer at the back of the vector
     or NULL if the deck is empty. */
    Card* getTopCard();
 
    
    /* Prints each card, one per line, using the Card's toString()
     member function.
     */
    void print()const;
  
    /* Shuffles the deck of cards by swapping two random elements of
     the deck. */
    void shuffle();
    
   
    
    
private:
    vector<Card*> deck;
    
    /* Swaps the contents of the elements of deck at the given
     indices. */
    void swapCards(int index1, int index2);
    
};

