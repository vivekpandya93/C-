/*<Vivek Pandya> PIC 10A Intro. to Programming
ID: <304202955> Fall 2013 
Email: <vivek.pandya93@gmail.com> Assignment #6 
Section: <3A> 
Honesty Pledge:  
 I, <Vivek Pandya>, pledge that this is my own independent 
work, which conforms to the guidelines of academic honesty as 
described in the course syllabus.*/



#include <iostream>
#include <string> 

using namespace std;
//Declarations
string roman_digit (int digit, string one, string five, string ten);
string roman_numeral (int num);
int arabic_value (string roman_symbol);
int arabic_numeral (string roman_numeral);
//Main Function
int main()
{
	string roman_symbol;
	int arabic_number;
	do {
		cout << "Please enter an arabic number" << endl; 
		cin >> arabic_number; 
		string print1 = roman_numeral(arabic_number); 
		cout << endl << print1 << endl << endl;
	} 
	while (arabic_number <= 4000 && arabic_number >= 0 );

	do {

		cout << "Please enter a roman numeral"<<endl;;
		cin >> roman_symbol;
		int print= arabic_numeral(roman_symbol);
        cout << endl<< print << endl << endl;
	}

	while (roman_symbol!= "quit"); //sentinal value =  quit 
	system ("pause");
return 0; 
}

// Definitions

string roman_digit (int digit, string one, string five, string ten)
{
    string roman_numeral;
    switch (digit)
    
    {
        case 0: break;
        case 1: roman_numeral = one; break;
        case 2: roman_numeral = one + one; break;
        case 3: roman_numeral = one + one + one; break;
        case 4: roman_numeral = one + five; break;
        case 5: roman_numeral = five; break;
        case 6: roman_numeral = five + one; break;
        case 7: roman_numeral = five + one + one; break;
        case 8: roman_numeral = five + one + one + one; break;
        case 9: roman_numeral = one + ten; break;
    }
    return roman_numeral; //works as a reference for roman_numeral, it is called everytime roman_numeral is used. 
    
}

string roman_numeral (int num)
{
  	int thousand_digits = num/1000;

    if (num >= 4000 || num <= 0 )
        return "Not representable as a roman numeral";
        string roman_ones = roman_digit (num%10, "I", "V", "X");//calculates the ones digit, similar for every other function.
        string roman_fives = roman_digit (((num % 100)/10),"X","L","C");
        string roman_hundreds = roman_digit (((num%1000)/100), "C", "D", "M");
        string roman_thousands;
            for(int i = 0; i < thousand_digits; i++) // only a finite amount 'M''s that can be pasted. (maximum 3 in the thousands place)
            roman_thousands += "M";
		return roman_thousands + roman_hundreds + roman_fives + roman_ones; //concatenation
return 0;
}

int arabic_value (string roman_symbol)
{
int arabic_number;

    if (roman_symbol == "I") arabic_number = 1;
    else if (roman_symbol == "V")arabic_number = 5;
    else if (roman_symbol == "X") arabic_number = 10;
    else if (roman_symbol == "L") arabic_number = 50;
    else if (roman_symbol == "C") arabic_number = 100;
    else if (roman_symbol == "D") arabic_number = 500;
    else if (roman_symbol == "M") arabic_number = 1000;
    else arabic_number = 0;

    return arabic_number; //reference for arabic_numeral 
}

int arabic_numeral (string roman_numeral)
{
	string sub1; //to store substrings 
	string sub2;
	int total_value = 0; 
    if (roman_numeral.length() == 0) return 0;
    else if(roman_numeral.length() == 1) //base case
	{
    total_value += arabic_value (roman_numeral);
	}



	else if (roman_numeral.length() == 2 && ((arabic_value(roman_numeral.substr(0,1))) < (arabic_value(roman_numeral.substr(1,1))))) //take 2 characters of the numeral at a time, and see if the second is bigger or smaller.
	{
		sub1 = roman_numeral.substr (0,1);
		sub2 = roman_numeral.substr(1,1); 
		total_value += (arabic_value(sub2) - arabic_value(sub1));
	}
    
    else
	{
		sub1 = roman_numeral.substr(0,1);
		sub2 = roman_numeral.substr(1,1);
		int roman_value1 = arabic_value(sub1);
		int roman_value2 = arabic_value(sub2); 
	
		if (roman_value1 < roman_value2) 
		{
			total_value += roman_value2 - roman_value1;
			total_value += arabic_numeral(roman_numeral.substr(2,roman_numeral.length()-2));
		}
		else 
		{
			total_value += roman_value1;
			total_value += arabic_numeral(roman_numeral.substr(1,roman_numeral.length() - 1));//calling arabic_numeral, always calls itself until it reaches the base case 

		}
	}
return total_value;
}



