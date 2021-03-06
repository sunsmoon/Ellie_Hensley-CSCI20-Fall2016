/*
Lab 12: Switch Case.
This lab uses switch case to determine what animal the user identifies with.
by Ellie Hensley
10-6-16
*/

#include <iostream>
using namespace std;

int main(){
    char response_1;        // Stores the Y/N of the first question ("Do you like the outdoors?")
    char response_2;        // Stores the Y/N of "Do you like to run?" or "Do you like cheese?"
    char response_3;        // Stores the Y/N of "Do you like to swim?"
    
    cout << "Do you like the outdoors? Y/N ";
    cin >> response_1;
    
    
    switch (response_1) {
        case 'Y':                                                   // If the user likes the outdoors
        case 'y':                                                   // Ask if they like to run & store their response.
            cout << "Do you like to run? Y/N ";
            cin >> response_2;
            
            switch (response_2) {
                case 'Y':                                           // If the user likes to run
                case 'y':                                           // tell them they are a horse
                    cout << "You are a horse!";
                    break;

                default:                                            // Otherwise (if they hate running), they are a turtle.
                    cout << "You are a turtle!";
                    break;
            }
            break;
        
        default:                                                    // User hates the outdoors. Ask another question!
            cout << "Do you like cheese? Y/N ";
            cin >> response_2;
            
            if (response_2 == 'Y' || response_2 == 'y') {           // User likes cheese
                cout << "You are a mouse!";
            }
            else
                cout << "Do you like to swim? Y/N ";                // User doesn't like cheese, ask another question.
                cin >> response_3;
            
                if (response_3 == 'Y' || response_3 == 'y') {       // User likes to swim
                    cout << "You are a fish!";
                }   
                else {                                              // User doesn't like to swim.
                    cout << "You are a cat!";
                }
        }
}