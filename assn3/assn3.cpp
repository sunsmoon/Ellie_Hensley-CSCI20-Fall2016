/*

Assignment #3: Turn-based game!
by Ellie Hensley
10-23-16

This game is run using loops, a class, and lots of user input! 
The objective is to be the person to reduce the number of stones to 0.

3 lines of code borrowed from user Greyfade at Stackoverflow. http://stackoverflow.com/a/5655685
Those snips of code are comment-tagged with his/her username.
*/

#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

class GameOfNim {
    private:
        int turnCounter;    // Stores the # of turns that have been completed since the start of the game. Used to determine whose turn it is.
        int numStonesA;      // Stores the # of stones still in the game in pile A.
        int numStonesB;     // Stores the # of stones still in the game in pile B.
    public:
        GameOfNim();        // Default constructor. Sets the # of stones in each pile to 20.
        GameOfNim(int startingStonesA, int startingStonesB);      // Overloaded Constructor. Lets the user change the starting # of stones.
        void IncrementTurnCounter();    // Increments the turnCounter variable by 1.
        int GetPlayerTurn();    // Returns 0 if it's the players turn, 1 if it's the computers. 
        void ReduceNumStonesA(int stonesRemoved);    // Reduces numStonesA by the value in the parameter.
        int GetNumStonesA(); // Returns the number of stones left in pile A.
        void ReduceNumStonesB(int stonesRemoved);    // Reduces numStonesB by the value in the parameter.
        int GetNumStonesB(); // Returns the number of stones left in pile B.
};

// Sets numStonesA and numStonesB to 20 and turnCounter to 0.
GameOfNim::GameOfNim() {
    turnCounter = 0;
    numStonesA = 20;
    numStonesB = 20;
}

// Sets numStones to the parameter value and turnCounter to 0.
GameOfNim::GameOfNim(int startingStonesA, int startingStonesB) {
    turnCounter = 0;
    numStonesA = startingStonesA;
    numStonesB = startingStonesB;
}

// Increments the turnCounter variable by 1.
void GameOfNim::IncrementTurnCounter() {
    turnCounter++;
}

// Returns 0 if it's the players turn, 1 if it is the computers.
int GameOfNim::GetPlayerTurn() {
    return turnCounter % 2;
}

// Reduces numStonesA by the amount held in the parameter.
void GameOfNim::ReduceNumStonesA(int stonesRemoved) {
    numStonesA -= stonesRemoved;
}

// Returns numStonesA.
int GameOfNim::GetNumStonesA() {
    return numStonesA;
}

// Reduces numStonesB by the amount held in the parameter.
void GameOfNim::ReduceNumStonesB(int stonesRemoved) {
    numStonesB -= stonesRemoved;
}

// Returns numStonesB.
int GameOfNim::GetNumStonesB() {
    return numStonesB;
}


int main() {
    
    // Sharing the rules.
    cout << "Welcome to Game of Nim! " << endl;
    cout << "This game is a simple game of subtraction and logic. The goal is to be the person to remove the very last stone in the game. " << endl;
    cout << "There are two piles of stones and you can only remove 1 - 3 stones from each pile." << endl << endl;
    
    // Prompting the user to input the # of stones they want to start with.
    int numStartingStonesA = 0;
    int numStartingStonesB = 0;
    
    // Prompting the user for the # of stones in the first pile.
    while (numStartingStonesA < 15) {
        cout << "How many stones do you want to start with in the first pile? (minimum 15) ";
        cin >> numStartingStonesA; 
    }
    
    while (numStartingStonesB < 15) {
        cout << "How many stones do you want to start with in the second pile? (minimum 15) ";
        cin >> numStartingStonesB; 
    }
    
    GameOfNim Game(numStartingStonesA, numStartingStonesB);
    
    char player_stonePile = 'n';    // Which pile to remove stones from. Legal input: a, A, b, or B.
    int player_numStones = 0;       // How many stones to remove from the pile. Legal input: 1, 2, or 3, so long as none exceed the # of stones in the pile.
    char computer_stonePile = 'n';
    int computer_numStones = 0;
    
    // Runs the game as long as there are stones left.
    while (Game.GetNumStonesA() > 0 || Game.GetNumStonesB() > 0) {
        
        // Runs only when it's the players turn.
        while (Game.GetPlayerTurn() == 0 && (Game.GetNumStonesA() > 0 || Game.GetNumStonesB() > 0)) {
            
            cout << endl << "Pile A has " << Game.GetNumStonesA() << " stones left." << endl;
            cout << "Pile B has " << Game.GetNumStonesB() << " stones left." << endl;
            
            // Asking the player to pick which pile of stones to remove from.
            while (!(player_stonePile == 'a' || player_stonePile == 'A' || player_stonePile == 'b' || player_stonePile == 'B')) {
                cout << "Which pile would you like to remove stones from? (a or b) ";
                cin >> player_stonePile;
            }

            // Making sure the player input is valid (must be between 1 and 3, or numStonesA/numStonesB if they are less than 3.)
            if (player_stonePile == 'a' || player_stonePile == 'A') {
                
                while (player_numStones < 1 || player_numStones > Game.GetNumStonesA() || player_numStones > 3) {
                
                    // Fixes the infinite loop caused by using a letter instead of a number. Courtesy of user Greyfade at Stackoverflow. http://stackoverflow.com/a/5655685
                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                
                    // Switch the input prompt depending on the number of stones left.
                    if (Game.GetNumStonesA() < 3) {
                        cout << "How many stones would you like to remove from? (between 1 and " << Game.GetNumStonesA() << ") ";
                    }
                    else {
                        cout << "How many stones would you like to remove? (between 1 and 3) ";
                    }
                    
                    cin >> player_numStones;
                }
            
                Game.ReduceNumStonesA(player_numStones);
            }
            else if (player_stonePile == 'b' || player_stonePile == 'B') {
                
                while (player_numStones < 1 || player_numStones > Game.GetNumStonesB() || player_numStones > 3) {
                    
                    // Fixes the infinite loop caused by using a letter instead of a number. Courtesy of user Greyfade at Stackoverflow. http://stackoverflow.com/a/5655685
                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    
                    // Switch the input prompt depending on the number of stones left.
                    if (Game.GetNumStonesB() < 3) {
                        cout << "How many stones would you like to remove from? (between 1 and " << Game.GetNumStonesB() << ") ";
                    }
                    else {
                        cout << "How many stones would you like to remove? (between 1 and 3) ";
                    }
                    cin >> player_numStones;
                }
            
            Game.ReduceNumStonesB(player_numStones);
            }

        Game.IncrementTurnCounter();
        }
    
        // Computer's Turn:
        while (Game.GetPlayerTurn() == 1 && (Game.GetNumStonesA() > 0 || Game.GetNumStonesB() > 0)) {
            
            int random = (rand() % 2) + 1;
            
            if (Game.GetNumStonesA() == 0) {
                computer_stonePile = 'b';
            }
            else if (Game.GetNumStonesB() == 0) {
                computer_stonePile = 'a';
            }
            else {
                if (random == 1) {
                    computer_stonePile = 'a';
                }
                else {
                    computer_stonePile = 'b';
                }
            }

            // Figuring out how many stones to remove based off of how many are left, making the computer a little bit more challenging to beat.
            if (computer_stonePile == 'a') {
                if (Game.GetNumStonesA() <= 3) {
                    computer_numStones = Game.GetNumStonesA();
                    Game.ReduceNumStonesA(computer_numStones);
                }
                else if (Game.GetNumStonesA() == 7) {
                    Game.ReduceNumStonesA(3);
                }
                else if (Game.GetNumStonesA() == 6) {
                    Game.ReduceNumStonesA(2);
                }
                else if (Game.GetNumStonesA() == 5) {
                    Game.ReduceNumStonesA(1);
                }
                else {
                    // Pick a random number between 1 and 3.
                    computer_numStones = (rand() % 3) + 1;
                    Game.ReduceNumStonesA(computer_numStones);
                }
            }
            else {
                if (Game.GetNumStonesB() <= 3) {
                    computer_numStones = Game.GetNumStonesB();
                    Game.ReduceNumStonesB(computer_numStones);
                }
                else if (Game.GetNumStonesB() == 7) {
                    Game.ReduceNumStonesB(3);
                }
                else if (Game.GetNumStonesB() == 6) {
                    Game.ReduceNumStonesB(2);
                }
                else if (Game.GetNumStonesB() == 5) {
                    Game.ReduceNumStonesB(1);
                }
                else {
                    // Pick a random number between 1 and 3.
                    computer_numStones = (rand() % 3) + 1;
                    Game.ReduceNumStonesB(computer_numStones);
                }
            }
            
            player_numStones = 0; // Resetting player input to an "illegal" value.
            player_stonePile = 'n';
            
            if (computer_numStones == 1) {
                cout << "The computer removed " << computer_numStones << " stone from pile " << computer_stonePile << "." << endl;
            }
            else {
                cout << "The computer removed " << computer_numStones << " stones from pile " << computer_stonePile << "." << endl;
            }

            Game.IncrementTurnCounter();
            
        }
    }
 
    cout << endl;
    
    if (Game.GetPlayerTurn() == 1) {
        cout << "You won!" << endl;
    }
    else {
        cout << "The Computer Won!" << endl;
    }
}