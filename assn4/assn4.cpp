/*
Assignment 4 - Grading program

This program takes a file that stores student answers and compares it to a provided key. 
If the student got the question right, they earn a point. If it's wrong, they lose 1/2 a point. If it's skipped, their score doesn't change.
If more than half the class got a question wrong, the program will note it.

by Ellie Hensley
11/14/16
*/

#include <iostream>
#include <fstream>
using namespace std;

// Class:
class Exam {
    private:
        string answers[21];
        string name;
        double score;
    public: 
        void setAnswer(int index, string answer) { answers[index] = answer; };
        void setName(string student_name) { name = student_name; };
        void setScore(double change) { score += change; };
        string getAnswer(int index) { return answers[index]; };
        string getName() { return name; };
        double getScore() { return score; };
};

int main() {
    ifstream fins;      // file input command
    ofstream fops;      // file output command
    
    Exam student[31];  // Creates an array of objects using the Exam class. 
    
    int wrong_answers[21]; // Stores how many people got a question wrong.
    int num_students = 0;   // Increases as we read thru the student-answers file.
    double class_average = 0;
    
    string file_name;   // stores the name & extension of the file we need to open.
    string temp, temp2;
    
    cout << "What is the answer key file? (ie: answers.txt) ";
    cin >> file_name;
    
    // Open the file and make sure it's open. If it can't open, prompt for the right file.
    fins.open(file_name);
    while (!fins.is_open()) {
        cout << "Could not open file " << file_name << ". What is the answer key file? ";
        cin >> file_name;
        fins.open(file_name);
    }
    
    student[0].setName("Answer Key");
    student[0].setScore(21);
    
    // Populate student[0] with the answer key.
    for (int i = 0; i < 21 && !fins.eof(); i++) {
        fins >> temp;
        student[0].setAnswer(i, temp);
    }
    
    fins.close();
    
    cout << "What is the name of the student answer file? ";
    cin >> file_name;
    
    // Open the file and make sure it's open. If it can't open, prompt for the right file.
    fins.open(file_name);
    while (!fins.is_open()) {
        cout << "Could not open file " << file_name << ". What is the answer key file? (ie: answers.txt) ";
        cin >> file_name;
        fins.open(file_name);
    }
    
    // Keep looping until we go thru 30 students (max # our array can hold) OR we reach the end of the file.
    for (int i = 1; i < 31 && !fins.eof(); i++) {
        num_students++;
        
        // Get student first and last name, then combine them and store in the object-array.
        fins >> temp >> temp2;
        temp += " " + temp2;
        student[i].setName(temp);
        
        for (int j = 0; j < 21; j++) {
            fins >> temp;
            student[i].setAnswer(j, temp);
        }
    }
    
    fins.close();
    
    for (int i = 1; i <= num_students; i++) {
        for (int j = 0; j < 21; j++) {
            // Compare the answers, so long as the student put in an anwer.
            if (student[i].getAnswer(j) != "?") {
                // If the fill-in-the-blank questions are the same/similar, increase score by 1.
                if (j >= 18 && student[i].getAnswer(j).compare(0, 3, student[0].getAnswer(j)) <= 0) {
                    student[i].setScore(1);
                }
                // Absolutely the same, increase student score by 1.
                else if (student[i].getAnswer(j) == student[0].getAnswer(j)) {
                    student[i].setScore(1);
                }
                // Otherwise it's wrong, subtract a quarter of a point.
                else {
                    student[i].setScore(-0.25);
                    wrong_answers[j]++;
                }
            }
            else {
                wrong_answers[j]++;
            }
        }
    }
    
    
    cout << "Where would you like to save the grades? ";
    cin >> file_name;
    
    char append = 0;
    
    while (append != 'Y' && append != 'N') {
        cout << "Would you like to overwrite that file or add to the end of it? (Y/N) ";
        cin >> append;
        append = toupper(append);
    }
    
    // Open the file and make sure it's open.
    if (append == 'Y') {
        fops.open(file_name, fstream::app);
    }
    else {
        fops.open(file_name);
    }
    if (!fops.is_open()) {
        cout << "Could not open file " << file_name << "." << endl;
        return 1;
    }
    
    cout << endl << "Name | Score | Answers (1-21)" << endl;
    
    // Making sure that appending to the file is on a new line and that it's clear when the new output starts.
    if (append = 'Y') {
        fops << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    fops << "Name | Score | Answers (1-21)" << endl;
    
    for (int i = 0; i <= num_students; i++) {
        // Outputting student information (name, score) to screen & file.
        cout << student[i].getName() << " " << student[i].getScore();
        fops << student[i].getName() << " " << student[i].getScore();
        class_average += student[i].getScore();
        
        for (int j = 0; j < 21; j++) {
            // Outputting student answers.
            cout << " " << student[i].getAnswer(j);
            fops << " " << student[i].getAnswer(j);
        
            // Formatting every student to be on different lines.
            if (j == 20) {
                cout << endl;
                fops << endl;
            }
        }
    }
    
    cout << endl << "Questions with > 50% incorrect or skipped:";
    fops << endl << "Questions with > 50% incorrect or skipped:";
    for (int i = 0; i < 21; i++) {
        if (wrong_answers[i] > num_students/2) {
            cout << " " << i+1; // since the array starts at 0, the actual question is 1 higher than the index.
            fops << " " << i+1;
        }
    }
    
    cout << endl << "The class average was " << class_average / num_students << ". The total was " << class_average << " over " << num_students << "." << endl;
    fops << endl << "The class average was " << class_average / num_students << ". The total was " << class_average << " over " << num_students << "." << endl;
    
    fops.close();
}