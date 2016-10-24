/*

Assignment #3: Turn-based game!
by Ellie Hensley
10-23-16

This game is run using loops, a class, and lots of user input! 
The objective is to be the person to reduce the number of stones to 0.
*/

#include <iostream>
using namespace std;

class GameOfNim {
    private:
        int turnCounter;    // Stores the # of turns that have been completed since the start of the game. Used to determine whose turn it is.
        int numStones;      // Stores the # of stones still in the game. 
    public:
        GameOfNim();        // Default constructor. Sets the # of stones to 20.
        GameOfNim(int startingStones);      // Overloaded Constructor. Lets the user change the starting # of stones.
        void IncrementTurnCounter();    // Increments the turnCounter variable by 1.
        int GetPlayerTurn();    // Returns 0 if it's the players turn, 1 if it's the computers. 
        void ReduceNumStones(int stonesRemoved);    // Reduces numStones by the value in the parameter.
        int GetNumStones(); // Returns the number of stones left in the game.
};

// Sets numStones to 20 and turnCounter to 0.
GameOfNim::GameOfNim() {
    turnCounter = 0;
    numStones = 20;
}

// Sets numStones to the parameter value and turnCounter to 0.
GameOfNim::GameOfNim(int startingStones) {
    turnCounter = 0;
    numStones = startingStones;
}

// Increments the turnCounter variable by 1.
void GameOfNim::IncrementTurnCounter() {
    turnCounter++;
}

// Returns 0 if it's the players turn, 1 if it is the computers.
int GameOfNim::GetPlayerTurn() {
    return turnCounter % 2;
}

// Reduces numStones by the amount held in the parameter.
void GameOfNim::ReduceNumStones(int stonesRemoved) {
    numStones -= stonesRemoved;
}

// Returns numStones.
int GameOfNim::GetNumStones() {
    return numStones;
}


int main() {
    
    // Prompting the user to input the # of stones they want to start with.
    int numStartingStones = 0;
    
    cout << "How many stones do you want to start with? (minimum 20) ";
    cin >> numStartingStones; 
    
    // Making sure there is at least 20 stones.
    if (numStartingStones < 20) {
        numStartingStones = 20;
    }
    
    GameOfNim Game(numStartingStones);
    
    int player_input = 0;       // Player input for the # of stones that should be removed. Initialized to 0 because it is an "illegal" value, forcing the program to prompt the user for a new, legal value.
    int computer_stones = 0;
    
    // Runs the game as long as there are stones left.
    while (Game.GetNumStones() > 0) {
        
        // Runs only when it's the players turn.
        while (Game.GetPlayerTurn() == 0 && Game.GetNumStones() > 0) {
            
            // Making sure the player input is valid (must be between 1 and 3, or numStones if numStones is less than 3.)
            while (player_input <= 0 || player_input > Game.GetNumStones() || player_input > 3) {
                
                // Switch the input prompt depending on the number of stones left.
                if (Game.GetNumStones() < 3) {
                    cout << "Pick a number between 1 and " << Game.GetNumStones() << ". ";
                }
                else {
                    cout << "Pick a number between 1 and 3. ";
                }
                cin >> player_input;
            }
            
            Game.ReduceNumStones(player_input);
            cout << Game.GetNumStones() << " stones remain." << endl << endl;
            Game.IncrementTurnCounter();
        }
        
        // Computer's Turn:
        while (Game.GetPlayerTurn() == 1 && Game.GetNumStones() > 0) {
            
            // Figuring out how many stones to remove based off of how many are left, making the computer a little bit more challenging to beat.
            if (Game.GetNumStones() <= 3) {
                computer_stones = Game.GetNumStones();
                Game.ReduceNumStones(computer_stones);
            }
            else if (Game.GetNumStones() == 7) {
                Game.ReduceNumStones(3);
            }
            else if (Game.GetNumStones() == 6) {
                Game.ReduceNumStones(2);
            }
            else if (Game.GetNumStones() == 5) {
                Game.ReduceNumStones(1);
            }
            else {
                // Pick a random number between 1 and 3.
                computer_stones = (rand() % 3) + 1;
                Game.ReduceNumStones(computer_stones);
            }
            
            player_input = 0; // Resetting player input to an "illegal" value.
            
            if (computer_stones == 1) {
                cout << "The computer removed " << computer_stones << " stone." << endl;
            }
            else {
                cout << "The computer removed " << computer_stones << " stones." << endl;
            }
            
            cout << Game.GetNumStones() << " stones remain." << endl << endl;
            Game.IncrementTurnCounter();
        }
    }
    
    // Win screen!
    if (Game.GetPlayerTurn() == 1) {
        cout << "You Won!" << endl;
    }
    else {
        cout << "The computer won!" << endl;
    }
    
}