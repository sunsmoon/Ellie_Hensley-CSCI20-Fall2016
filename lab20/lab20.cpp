#include <iostream>
#include <cstring>
using namespace std;
 
int main() 
{
    char firststr[10];      // Creates a cstring that is 10 characters long.
    int firstname = 0;      // Used later to store the length of the user provided word.
    char *head = firststr;  // Creates a single-character pointer that points to the cstring.
    char *tail = firststr; 

    cout << "Please enter a 10 letter word or less" << endl;
    cin >> firststr;
    //strlen(firststr);     // Why is this included? It does nothing!
    firstname = strlen(firststr); 
    cout << "Your word is " << firststr << endl;

    if (firstname < 10)     
    {
        while (*head != '\0')       // As long as we're not at the end of the cstring.
        {
            cout << *head;
            head++;         // Moves which cstring position head is pointing to.
        }
    }
    else
    {
        cout << "WARNING WORD TOO BIG TO DISPLAY!!" << endl;
    }
    
    cout << endl;
    tail = &firststr[strlen(firststr) - 1];     // sets the tail pointer to point at the next-to-last character of the cstring.
    
    if (firstname < 10)
    {
        while (*tail > 0)       // As long as the tail is pointing at something.
        {
            cout << *tail;
            tail--;             // Moves the tail pointer back along the cstring, reversing it.
        }
    }
    
    cout << endl;
    head = firststr;
    tail = &firststr[strlen(firststr) - 1];
    head++;
    tail--;
    
    // If the word is the same as itself reversed...
    if (*head == *tail)
    {
        cout << "It is an palindrome!" << endl;
    }
    else
    {
        cout << "It is not an palindrome" << endl;
    }

    return 0;
}