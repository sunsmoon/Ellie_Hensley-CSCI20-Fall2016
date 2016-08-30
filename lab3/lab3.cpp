// Lab 3: User Input
// This program asks the user for multiple inputs, which are used for madlibs!
// Ellie Hensley
// 8-30-16

#include <iostream>
using namespace std;

int main()
{
    string profession = "doctors";
    string noun = "bike";
    string verbing = "riding";
    string adjective = "healthy";
    string activity = "exercise";
    int num_people = 4;
    int num_people_total = 5;
    char comparator = 0;
    float num_time = 52.4;
    string time_unit = "hours";
    string adjective_er = "healthier";
    
    cout << "Give me a profession (plural/ending with an s): ";
    cin >> profession;
    cout << "Give me a noun: ";
    cin >> noun;
    cout << "Give me a verb that you do with the noun (ending with ing): ";
    cin >> verbing;
    cout << "Give me an adjective: ";
    cin >> adjective;
    cout << "Give me an activity: ";
    cin >> activity;
    cout << "Give me a whole number: ";
    cin >> num_people;
    cout << "Give me another whole number!: ";
    cin >> num_people_total;
    cout << "Give me one character for comparison (<, >, =): ";
    cin >> comparator;
    cout << "Give me a number with a decimal!: ";
    cin >> num_time;
    cout << "Give me a measure of time: ";
    cin >> time_unit;
    cout << "Give me another adjective, ending with er: ";
    cin >> adjective_er;
    
    cout << endl;
    cout << "Most " << profession << " agree that " << noun << " " << verbing << " is a/an ";
    cout << activity << ". " << num_people << " out of " << num_people_total << " " << profession << " say that " << endl;
    cout << "people that get " << comparator << " " << num_time << " " << time_unit << " of " << noun << " " << verbing;
    cout << " in per day are " << adjective_er << " than people who don\'t!";
}