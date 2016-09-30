/*
Assignment #2: Calculating your weight on another planet!
This program takes a user-input weight and calculates what it would be on different planets in out solar system.
by Ellie Hensley
9/29/16
*/

#include <iostream>
using namespace std;

class weight_in_space {
    private:
        double weight;                                      // stores the users weight on Earth
        double calculate_weight(double gravity);            // calculates the users weight on different planets
        
    public:
        weight_in_space();                                  // Defaults "weight" to 0.
        weight_in_space(double input_weight);               // Sets "weight" to a user-provided value.
        double GetWeight();                                 // Returns what's stored in "weight"
        void SetWeight(double input_weight);                // Sets "weight" to a user-provided value.
        void PrintWeightCalcs();                            // Outputs the users weight on different planets.
};

// weight_in_space();
// Sets "weight" variable to zero.
weight_in_space::weight_in_space() {
    weight = 0;
}

// weight_in_space();
// Sets "weight" variable to a user-defined value.
weight_in_space::weight_in_space(double input_weight) {
    weight = input_weight;
}

// GetWeight();
// Returns the value stored in "weight"
double weight_in_space::GetWeight() {
    return weight;
}

// SetWeight();
// Sets "weight" to a user-defined input value.
void weight_in_space::SetWeight(double input_weight) {
    weight = input_weight;
}

// calculate_weight()
// Returns what the users weight would be on a different planet.
double weight_in_space::calculate_weight(double gravity) {
    return weight * gravity;
}

// PrintWeightCalcs()
// Outputs the weight of the user on various planets.
void weight_in_space::PrintWeightCalcs() {
    cout << "Your weight on Earth is " << weight << " lbs." << endl << endl;
    
    cout << "Your weight on the other planets is: " << endl;
    cout << "Mercury: " << calculate_weight(0.38) << " lbs." << endl;
    cout << "Venus: " << calculate_weight(0.91) << " lbs." << endl;
    cout << "Mars: " << calculate_weight(1.03) << " lbs." << endl;
    cout << "Jupiter: " << calculate_weight(0.41) << " lbs." << endl;
    cout << "Saturn: " << calculate_weight(0.43) << " lbs." << endl;
    cout << "Uranus: " << calculate_weight(0.75) << " lbs." << endl;
    cout << "Neptune: " << calculate_weight(0.67) << " lbs." << endl;
}

int main() {
    weight_in_space MyWeight;
    
    double user_weight;
    
    cout << "What is your weight on Earth (in lbs)? ";
    cin >> user_weight;
    cout << endl;
    
    MyWeight.SetWeight(user_weight);
    
    MyWeight.PrintWeightCalcs();
}