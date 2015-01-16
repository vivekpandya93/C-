//
//  CardDeck.cpp
//  HW8
//
//  Created by Vivek Pandya on 12/6/13.
//  Copyright (c) 2013 Vivek Pandya. All rights reserved.
//

#include "CardDeck.h"

CardDeck::CardDeck() // default constructor
{
    deck.push_back(new Card(ACE,HEARTS));
    deck.push_back(new Card(TWO,HEARTS));
    deck.push_back(new Card(THREE,HEARTS));
    deck.push_back(new Card(FOUR,HEARTS));
    deck.push_back(new Card(FIVE,HEARTS));
    deck.push_back(new Card(SIX,HEARTS));
    deck.push_back(new Card(SEVEN,HEARTS));
    deck.push_back(new Card(EIGHT,HEARTS));
    deck.push_back(new Card(NINE,HEARTS));
    deck.push_back(new Card(TEN,HEARTS));
    deck.push_back(new Card(JACK,HEARTS));
    deck.push_back(new Card(QUEEN,HEARTS));
    deck.push_back(new Card(KING,HEARTS));

    deck.push_back(new Card(ACE,CLUBS));
    deck.push_back(new Card(TWO,CLUBS));
    deck.push_back(new Card(THREE,CLUBS));
    deck.push_back(new Card(FOUR,CLUBS));
    deck.push_back(new Card(FIVE,CLUBS));
    deck.push_back(new Card(SIX,CLUBS));
    deck.push_back(new Card(SEVEN,CLUBS));
    deck.push_back(new Card(EIGHT,CLUBS));
    deck.push_back(new Card(NINE,CLUBS));
    deck.push_back(new Card(TEN,CLUBS));
    deck.push_back(new Card(JACK,CLUBS));
    deck.push_back(new Card(QUEEN,CLUBS));
    deck.push_back(new Card(KING,CLUBS));
    
    deck.push_back(new Card(ACE,SPADES));
    deck.push_back(new Card(TWO,SPADES));
    deck.push_back(new Card(THREE,SPADES));
    deck.push_back(new Card(FOUR,SPADES));
    deck.push_back(new Card(FIVE,SPADES));
    deck.push_back(new Card(SIX,SPADES));
    deck.push_back(new Card(SEVEN,SPADES));
    deck.push_back(new Card(EIGHT,SPADES));
    deck.push_back(new Card(NINE,SPADES));
    deck.push_back(new Card(TEN,SPADES));
    deck.push_back(new Card(JACK,SPADES));
    deck.push_back(new Card(QUEEN,SPADES));
    deck.push_back(new Card(KING,SPADES));
    
    deck.push_back(new Card(ACE,DIAMONDS));
    deck.push_back(new Card(TWO,DIAMONDS));
    deck.push_back(new Card(THREE,DIAMONDS));
    deck.push_back(new Card(FOUR,DIAMONDS));
    deck.push_back(new Card(FIVE,DIAMONDS));
    deck.push_back(new Card(SIX,DIAMONDS));
    deck.push_back(new Card(SEVEN,DIAMONDS));
    deck.push_back(new Card(EIGHT,DIAMONDS));
    deck.push_back(new Card(NINE,DIAMONDS));
    deck.push_back(new Card(TEN,DIAMONDS));
    deck.push_back(new Card(JACK,DIAMONDS));
    deck.push_back(new Card(QUEEN,DIAMONDS));
    deck.push_back(new Card(KING,DIAMONDS));
    
}

CardDeck::~CardDeck() // destructor
{
    for (int i =0; i < deck.size(); i++)
        delete deck[i];
}

Card* CardDeck::getTopCard()
{
    if (deck.empty())
        return NULL;
    else
    {
        return deck.back();
    }
}


void CardDeck:: print()const
{
    for ( int i = 0; i < deck.size(); i++)
    {
        cout << deck[i]->toString() << endl;
    }
}


void CardDeck:: shuffle()

        
{
        int number1;
        int number2;
        
        for (int i = 0; i < 200; i++)
        {
            number1 = rand()%deck.size();
            number2 = rand()%deck.size();
            swapCards (number1, number2);
    }
        
}

void CardDeck::swapCards(int index1, int index2)
        {
            Card* temp = deck[index1];
            deck[index1] = deck[index2];
            deck[index2] = temp;
        }
        


        
