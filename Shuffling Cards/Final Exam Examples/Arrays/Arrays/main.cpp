//
//  main.cpp
//  Arrays
//
//  Created by Vivek Pandya on 12/7/13.
//  Copyright (c) 2013 Vivek Pandya. All rights reserved.
//
/*
 PIC10A  Introduction to Programming
 
 ArraysCountingLetters.cpp
 version: 11/22/2013
 
 This source file demonstrates how to create arrays,
 use arrays, and pass arrays to functions.
 */

#include<iostream>
using namespace std;

/**
 Returns the number of characters in the given char array text up to (but not including)
 the first null character '\0'.
 
 @param text the char array to get the number of characters from
 @param array_size the size of the char array text
 
 @return The number of characters in the given char array text up to (but not including)
 the first null character '\0'.
 */
int getLength(const char text[], const unsigned int array_size){
    if(array_size == 0) return 0;
    int size = 0;
    char letter;
    do{
        letter = text[size];
        if(letter != '\0') { size++; }
    }
    while(size < array_size && letter != '\0');
    return size;
}

/**
 Counts the occurrences of each character in the char array text which is of the given size
 and records the result of the counting in the given frequency array.
 
 Precondition: frequency is an array of size 256
 Postcondition: The number of occurences of each character in text will be added to
 the element of frequency whose index matches the character's ASCII code.
 
 */
void countEachLetter(const char text[], const unsigned int size, int frequency[])
{
	for(int i = 0; i < size; i++){
        char letter = text[i];
        // convert the character to its ASCII code
        int index = static_cast<int>(letter);
        // count another occurrence of the given char
        // by incrementing the value of element of the frequency array
        // whose index is the same as the charachter's ASCII value
        frequency[index]++;
	}
}

void printArray(const int a[], const unsigned int size){
	for(int i = 0; i < size; i++){
        cout << a[i] << " ";
	}
	cout << endl;
}

void printArray(const char a[], const unsigned int size){
	for(int i = 0; i < size && a[i] != '\0'; i++){
        cout << a[i] << " ";
	}
	cout << endl;
}

void printArray(const double a[], const unsigned int size){
	for(int i = 0; i < size; i++){
        cout << a[i] << " ";
	}
	cout << endl;
}

void printArray(const int a[], const unsigned int size, const unsigned int start, const unsigned int end){
	for(int i = start; i <= end && i < size; i++){
        cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
    
    const int ARRAY_SIZE = 100;
    const int NUM_ASCII_CODES = 256;//using constants to avoid magic numbers
    
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char sentence[] = "Supercalifragilisticexpialidocious?";//the char array where you want to see how many characters there are
    
    // get the number of characters up to the null char '\0' of each array
    int alength = getLength(alphabet, ARRAY_SIZE);
    int slength = getLength(sentence, ARRAY_SIZE);
    
    cout << "Counting occurrences of each letter in the string:  " << endl;
    cout << sentence << endl << endl;
    
    // create frequency array and initialize all elements to 0
    int frequency[NUM_ASCII_CODES] = {0};
    
    cout << "Slice of frequency array before calling countEachLetter: " << endl;
    printArray(alphabet, 26);
    printArray(frequency, NUM_ASCII_CODES, 'a', 'z');
    
    countEachLetter(sentence, slength, frequency);
    
    cout << endl << "Slice of frequency array after calling countEachLetter: " << endl;
    printArray(alphabet, 26);
    printArray(frequency,NUM_ASCII_CODES, 'a', 'z'); //freqeuncy array now stores the count of each letter, passing in by reference.
    
    cout << endl << endl;
    return 0;
    
}