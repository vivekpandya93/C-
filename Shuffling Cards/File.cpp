//
//  File.cpp
//  HW8
//
//  Created by Vivek Pandya on 12/6/13.
//  Copyright (c) 2013 Vivek Pandya. All rights reserved.
//

#include "File.h"

Card::Card (Rank r, Suit s)
{
    rank = r;
    suit = s;
}

Suit Card:: getSuit()const
{
	return suit;
}

Rank Card:: getRank()const
{
	return rank;
}


string Card::toString()const{
    
    string description = "";
    
    switch(rank) {
        case ACE:
            description += "Ace";
            break;
        case TWO:
            description += "Two";
            break;
        case THREE:
            description += "Three";
            break;
        case FOUR:
            description += "Four";
            break;
        case FIVE:
            description += "Five";
            break;
        case SIX:
            description += "Six";
            break;
        case SEVEN:
            description += "Seven";
            break;
        case EIGHT:
            description += "Eight";
            break;
        case NINE:
            description += "Nine";
            break;
        case TEN:
            description += "Ten";
            break;
        case JACK:
            description += "Jack";
            break;
        case QUEEN:
            description += "Queen";
            break;
        case KING: 
            description += "King"; 
            break; 
    } 
    
    description += " of "; 
    
    switch(suit) { 
        case HEARTS: 
            description += "Hearts"; 
            break;
        case CLUBS:
            description += "Clubs"; 
            break; 
        case SPADES: 
            description += "Spades"; 
            break; 
        case DIAMONDS: 
            description += "Diamonds"; 
            break; 
    } 
    return description;
}

