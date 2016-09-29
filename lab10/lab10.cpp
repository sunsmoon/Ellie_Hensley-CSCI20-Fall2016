/*
Lab 10 : Boolean & Logical Operators
by Ellie Hensley
9-29-16
*/

#include <iostream>
using namespace std;

int main() {
    
    // Worksheet #1: 
    int suzyAge = 25;
    int johnAge = 21;
    cout << "Is Suzy's age less than John's age? " << (suzyAge < johnAge) << endl;      // should output 0
    
    // #2:
    int x = 7;
    int y = 7;
    cout << "Is x greater than or the same as y? " << (x >= y) << endl;  // should output 1
    
    // #3
    int a = 1;
    int b = 9;
    cout << "Is a the same as b? " << (a == b) << endl; // should output 0
    
    // #4
    int limit = 20;
    int count = 10;
    cout << "Is half of the product of limit and count greater than zero? " << ((limit * count) / 2 > 0) << endl; // should output 1
    
    // #5
    int t = -4;
    int z = 0;
    cout << "Is t more than 5 OR is z less than 2? " << (t > 5 || z < 2) << endl; // output 1
    
    // #6
    int variable = -5;
    cout << "Is variable greater than zero? " << !(variable < 0) << endl; // output 1
    
    // #7
    a = 16; 
    cout << "Is a divided by 4 less than 8 AND is a at least 4? " << (a/4 < 8 && a >= 4) << endl; // output 1
    
    // #8
    x = -2;
    y = 5;
    cout << "Is x multiplied by y less than 10? OR is y multiplied by z less than 10? " << (x*y < 10 || y*z < 10) << endl; // outputs 1
    
    // #9
    int j = -2;
    int k = 5;
    int l = 4;
    cout << "Is j * l NOT less than 10? OR is y divided by x multiplied by 4 less than y doubled? " << (!(j*l < 10) || y/x * 4 < y *2); // outputs 1
}