/*
Lab 19 - File Input/Output

This program takes numbers stored in a matrix in an input file and outputs a file with the same matrix and the sum of each row and column.

by Ellie Hensley
11/8/16
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fins;      // file input command
    ofstream fops;      // file output command
    
    int file_input[3][4];   // Stores the input file.
    
    // Open the file and make sure it's open.
    fins.open("input.txt");
    if (!fins.is_open()) {
        cout << "Could not open file input.txt." << endl;
        return 1;
    }
    
    // Stores the sum for each row or column
    int row_sum[3] = {0};
    int col_sum[4] = {0};
    
    // Store the stuff in the file to the storage array and add them to the column and row arrays.
    while (!fins.eof()) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                fins >> file_input[i][j];
                row_sum[i] += file_input[i][j];
                col_sum[j] += file_input[i][j];
            }
        }
    }
    
    // Close the file.
    fins.close();

    // Output the array and the row/col sums to the screen.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << file_input[i][j] << " ";
            
            if (j == 3) {
                cout << row_sum[i] << endl;
            }
        }
        
    }
    
    for (int i = 0; i < 3; i++) {
        cout << col_sum[i];
        
        if (i != 3) {
            cout << " ";
        }
    }
    
    // Open the output file.
    fops.open("output.txt");
    
    // Formats what we're putting in the file.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            fops << file_input[i][j] << " ";
            
            if (j == 3) {
                fops << row_sum[i] << endl;
            }
        }
        
    }
    
    for (int i = 0; i < 3; i++) {
        fops << col_sum[i];
        
        if (i != 3) {
            fops << " ";
        }
    }

    // close the output file.
    fops.close();
}