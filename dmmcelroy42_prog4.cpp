// Name: Dominic McElroy 
// Date 4/25/2023
// purpose : Monster zookeeper program thingy 

#include "dmmcelroy42_prog4.h"

int main() {
    Monsters monster[SIZE];
    int Monsterz = 0, choice;

    Monsterz = loadMonstersFromFile(Monsterz, monster);

    do {
        cout << endl << "What would you like to do?" << endl;
        cout << "\t1. Register a New Monster" << endl;
        cout << "\t2. Remove a Monster From Zoo" << endl;
        cout << "\t3. Print Monsters to Screen" << endl;
        cout << "\t4. Print Monster Care Cost Data" << endl;
        cout << "\t5. End Program" << endl;
        cout << "\tEnter 1,2,3,4, or 5." << endl;
        cout << "CHOICE: ";
        cin >> choice;
        cin.ignore();
        while(choice > 5 || choice < 1) {
            cout << "Enter 1,2,3,4, or 5: ";
            cin >> choice;
            cin.ignore();
        }

        switch (choice) {
            case 1:
                Monsterz = registerMonster(Monsterz, monster);
                break;
            case 2:
                Monsterz = removeMonster(Monsterz, monster);
                break;
            case 3:
                printMonsters(Monsterz, monster);
                break;
            case 4:
                printCostInfo(Monsterz, monster);
                break;
            default:
                break;
        }
    } while(choice != 5);

    saveMonstersToFile(Monsterz, monster);

    cout << endl << "GOODBYE!";

    return 0;
}