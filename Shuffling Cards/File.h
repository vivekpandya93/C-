//
//  File.h
//  HW8
//
//  Created by Vivek Pandya on 12/6/13.
//  Copyright (c) 2013 Vivek Pandya. All rights reserved.
//

#ifndef __HW8__File__
#define __HW8__File__

#include <iostream>
#include <string> 

using namespace std;

enum Suit {HEARTS, CLUBS, SPADES, DIAMONDS};
enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING};

class Card{
    
public:
    Card(Rank r, Suit s);
    Rank getRank()const;
    Suit getSuit()const;
    string toString()const;
    
private:
    Suit suit;
    Rank rank; 
};


#endif