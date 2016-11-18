/*
Assignment 4 - Grading program

This program takes a file that stores student answers and compares it to a provided key file. 
If the student got the question right, they earn a point. If it's wrong, they lose 1/4 a point. If it's skipped, their score doesn't change.
If more than half the class got a question wrong or skipped it, the program will note it.

Output is sent both to the screen and to a designated file, with the ability to add to the end of the file.

by Ellie Hensley
11/17/16
*/

#include <iostream>
#include <fstream>
using namespace std;

// Class:
class Exam {
    private:
        string answers[21]; // stores answers to test questions
        string name;        // name of student
        double score;       // current score of the exam.
    public: 
        void setAnswer(int index, string answer) { answers[index] = answer; };  // changes a specific answer. requires an integer for the index value and something to place in that location.
        void setName(string student_name) { name = student_name; }; // Sets the students name.
        void setScore(double change) { score += change; };  // Adjusts the score based off of the amount passed through change.
        string getAnswer(int index) { return answers[index]; }; // returns the answer at a provided index.
        string getName() { return name; };  // returns the name of the student.
        double getScore() { return score; };    // returns the students exam score.
};

int main() {
    ifstream fins;      // file input command
    ofstream fops;      // file output command
    
    Exam student[31];  // Creates an array of objects using the Exam class. 
    
    int wrong_answers[21]; // Stores how many people got a question wrong.
    int num_students = 0;   // Increases as we loop through the provided student-answers file.
    double class_average = 0;
    
    string file_name;   // stores the name & extension of the file we need to open.
    string temp, temp2; // stores temporary input.
    
    
    // Answer key input.
    cout << "What is the answer key file? (ie: answers.txt) ";
    cin >> file_name;
    
    // Open the file and make sure it's open. If it can't open, prompt for the right file.
    fins.open(file_name);
    while (!fins.is_open()) {
        cout << "Could not open file " << file_name << ". What is the answer key file? ";
        cin >> file_name;
        fins.open(file_name);
    }
    
    // Populate student[0] with the answer key.
    student[0].setName("Answer Key");
    student[0].setScore(21);
    
    for (int i = 0; i < 21 && !fins.eof(); i++) {
        fins >> temp;
        student[0].setAnswer(i, temp);
    }
    
    // Done with the answer key.
    fins.close();
    
    
    // Student answer file input.
    cout << "What is the name of the student answer file? ";
    cin >> file_name;
    
    // Open the file and make sure it's open. If it can't open, prompt for the right file.
    fins.open(file_name);
    while (!fins.is_open()) {
        cout << "Could not open file " << file_name << ". What is the student file? (ie: students.txt) ";
        cin >> file_name;
        fins.open(file_name);
    }
    
    // Keep looping until we go thru 30 students (max # our object-array can hold, minus the answer key) OR we reach the end of the file.
    for (int i = 1; i < 31 && !fins.eof(); i++) {
        num_students++; // This will prevent later loops from reading default objects.
        
        // Get student first and last name, then combine them and store in the object-array.
        fins >> temp >> temp2;
        temp += " " + temp2;
        student[i].setName(temp);
        
        for (int j = 0; j < 21; j++) {
            fins >> temp;
            student[i].setAnswer(j, temp);
        }
    }
    
    // Done with the student file!
    fins.close();
    
    // Looping through the object array, without going to 'empty' spots thanks to num_students.
    for (int i = 1; i <= num_students; i++) {
        // Looping through the answers.
        for (int j = 0; j < 21; j++) {
            // Compare the answers, so long as the student put in an anwer.
            if (student[i].getAnswer(j) != "?") {
                // If the student fill-in-the-blank answer is the same/similar to the key, increase score by 1.
                if (j >= 18 && student[i].getAnswer(j).compare(0, 3, student[0].getAnswer(j)) <= 0) {
                    student[i].setScore(1);
                }
                // If they are absolutely the same the same, increase student score by 1.
                else if (student[i].getAnswer(j) == student[0].getAnswer(j)) {
                    student[i].setScore(1);
                }
                // Otherwise the answer is probably wrong, so subtract a quarter of a point.
                else {
                    student[i].setScore(-0.25);
                    wrong_answers[j]++;         // Also, add 1 to the wrong/omitted counter for this question.
                }
            }
            else {
                wrong_answers[j]++;         // Add 1 to the wrong/omitted counter for this question.
            }
        }
    }
    
    
    
    // Prompt for grade file storage.
    cout << "What file would you like to save the grades to? ";
    cin >> file_name;
    
    char append = 0; // Used to determine if we should overwrite the file or not.
    
    while (append != 'Y' && append != 'N') {
        cout << "Would you like to overwrite that file or add to the end of it? (Y/N) ";
        cin >> append;
        append = toupper(append);
    }
    
    // Open the file depending on whether we want to append or overwrite.
    if (append == 'Y') {
        fops.open(file_name, fstream::app);
    }
    else {
        fops.open(file_name);
    }

    
    cout << endl << "Name | Score | Answers (1-21)" << endl;
    
    // Making sure that appending to the file is on a new line and that it's clear when the new output starts.
    if (append == 'Y') {
        fops << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    
    fops << "Name | Score | Answers (1-21)" << endl;
    
    for (int i = 0; i <= num_students; i++) {
        // Outputting student information (name, score) to screen & file.
        cout << student[i].getName() << " " << student[i].getScore();
        fops << student[i].getName() << " " << student[i].getScore();
        
        if (i > 0) {
            class_average += student[i].getScore(); // Making sure the answer key doesn't influence our class score.
        }
        
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
    
    cout << endl << "The class average is " << class_average / num_students << " points. The total is " << class_average << " points over " << num_students << " student(s)." << endl; // Averages and totals.
    fops << endl << "The class average is " << class_average / num_students << " points. The total is " << class_average << " points over " << num_students << " student(s)." << endl;
    
    // Done outputting to file!
    fops.close();
}