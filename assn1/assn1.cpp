/*
Assignment 1: Wage Program
Ellie Hensley
9-8-16
This program asks for user input for employee name, hours worked, and wage. 
It then computes the amount of money before and after taxes that the employee will earn.
Finally, it outputs the results (including the original inputs).

It can be modified to make the tax rate an input.
*/

#include <iostream>
using namespace std;

int main()
{
    string employee_name = "";
    float hours_worked = 0.00;
    float wage = 0.00;
    
    cout << "What is the employee's name? ";
    getline (cin, employee_name);
    cout << "How many hours has the employee worked this pay period? ";
    cin >> hours_worked;
    cout << "What is the hourly pay rate for the employee? ";
    cin >> wage;
    
    float tax_rate = 17.00;
    float after_tax_rate = 1 - (tax_rate / 100); // This sets up a variable that converts the tax percent to the percentage of money remaining after taxes.
    float gross_income = hours_worked * wage;
    float net_income = gross_income * after_tax_rate;
    
    cout << endl;
    cout << employee_name << " worked " << hours_worked << " hours at a rate of $" << wage << " per hour." << endl;
    cout << employee_name << " earned $" << gross_income << " before taxes (" << tax_rate << "%)." << endl;
    cout << "After taxes, " << employee_name << " will recieve $" << net_income << " in take-home pay.";
}