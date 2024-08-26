/*Name: Dominic McElroy
Date: 4/7/2023
Purpose: Candyland - Life mix board game
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice() {
    return rand() % 6 + 1; // generate a random number between 1 and 6
}

int main() {
cout <<"Welcome to it's a hard knock life!" << endl;
    //start of da randomness
    srand(time(NULL));

    // the start
    const int totalPlayers = 20;
    const int totalSpaces = 25;
    string names[totalPlayers];
    int boardthings[totalPlayers] = {0};
    int chaching[totalPlayers] = {0};

    // introducing da playas
    int numPlayers;
    cout << "Enter the number of players (1-20): ";
    cin >> numPlayers;
    cin.ignore();

    for (int i = 0; i < numPlayers; i++) {
        cout << "Enter name for player " << i+1 << ": ";
        getline(cin, names[i]);
    }

    //sir loops a lot
    int daplaya = 0;
    while (boardthings[daplaya] < totalSpaces) {
        //its dice rollin time
        cout << names[daplaya] << ", press Enter to roll the dice.";
        cin.get();

        int diceRoll = rollDice();
        cout << "You rolled a " << diceRoll << "!" << endl;


switch(diceRoll)
{
	case 1:
		cout << " _________\n";
		cout << "|         |\n";
		cout << "|    o    |\n";
		cout << "|         |\n";
		cout << "|_________|\n\n";
		break;
	case 2:
		cout << " _________\n";
		cout << "|         |\n";
		cout << "|  o      |\n";
		cout << "|      o  |\n";
		cout << "|_________|\n\n";
		break;
	case 3:
		cout << " _________\n";
		cout << "| o       |\n";
		cout << "|    o    |\n";
		cout << "|       o |\n";
		cout << "|_________|\n\n";
		break;
	case 4:
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "|         |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		break;
	case 5:
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "|    o    |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		break;
	case 6:
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "| o     o |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		break;
}
    int random = rand() % 2 + 1;
     fstream file;
     string fileinput;
     if (random == 1) {
        file.open("good_things.txt");
        for (int i = 0; i < rand() % 20 + 1; ++i) {
            getline(file,fileinput);
        }
        file.close();
     }
        else{
            file.open("bad_things.txt");
            for (int i = 0; i < rand() % 20 + 1; ++i) {
                getline(file, fileinput);
            }
            file.close();
        }

        boardthings[daplaya] += diceRoll;
        if (boardthings[daplaya] > totalSpaces) {
            boardthings[daplaya] = totalSpaces;
        }


        //player checkups / where the player is after each roll
        cout << names[daplaya] << " is now on space " << boardthings[daplaya] << " with $" << chaching[daplaya] << endl;

        daplaya++;
        if (daplaya == numPlayers) {
            daplaya = 0;
        }
    }

   //the winner winner chicken dinner 
    int winnerchicken = 0;
    for (int i = 1; i < numPlayers; i++) {
        if (chaching[i] > chaching[winnerchicken]) {
            winnerchicken = i;
        }
    }
    cout << names[winnerchicken] << " has won the game with $" << chaching[winnerchicken] << "!" << endl;
    
    char again;
    cout << "Do you want to play again? (y/n) ";
    cin >> again;

    if (again == 'y') {
        main();
    } else {
        return 0;
    }
}










