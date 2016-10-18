#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    // intitializing variables
    string name;
    string filing_status;
    float wages;
    float taxes_withheld;
    float adjusted_gross_income;
    float taxes_expected = 0;
    
    // Input for name, filing status, income, and taxes withheld.
    cout << "What is your name? ";
    getline(cin, name);
    
    cout << "Are you filing single or married? ";
    cin >> filing_status;
        
    cout << "How much money did you (and your spouse, if filing together) earn this last tax year? $";
    cin >> wages;
    
    cout << "How much have you paid out in taxes? $";
    cin >> taxes_withheld;
        
    // determining adjusted gross income and amount in taxes owed based off of filing status.
    if (filing_status == "married") {
        adjusted_gross_income = wages - 20000;
        
        if (adjusted_gross_income < 0) {
            taxes_expected = 0; 
        }
        else if (adjusted_gross_income >= 0 && adjusted_gross_income <= 17850) {
            taxes_expected = adjusted_gross_income * 0.1;
        }
        else if (adjusted_gross_income > 17850 && adjusted_gross_income <= 72500) {
            taxes_expected = 1785 + (adjusted_gross_income - 17850) * 0.15;
        }
        else {
            taxes_expected = 9982.50 + (adjusted_gross_income - 72500) * 0.28;
        }
    }
    
    else if (filing_status == "single") {
        adjusted_gross_income = wages - 10000;
        
        if (adjusted_gross_income < 0) {
            taxes_expected = 0;
        }
        else if (adjusted_gross_income >= 0 && adjusted_gross_income <= 8925) {
            taxes_expected = adjusted_gross_income * 0.1;
        }
        else if (adjusted_gross_income > 8925 && adjusted_gross_income <= 36250) {
            taxes_expected = 892.50 + (adjusted_gross_income - 8925) * 0.15;
        }
        else if (adjusted_gross_income > 36250 && adjusted_gross_income <= 87850) {
            taxes_expected = 4991.25 + (adjusted_gross_income - 36250) * 0.25;
        }
        else {
            taxes_expected = 17891.25 + (adjusted_gross_income - 87850) * 0.28;
        }
    }
    
        
    // output Adjusted Gross Income, owed taxes and/or refund owed.
    cout << endl;
    cout << "Adjusted Gross Income: $" << adjusted_gross_income << endl;
        
    if (taxes_expected < taxes_withheld) {
        cout << fixed << setprecision(2) << "You are entitled to a refund of $" << taxes_withheld - taxes_expected << ".";
    }
    else if (taxes_expected > taxes_withheld) {
        cout << fixed << setprecision(2) << "You owe $" << taxes_expected - taxes_withheld << ".";
    }
    else {
        cout << "You owe no taxes!";
    }
}