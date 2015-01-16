//
//  main.cpp
//  HW8
//
//  Created by Vivek Pandya on 12/6/13.
//  Copyright (c) 2013 Vivek Pandya. All rights reserved.
//

#include <iostream>
#include "CardDeck.h"
#include "File.h"
#include <ctime>


int main(){
    
    int seed = static_cast<int>(time(NULL));
    srand (seed);
    // Creates a CardDeck object using default constructor
    CardDeck d;
    
    // display the contents of the CardDeck object
    d.print();
    
    cout << "Shuffling..." << endl << endl;
    
    // shuffle the CardDeck
    d.shuffle();
    
    // display the contents of the shuffled CardDeck object
    d.print(); 
    
    return 0; 
}

