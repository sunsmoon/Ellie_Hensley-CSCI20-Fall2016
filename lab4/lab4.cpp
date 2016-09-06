// Lab 4: Coinstar
// This program asks the user for the amount of change deposited, determines the most efficient number of coins that would make up that value
// and outputs how much money the user "earned" for it after taking a 10.9% cut.
// Ellie Hensley
// 8-30-16

#include <iostream>
using namespace std;

int main()
{
    double money_in = 0;
    
    cout << "How much money (in cents) are you depositing? ";
    cin >> money_in;
    
    int num_quarters = 0;
    int num_dimes = 0;
    int num_nickels = 0;
    int num_pennies = 0;
    int money_uncounted = money_in;
    
    // Determine the number of a specific coin in the current total, then remove that amount from the total.
    num_quarters = money_uncounted / 25;
    money_uncounted = money_uncounted % 25;
    
    num_dimes = money_uncounted / 10;
    money_uncounted = money_uncounted % 10;
    
    num_nickels = money_uncounted / 5;
    money_uncounted = money_uncounted % 5;
    
    num_pennies = money_uncounted / 1;
    money_uncounted = money_uncounted - num_pennies;
    
    double money_out = 0.0;
    double fee = 0.0;
    
    // Determine the fee and money going back to the user.
    
    fee = money_in * .109;
    money_out = money_in - fee;
    
    // Print the results to the user!
    
    cout.precision(4); // Limits the cout to 4 digits (XX.XX)
    cout << endl;
    cout << "You deposited $" << money_in / 100 << ". It broke down as follows: " << endl;
    cout << num_quarters << " quarters, " << num_dimes << " dimes, " << num_nickels << " nickels, " << num_pennies << " pennies." << endl;
    cout << endl;
    cout << "After the fee ($" << fee / 100 << "), you will get $" << money_out / 100 << " in cash." << endl;
}