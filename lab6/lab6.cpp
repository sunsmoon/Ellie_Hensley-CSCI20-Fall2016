// Lab 6: Copyright © Function.
// This program outputs ascii art of Eevee, my favorite pokemon
// followed by a Copyright statement.
// Ellie Hensley
// 9-13-16
// Ascii Eevee courtesy of: http://www.fiikus.net/?pokedex

#include <iostream>
using namespace std;

void copyright(string name, int year) {
    cout << "Copyright © " << name << " " << year << endl; 
}

int main()
{
    cout << "                                      |" << endl;
    cout << "                                     /|" << endl;
    cout << "                                   ,\' |" << endl;
    cout << "                                  .   |" << endl;
    cout << "                                    | |" << endl;
    cout << "                                 \' \'| |" << endl;
    cout << "                                / / | |" << endl;
    cout << "       _,.-\"\"--._              / /  | |" << endl;
    cout << "     ,'          `.           j \'   \' \'" << endl;
    cout << "   ,'              `.         ||   / ,                         ___..--," << endl;
    cout << "  /                  \\        ' `.'`.-.,-\".  .       _..---\"\"'' __, ,'" << endl;
    cout << " /                    \\        \\\` .\"\`      `\"\'\\   ,\'\"_..--\'\'\"\"\"\'.\'.\'" << endl;
    cout << ".                      .      .\'-\'             \\,\' ,\'         ,\',\'" << endl;
    cout << "|                      |      ,`               \' .`         .\' /" << endl;
    cout << "|                      |     /          ,\"`.  \' `-. _____.-\' .\'" << endl;
    cout << "\'                      |..---.|,\".      | | .  .-\'\"\"   __.,-\'" << endl;
    cout << " .                   ,'       ||,|      |.\' |    |\"\"`\'\"" << endl;
    cout << "  `-._   `._.._____  |        || |      `._,\'    |" << endl;
    cout << "      `.   .       `\".     ,\'\"| \"  `\'           ,+." << endl;
    cout << "        \\  \'         |    \'   |   .....        .\'  `." << endl;
    cout << "         .\'          \'     7  \".              ,\'     \\" << endl;
    cout << "                   ,\'      |    `..        _,\'      F" << endl;
    cout << "                  .        |,      `\'----\'\'         |" << endl;
    cout << "                  |      ,\"j  /                   | \'" << endl;
    cout << "                  `     |  | .                 | `,\'" << endl;
    cout << "                   .    |  `.|                 |/" << endl;
    cout << "                    `-..\'   ,\'                .\'" << endl;
    cout << "                            | \\             ,\'\'" << endl;
    cout << "                            |  `,\'.      _,\' /" << endl;
    cout << "                            |    | ^.  .\'   /" << endl;
    cout << "                             `-\'.\' j` V    /" << endl;
    cout << "                                   |      /" << endl;
    cout << "                                   |     /" << endl;
    cout << "                                   |   ,\'" << endl;
    cout << "                                    `\"\"" << endl;
    cout << endl;
    
    copyright("Ellie Hensley", 2016);
}