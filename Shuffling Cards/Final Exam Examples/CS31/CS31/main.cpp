//
//  main.cpp
//  CS31
//
//  Created by Vivek Pandya on 4/15/14.
//  Copyright (c) 2014 Vivek Pandya. All rights reserved.
//
/*
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main () {
    
    double amount_of_credit;
    double bonuscredit;
    double totalcredit;
    
    cout << "Company name:" << endl;
    string Company_name;
    cin >> Company_name;
    
    cout << "Annual Sales (in trillions): " << endl;
    double Annual_Sales;
    cin >> Annual_Sales;
    
    cout << "Industry: " << endl;
    string Industry;
    cin >> Industry;
    
    cout << "Number of Employees" << endl;
    int Number_of_employees;
    cin >> Number_of_employees;
    
    cout << "---" << endl;
    
    
    if (Industry == "")
        cout << "Please enter an industry." << endl;
    if (Company_name == "")
        cout << "Please enter a company name." << endl;
    if (Annual_Sales < 0)
        cout << "The annual sales must be nonnegative." << endl;
    if (Number_of_employees < 0)
        cout << "The number of employees must be positive." << endl;
    
    if (Annual_Sales <= 500) {
        amount_of_credit = 0.20 * Annual_Sales;
    }
    
    else if (Annual_Sales <= 900 ) {
        amount_of_credit = (0.20 * 500) + ((Annual_Sales - 500) * 0.10);
        if (Industry == "phishing" || Industry == "mud")
            amount_of_credit = (0.20 * 500) + ((Annual_Sales - 500) * 0.15);
    }
    
    else if (Annual_Sales > 900) {
        amount_of_credit = (0.20 * 500) + (400 * 0.10) + ((Annual_Sales - 900)*0.03);
        if (Industry == "phishing" || Industry == "mud")
            amount_of_credit = (0.20 * 500) + (400 * 0.15) + ((Annual_Sales - 900)*0.03);
    }
        
    if (Annual_Sales >= 700) {
        bonuscredit = Number_of_employees * 0.01;}
    else
        bonuscredit = 0;
    
    totalcredit = bonuscredit + amount_of_credit;
    
    
        cout << Company_name << " can borrow up to G" << setprecision(2) << fixed << totalcredit << " trillion." << endl;
    
    
    return 0;
    
}
*/

