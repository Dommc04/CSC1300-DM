// Name: Dominic McElroy 
// Date 4/25/2023
// purpose : Monster zookeeper program thingy 

#include "dmmcelroy42_prog4.h"

int loadMonstersFromFile(int Monsterz, Monsters *monsters) {
    string filename, tempstring;
    fstream file;
    cout << "What is the name of the file with your monster data? (ex: filename.txt)" << endl << "FILENAME:  ";
    getline(cin, filename);
    file.open(filename);
    cout << endl;
    if (file.is_open()) {
        while(!file.eof()) {
            getline(file, monsters[Monsterz].name, '#');
            getline(file, monsters[Monsterz].description, '#');
            getline(file, tempstring, '#');
            monsters[Monsterz].weight = stod(tempstring);
            getline(file, tempstring, '#');
            monsters[Monsterz].height = stod(tempstring);
            getline(file, monsters[Monsterz].location, '#');
            getline(file, tempstring, '#');
            monsters[Monsterz].danger = stoi(tempstring);
            getline(file, tempstring, '#');
            monsters[Monsterz].cost.numHours = stod(tempstring);
            getline(file, tempstring, '#');
            monsters[Monsterz].cost.costWeek = stod(tempstring);
            getline(file, tempstring, '#');
            monsters[Monsterz].cost.costFood = stod(tempstring);
            getline(file, tempstring, '#');
            monsters[Monsterz].cost.costNotFood = stod(tempstring);
            if(monsters[Monsterz].name != "") {
                cout << monsters[Monsterz].name << " has been added." << endl;
                Monsterz++;
            }
        }
    }
    cout << endl << "All creatures from " << filename << " have been added to the program." << endl << endl;
    return Monsterz;
}

int registerMonster(int Monsterz, Monsters *monsters) {
    cout << endl << "NAME: ";
    getline(cin, monsters[Monsterz].name);
    cout << "DESCRIPTION: ";
    getline(cin, monsters[Monsterz].description);
    cout << "WEIGHT (in pounds): ";
    cin >> monsters[Monsterz].weight;
    cin.ignore();
    while(monsters[Monsterz].weight <= 0) {
        cout << "WEIGHT (in pounds): ";
        cin >> monsters[Monsterz].weight;
        cin.ignore();
    }
    cout << "HEIGHT (in feet): ";
    cin >> monsters[Monsterz].height;
    cin.ignore();
    while(monsters[Monsterz].height <= 0) {
        cout << "HEIGHT (in feet): ";
        cin >> monsters[Monsterz].height;
        cin.ignore();
    }
    cout << "LAST KNOWN LOCATION: ";
    getline(cin, monsters[Monsterz].location);
    cout << "DANGER LEVEL (1-5): ";
    cin >> monsters[Monsterz].danger;
    cin.ignore();
    while(monsters[Monsterz].danger > 5 || monsters[Monsterz].danger < 1) {
        cout << "DANGER LEVEL (1-5): ";
        cin >> monsters[Monsterz].danger;
        cin.ignore();
    }
    cout << endl << "CARE INFORMATION (per week): " << endl << "\tRequired direct care for monster (in hours) ";
    cin >> monsters[Monsterz].cost.numHours;
    cin.ignore();
    while(monsters[Monsterz].cost.numHours < 0) {
        cout << "\tRequired direct care for monster (in hours) ";
        cin >> monsters[Monsterz].cost.numHours;
        cin.ignore();
    }
    cout << "\tCost of care $ ";
    cin >> monsters[Monsterz].cost.costWeek;
    cin.ignore();
    while(monsters[Monsterz].cost.costWeek < 0) {
        cout << "\tCost of care $ ";
        cin >> monsters[Monsterz].cost.costWeek;
        cin.ignore();
    }
    cout << "\tFood cost $ ";
    cin >> monsters[Monsterz].cost.costFood;
    cin.ignore();
    while(monsters[Monsterz].cost.costFood < 0) {
        cout << "\tFood cost $ ";
        cin >> monsters[Monsterz].cost.costFood;
        cin.ignore();
    }
    cout << "\tMedical & grooming cost $ ";
    cin >> monsters[Monsterz].cost.costNotFood;
    cin.ignore();
    while(monsters[Monsterz].cost.costNotFood < 0) {
        cout << "\tMedical & grooming cost $ ";
        cin >> monsters[Monsterz].cost.costNotFood;
        cin.ignore();
    }
    cout << endl << "The " << monsters[Monsterz].name << " has been added." << endl << endl;
    Monsterz++;
    return Monsterz;
}

int removeMonster(int Monsterz, Monsters *monsters) {
    string tempstring;
    bool found = false;

    cout << endl << "The following is a list of all the monsters in the zoo:" << endl;
    for (int i = 0; i < Monsterz; i++) {
        cout << monsters[i].name << endl;
    }
    cout << endl << "What monster is leaving the zoo?" << endl << "MONSTER NAME: ";
    getline(cin, tempstring);
    
    for (int i = 0; i < Monsterz; i++) {
        if (monsters[i].name == tempstring) {
            found = true;
            for (int j = i; j < Monsterz - 1; j++) {
                monsters[j] = monsters[j + 1];
            }
            Monsterz--;
            cout << "You have removed " << tempstring << "." << endl << endl;
            break;
        }
    }
    if (!found) {
        cout << "Sorry, a monster by the name " << tempstring << " could not be found." << endl;
    }

    return Monsterz;
}

void printMonsters(int Monsterz, Monsters *monsters) {
if (Monsterz == 0) {
        cout << "THERE ARE NO MONSTERS AT YOUR ZOO!\n";
        return;
    }

    for (int i = 0; i < Monsterz; ++i) {

        // Print monster header
        cout << endl << "------------------------------------------------------------------------" << endl
                  << "**MONSTER " << (i+1) << "**" << endl
                  << "Name:    " << monsters[i].name << endl
                  << "Description:" << endl;

        // Word-wrap description
        string desc = monsters[i].description;
        const int lineLength = 68;
        while (desc.size() > lineLength) {
            size_t pos = desc.find_last_of(' ', lineLength);
            if (pos == string::npos) pos = lineLength;
            cout << "         " << desc.substr(0, pos) << endl;
            desc.erase(0, pos+1);
        }
        cout << "         " << desc << endl;

        // Print monster stats
        cout << "Weight:  " << fixed << setprecision(2) << monsters[i].weight << " pound(s)" << endl
                  << "Height:  " << monsters[i].height << " feet" << endl
                  << "Last known location:  " << monsters[i].location << endl
                  << "Danger level:  " << monsters[i].danger << endl
                  << "Weekly Care Information:" << endl
                  << "\t-Hours of care required:       " << monsters[i].cost.numHours << endl
                  << "\t-Cost of care:" << "                 $ " << fixed << setprecision(2) << monsters[i].cost.costWeek << endl
                  << "\t-Food cost:" << "                    $ " << monsters[i].cost.costFood << endl
                  << "\t-Grooming & Supplies Cost:" << "     $ " << monsters[i].cost.costNotFood << endl;
    }
    cout << "------------------------------------------------------------------------" << endl << endl;
}

void printCostInfo(int Monsterz, Monsters *monsters) {
if (Monsterz == 0) {
        cout << "There are no monsters in the zoo so the total cost is $0.00." << endl;
        return;
    }

    double totalCost = 0.0;

    cout << fixed << setprecision(2);
    cout << "COST OF EACH MONSTER FOR ONE WEEK:" << endl;
    cout << setw(30) << left << "MONSTER" << setw(20) << right << "CARE COST" << endl;

    for (int i = 0; i < Monsterz; i++) {
        double careCost = monsters[i].cost.numHours * monsters[i].cost.costNotFood + monsters[i].cost.costFood + monsters[i].cost.costWeek;
        totalCost += careCost;

        cout << setw(30) << left << monsters[i].name << "$" << setw(19) << right << careCost << endl;
    }

    cout << endl << setw(30) << left <<  "TOTAL COST: " << "$" << setw(19) << right << totalCost << endl;
}

void saveMonstersToFile(int Monsterz, Monsters *monsters) {
    if (Monsterz == 0) {
        cout << "There are no monsters in the zoo so none can be saved to a file." << endl;
        return;
    }

    string fileName;
    char choice;

    cout << "Would you like to save your monster list to a file? (y or n) ";
    cin >> choice;

    if (tolower(choice) == 'n') {
        return;
    }

    cout << "What is the name of the file you want to save your creatures to?" << endl;
    cout << "FILENAME: ";
    cin >> fileName;

    ofstream file(fileName);

    for (int i = 0; i < Monsterz; i++) {
        file << monsters[i].name << "#" << monsters[i].description << "#" << monsters[i].weight << "#" << monsters[i].height << "#" << monsters[i].location << "#" << monsters[i].danger << "#" << monsters[i].cost.numHours << "#" << monsters[i].cost.costWeek << "#" << monsters[i].cost.costFood << "#" << monsters[i].cost.costNotFood << "#";
    }

    file.close();

    cout << endl << "Your monsters currently housed in the zoo were successfully saved to the " << fileName << " file." << endl << endl;
}

