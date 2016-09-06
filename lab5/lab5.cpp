/*
Monster Lab (Lab 5)
Ellie Hensley
9-6-16
This lab asks users to build a monster and saves that info to a STRUCT or a CLASS.
*/

#include <iostream>
using namespace std;

int main()
{
    struct monster_struct {
        string name, head, eyes, ears, mouth, nose;
    };
    
    monster_struct monster_one;
    monster_struct monster_two;
    monster_struct monster_three;
    monster_struct monster_four;
    monster_struct monster_five;
    
    cout << "Name of your first monster: ";
    cin >> monster_one.name;
    cout << "Head type (Zombus, Franken, Happy): ";
    cin >> monster_one.head;
    cout << "Eyes (Vegitas, Spritem, Wackus): ";
    cin >> monster_one.eyes;
    cout << "Nose (Vegitas, Spritem, Wackus): ";
    cin >> monster_one.nose;
    cout << "Mouth (Vegitas, Spritem, Wackus): ";
    cin >> monster_one.mouth;
    cout << "Ears (Vegitas, Spritem, Wackus): ";
    cin >> monster_one.ears;
    
    cout << "Name of your two monster: ";
    cin >> monster_two.name;
    cout << "Head type (Zombus, Franken, Happy): ";
    cin >> monster_two.head;
    cout << "Eyes (Vegitas, Spritem, Wackus): ";
    cin >> monster_two.eyes;
    cout << "Nose (Vegitas, Spritem, Wackus): ";
    cin >> monster_two.nose;
    cout << "Mouth (Vegitas, Spritem, Wackus): ";
    cin >> monster_two.mouth;
    cout << "Ears (Vegitas, Spritem, Wackus): ";
    cin >> monster_two.ears;
    
    cout << "Name of your three monster: ";
    cin >> monster_three.name;
    cout << "Head type (Zombus, Franken, Happy): ";
    cin >> monster_three.head;
    cout << "Eyes (Vegitas, Spritem, Wackus): ";
    cin >> monster_three.eyes;
    cout << "Nose (Vegitas, Spritem, Wackus): ";
    cin >> monster_three.nose;
    cout << "Mouth (Vegitas, Spritem, Wackus): ";
    cin >> monster_three.mouth;
    cout << "Ears (Vegitas, Spritem, Wackus): ";
    cin >> monster_three.ears;
    
    cout << "Name of your four monster: ";
    cin >> monster_four.name;
    cout << "Head type (Zombus, Franken, Happy): ";
    cin >> monster_four.head;
    cout << "Eyes (Vegitas, Spritem, Wackus): ";
    cin >> monster_four.eyes;
    cout << "Nose (Vegitas, Spritem, Wackus): ";
    cin >> monster_four.nose;
    cout << "Mouth (Vegitas, Spritem, Wackus): ";
    cin >> monster_four.mouth;
    cout << "Ears (Vegitas, Spritem, Wackus): ";
    cin >> monster_four.ears;
    
    cout << "Name of your five monster: ";
    cin >> monster_five.name;
    cout << "Head type (Zombus, Franken, Happy): ";
    cin >> monster_five.head;
    cout << "Eyes (Vegitas, Spritem, Wackus): ";
    cin >> monster_five.eyes;
    cout << "Nose (Vegitas, Spritem, Wackus): ";
    cin >> monster_five.nose;
    cout << "Mouth (Vegitas, Spritem, Wackus): ";
    cin >> monster_five.mouth;
    cout << "Ears (Vegitas, Spritem, Wackus): ";
    cin >> monster_five.ears;
    
    cout << "Monster Name | Head | Eyes | Nose | Mouth | Ears" << endl;
    cout << monster_one.name << " | " << monster_one.head << " | " << monster_one.eyes << " | " << monster_one.nose << " | " << monster_one.mouth << " | " << monster_one.ears << endl;
    cout << monster_two.name << " | " << monster_two.head << " | " << monster_two.eyes << " | " << monster_two.nose << " | " << monster_two.mouth << " | " << monster_two.ears << endl;
    cout << monster_three.name << " | " << monster_three.head << " | " << monster_three.eyes << " | " << monster_three.nose << " | " << monster_three.mouth << " | " << monster_three.ears << endl;
    cout << monster_four.name << " | " << monster_four.head << " | " << monster_four.eyes << " | " << monster_four.nose << " | " << monster_four.mouth << " | " << monster_four.ears << endl;
    cout << monster_five.name << " | " << monster_five.head << " | " << monster_five.eyes << " | " << monster_five.nose << " | " << monster_five.mouth << " | " << monster_five.ears << endl;
}