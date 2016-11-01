/*
Lab 16 - Menu Array #2.
This program uses parallel arrays to store the items on a menu, their prices, and how many a user wants to purchase.

by Ellie Hensley
10/27/16
*/

#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

int main() {
    int const ITEMS = 10;   
    
    string menu[ITEMS] = {"Bananas Fosters", "Hot Dogs", "Pancakes", "Foie Gras", "Chicken Mole", "Chile Verde", "Slice of Fancy Veggie Pizza", "Glass of Lemonade", "Mug of A&W Root Beer", "Scoop of Vanilla Ice Cream"};
    float menu_price[ITEMS] = {14.99, 2.49, 4.99, 149.99, 7.49, 7.49, 1.99, 1.49, 1.49, 5.99};
    int menu_inventory[ITEMS];
    int order[ITEMS];
    
    // Populate the inventory with a number between 1 and 5.
    for (int i = 0; i < ITEMS; i++) {
        menu_inventory[i] = (rand() % 5) + 1;
    }

    // Print out the menu & Prompt the user to buy something.
    cout << "Today, we are serving ";
    for (int i = 0; i < ITEMS; i++) {
        
        if (i == ITEMS - 1) {
            cout << "and ";
        }
        
        cout << menu[i] << " ($" << menu_price[i] << ")";
        
        if (i < ITEMS - 1) {
            cout << ", ";   // Commas after every item except the last.
        }
        else {      // End the list & Ask if the user wants anything from the menu.
            cout << "." << endl << endl << "Does anything interest you? (yes / no) ";
        }
        
        
        if (i == ITEMS / 2) {   // Put about half the items on a second line.
            cout << endl;
        }
    }
    
    string user_interested;
    cin >> user_interested;
    
    int amount_purchased = -1;
    
    // User wants to order something.
    if (user_interested == "yes" || user_interested == "Yes") {
        // Find out what the user wants and how many.
        for (int i = 0; i < ITEMS; i++) {
            // Keep prompting the user until the input is valid.
            while (amount_purchased < 0 || amount_purchased > menu_inventory[i]) {
                
                cout << "How many " << menu[i] << " would you like? We have " << menu_inventory[i] << " in stock. They are $" << menu_price[i] << " each.  ";
                cin >> amount_purchased;
                                
                // Fixes the infinite loop caused by using a letter instead of a number. Courtesy of user Greyfade at Stackoverflow. http://stackoverflow.com/a/5655685
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    amount_purchased = -1;
                }
            }
            order[i] = amount_purchased;
            menu_inventory[i] = menu_inventory[i] - amount_purchased;
            amount_purchased = -1;
        }
        
        float check = 0.00;
        // Print out the final order and calculate the price.
        cout << endl << "Your order is: " << endl;
        for (int i = 0; i < ITEMS; i++) {
            if (order[i] > 0) {
                cout << order[i] << " " << menu[i] << " for $" << menu_price[i] * order[i] << "." << endl;
                check = check + menu_price[i] * order[i];
            }
        }
        
        cout << endl << "Your total is $" << check;
    
    }
    else {
        cout << "I'm sorry nothing interested you." << endl;
    }
}