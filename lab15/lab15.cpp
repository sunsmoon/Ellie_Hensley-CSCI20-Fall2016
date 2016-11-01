/*
Lab 15 - Menu Array.
This program uses two arrays to store a list of items and how many the user would like to purchase.

by Ellie Hensley
10/27/16
*/

#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

int main() {
    int const ITEMS = 10;   
    
    string menu[ITEMS] = {"Bananas Fosters", "Hot Dogs", "Pancakes", "Foie Gras", "Chicken Mole", "Chile Verde", "Slice of Fancy Veggie Pizza", "Glass of Lemonade", "Mug of A&W Root Beer", "Scoops of Pretzel-Crusted Vanilla Ice Cream with Caramel Sauce"};
    int check[ITEMS];

    // Print out the menu & Prompt the user to buy something.
    cout << "Today, we are serving ";
    for (int i = 0; i < ITEMS; i++) {
        
        if (i == ITEMS - 1) {
            cout << "and ";
        }
        
        cout << menu[i];
        
        if (i < ITEMS - 1) {
            cout << ", ";   // Commas after every item except the last.
        }
        else {      // End the list & Ask if the user wants anything from the menu.
            cout << "." << endl << endl << "Does anything interest you? (yes / no) ";
        }
        
        
        if (i == ITEMS / 2 + 1) {   // Put about half the items on a second line.
            cout << endl;
        }
    }
    
    string user_interested;
    cin >> user_interested;
    
    int amount_purchased = -1;
    
    if (user_interested == "yes" || user_interested == "Yes") {
        // Find out what the user wants and how many.
        for (int i = 0; i < ITEMS; i++) {
            // Keep prompting the user until the input is valid.
            while (amount_purchased < 0) {
                    
                cout << "How many " << menu[i] << " would you like? ";
                cin >> amount_purchased;
                
                    // Fixes the infinite loop caused by using a letter instead of a number. Courtesy of user Greyfade at Stackoverflow. http://stackoverflow.com/a/5655685
                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        amount_purchased = -1;
                    }
            }
            check[i] = amount_purchased;
            amount_purchased = -1;
        }
        
        // Print out the final order.
        cout << "Your order is: " << endl;
        for (int i = 0; i < ITEMS; i++) {
            cout << check[i] << " " << menu[i] << "." << endl;
        }
    }
    else {
        cout << "I'm sorry nothing interested you." << endl;
    }
}