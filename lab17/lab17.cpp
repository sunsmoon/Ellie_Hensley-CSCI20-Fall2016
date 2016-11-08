/*
Lab 17 - CStrings.

This program asks the user for their first and last name, then 
uses that information to create three usernames.

By Ellie Hensley
11/04/16
*/

#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char first_name[11] = "          ";
    char last_name[21] = "                    ";

    cout << "What is your first name? (Limit: 10 characters.)  ";
    cin >> first_name;
    
    // If first_name is too long, truncate it and output the change.
    if (first_name[10] != '\0') {
        first_name[10] = '\0';
        cout << "Your first name was too long. Truncated to " << first_name << endl;
    }    
    
    cout << "What is your last name? (Limit: 20 characters.)  ";
    cin >> last_name;
    
    // If the last name is too long, truncate it and output the change.
    if (last_name[20] != '\0') {
        last_name[20] = '\0';
        cout << "Your last name was too long. Truncated to " << last_name << endl;
    }
    
    // Compare first_name and last_name. If it's the same, output a warning.
    if (strlen(first_name) ==  strlen(last_name)) {
        int same_name_counter = 0;
    
        for (int i = 0; i <= strlen(last_name); i++) {
            if (first_name[i] == last_name[i] && first_name[i] != '\0') {
                same_name_counter++;
            }
            else if (first_name[i] == last_name[i] && first_name[i] == '\0') {
                same_name_counter += 8;
                i = 11;
            }
            
            if (same_name_counter > 10) {
                cout << endl << "You entered the same name twice.";
            }
        }
    }
    
    cout << endl << endl;
    
    cout << "Name: " << first_name << " " << last_name << endl << endl;
    
    cout << "Which of the three usernames would you like? " << endl;
    
    // First username (elhensley).
    cout << "1. ";
    
    for (int i = 0; i < 2; i++) {
        first_name[i] = tolower(first_name[i]);
        cout << first_name[i];
    }
    
    for (int i = 0; last_name[i] != '\0'; i++) {
        last_name[i] = tolower(last_name[i]);
        cout << last_name[i];
    }
    
    // Second username (elliehensley).
    cout << endl << "2. ";
    
    for (int i = 0; first_name[i] != '\0'; i++) {
        first_name[i] = tolower(first_name[i]);
        cout << first_name[i];
    }
    
    cout << last_name; // Last name is lower case by now!
    
    // Third username (ehensley)
    cout << endl << "3. " << first_name[0] << last_name; // first letter of the first name & all of last name must be lower case by now!
}