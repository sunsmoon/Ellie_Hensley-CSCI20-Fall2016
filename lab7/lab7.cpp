/*
Lab 7: Functionizing a Song

Song name: My Name is Joe
Adapted from: http://www.scoutsongs.com/lyrics/mynameisjoe.html

by Ellie Hensley
9/15/16
*/

#include <iostream>
using namespace std;

// Function: song
// Purpose: Main song lyrics with variations.
// Inputs: 
//       - name : string ; name of a person
//       - body_part : string ; a body part to use
// Output: Song lyrics with the appropriate name and body part.

void song(string name, string body_part)
{
    cout << "Hey, my name is " << name << endl;
    cout << "And I work in a button factory!" << endl;
    cout << "I've got a wife and a dog and a family." << endl;
    cout << "One day, the boss came up to me and said " << endl;
    cout << "\"Hey " << name << ", are you busy?\"" << endl;
    cout << "I said no." << endl;
    cout << "He said \"Turn this button with your " << body_part << ".\"" << endl << endl;
};

int main() {
    song("Joe", "left hand");
    song("Jane", "right hand");
    song("Joe", "left foot");
    song("Jane", "right foot");
    song("Joe", "butt");
    song("Jane", "tongue");
}