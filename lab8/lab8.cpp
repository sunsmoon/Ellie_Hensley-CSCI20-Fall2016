/*
Lab 8 - Return Values & Scope

by Ellie Hensley
9/20/16



*/

#include <iostream>
using namespace std;


// ToKilo Function
// Takes the input "pounds" and converts it to kilograms.
// Returns the conversion.
double ToKilo(double pounds){
    double kilograms = pounds / 2.2046226218;       // variable local to ToKilo() function.
    return kilograms;                               // output
}


// ToPounds function
// Takes the input "kilograms" and converts it to pounds.
// Returns the conversion.
double ToPounds(double kilograms){
    double pounds = kilograms * 2.2046226218;       // variable local to ToPounds() function.
    return pounds;                                  // output
}


// Main program
// Takes user input, sends it to the ToKilos() and ToPounds() functions.
// Outputs the results sent from the functions.
int main()
{
    
    double origKilo, origPounds;                    // variable local to main() function; used to store user input.
    
    // Request input for Kilograms and Pounds.
    cout << "Input a number of kilograms! ";
    cin >> origKilo;
    cout << "Input a number of pounds! ";
    cin >> origPounds;
    
    // Convert kilograms to pounds and vice-versa, then save them to a variable to be used later.
    double convertedToPounds = ToPounds(origKilo);  // variable local to main() function.
    double convertedToKilos = ToKilo(origPounds);   // variable local to main() function.
    
    // Output the results!
    cout << endl;
    cout << origKilo << " kilograms is the same as " << convertedToPounds << " pounds!" << endl;
    cout << origPounds << " pounds is the same as " << convertedToKilos << " kilograms!" << endl;
    
}