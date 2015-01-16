/*
 <Vivek Pandya> PIC 10A Intro. to Programming
 ID: <304202955> Fall 2014
 Email: <vivek.pandya93@gmail.com> Assignment #8
 Section: <1 A>
 Honesty Pledge:
 
 I, <Vivek Pandya>, pledge that this is my own independent
 work, which conforms to the guidelines of academic honesty as
 described in the course syllabus.
 */


#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <vector>

using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class YogurtOrder {
public:
    YogurtOrder(); // default constructor
    YogurtOrder(string, string, string, string, double);
    // constructor with parameters: size, flavor1, flavor2, flavor3 and price
    string getSize();
    string getMixedFlavor();
    double getPrice();
private:
    string size;
    string flavor1, flavor2, flavor3;
    double price;
};

YogurtOrder::YogurtOrder() {
    price = 0;
}


YogurtOrder::YogurtOrder(string yogurtSize, string flavor_1, string flavor_2, string flavor_3, double currentprice){
    size = yogurtSize;
    flavor1 = flavor_1;
    flavor2 = flavor_2;
    flavor3 = flavor_3;
    price = currentprice;
}


string YogurtOrder::getSize() {
    return size;
}

string YogurtOrder:: getMixedFlavor() {
    return flavor1.substr(0,4) + "-" + flavor2.substr(0,4) + "-" + flavor3.substr(0, 4);
}

double YogurtOrder:: getPrice() {
    return price;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double getYogurtSize(string& size);
void printWelcomMessage();
void getYogurtFlavors(string& flavor1, string& flavor2, string& flavor3);
void printOrder(string, string, int);
bool addAnotherOrderQ();
void printTotalCosts(double,int, vector<YogurtOrder>&orders_storage);
char toLowerCase(char c);
void tolowerCase(string& str);


int smallcount = 0;
int mediumcount = 0;
int largecount = 0;
double const small_price = 2.19;
double const medium_price = 3.49;
double const large_price = 4.49;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    printWelcomMessage();
    
    // initialize the loop variables
    bool more_order = true;
    
    int orderNumber = 0;
    
    // Variable for cost
    double subtotal, orderprice, initial_total = 0;
    
    // Variables for size and flavors default initialized to ""
    string yogurtSize, flavor_1, flavor_2, flavor_3, mixedflavor,ordersize;
    
    vector <YogurtOrder> orders_storage;
    
    
    while (more_order)
    {
        orderNumber++;
        
        initial_total = getYogurtSize(yogurtSize);
        subtotal = subtotal + initial_total;
        
        // Update the flavors
        getYogurtFlavors(flavor_1, flavor_2, flavor_3);
        
        YogurtOrder orderflavor (yogurtSize, flavor_1, flavor_2, flavor_3,initial_total);
        
        mixedflavor = orderflavor.getMixedFlavor();
        
        ordersize = orderflavor.getSize();
        
        orderprice = orderflavor.getPrice();
        
        // Print the current order
        printOrder(ordersize, mixedflavor, orderNumber);
        
        orders_storage.push_back(orderflavor);
        
        // Determine whether or not to order more
        more_order = addAnotherOrderQ();
        
    }
    
    printTotalCosts(subtotal, orderNumber, orders_storage);
    return 0;
}

//FUNCTIONDEFINITIONS///////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 This function changes characters from lowercase to uppercase.
 @param c is the inputted character
 @return c_lower is the uppercase character
 */
char toLowerCase(char c) {
	char c_lower = c;
	if ( (c>='A') && (c<='Z')) c_lower = c + 32;
	return c_lower;
}

/**
 This function changes characters in a string from lowercase to uppercase by calling toLowerCase
 @param str is the inputted string
 */

void tolowerCase(string& str) {
	for (int k = 0; k < str.length(); k++) {
		str[k] = toLowerCase(str[k]);
	}
    return;
}

//prints welcome message
void printWelcomMessage()
{
    cout << "Welcome to My Frozen Yogurt!" << endl << endl;
}

/**
 This function gets the yogurt size and keeps track of the type of size.
 @param str is the referenced parameter for the size
 @return total is the price of one order which is added to subtotal
 */

double getYogurtSize(string& size)
{
    
    double total = 0;
    do
    {
        cout << "What size would you like? Please enter small, medium, or large: " ;
        cin >> size;
        tolowerCase(size);
        
        if (size =="small")
        {
            total = small_price;
            break;
        }
        
        if (size == "medium")
        {
            total = medium_price;
            break;
        }
        
        if (size == "large")
        {
            total = large_price;
            break;
        }
    }
    while (size!="small" || size!="medium" || size != "large");
    
    return total;
    
}

/**
 This function gets the yogurt flavors.
 @param flavor1 is the referenced parameter for 1st flavor
 @param flavor2 is the referenced parameter for 2nd flavor
 @param flavor3 is the referenced parameter for 3rd flavor
 */
void getYogurtFlavors(string& flavor_1, string& flavor_2, string& flavor_3)
{
    cout << "Enter flavor 1: " ;
    cin >> flavor_1;
    cout << "Enter flavor 2: " ;
    cin >> flavor_2;
    cout << "Enter flavor 3: " ;
    cin >> flavor_3;
    cout << endl;
    return;
}

/**
 This function prints the order.
 @param yogurtSize prints out size of the order
 @param flavor1 is refering to the 1st flavor
 @param flavor2 is refering to the 2nd flavor
 @param flavor3 is refering to the 3rd flavor
 @param orderNumber is the specific Order number.
 */

void printOrder(string ordersize, string mixedflavor,int orderNumber)
{
    for (int i = 0; i <= 35 ; i ++)
        cout << "*";
    cout << endl << "Order "<< orderNumber << ": " << mixedflavor << " " << ordersize << endl;
    for (int i = 0; i <= 35 ; i ++)
        cout << "*";
    cout << endl << endl;
    
    return;
}


/**
 This function keeps track of the bool variable responsible for continuing the while loop in main (more_order). Yes/No is standardized using tolowerCase.
 @return continuation is the result of the yes/no response of the user.
 */


bool addAnotherOrderQ()
{
    bool continuation = true;
    bool addanother = true;
    string response;
    while (addanother)
    {
        cout << "Would you like another order? Please enter yes or no: ";
        cin >> response;
        tolowerCase(response);
        if (response == "yes")
        {
            continuation = true;
            addanother = false;
        }
        else if (response == "no")
        {
            continuation = false;
            addanother = false;
        }
        else addanother = true;
    }
    return continuation;
}

/**
 This function prints the receipt for the order.
 @param subtotal prints out the subtotal calculated in the loop.
 @param orderNumber is the specific Order number.
 */

void printTotalCosts(double subtotal, int orderNumber, vector <YogurtOrder> &orders_storage)
{
    cout << fixed << setprecision(2);
    cout << endl << "================= Receipt =================" << endl << endl;
    for (int i = 0; i < orderNumber ; i ++)
    {
        cout << i+1 << "   " << orders_storage[i].getMixedFlavor() <<"   "<< orders_storage[i].getSize() << "   " << orders_storage[i].getPrice() << endl;
    }
    cout << endl;
    cout << "Number of Items = " << orderNumber << endl;
    cout << "Subtotal: " <<  setw(6) << "$" << subtotal << endl;
    cout << "Tax (8.75%):"  << setw(4) << "$" << subtotal * 0.0875<< endl;
    cout << "Total:" << setw(10) << "$" << subtotal + (subtotal * 0.0875) << endl << endl;
    cout << "============================================" << endl;
    return;
}



