/*
    Title: Program TWO!!!!
    Author: Dominic McElroy
    Date: 3/8/2023
    Purpose: MASH MASH MASH
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int displayMenuGetChoice(), getrand(int, int), getmoney(), getchill();
void getrest();
string getpeople(), getdwelling(), getcar(), getlocation(), getcompany(), getjob();

fstream file;
int Choice, p1, p2, p3, s1, s2, s3, inte, inte2, chill, money, randomnum;
string job1, job2, job3, company1, company2, company3, jobshtuff, companyshtuff, car, people, location, dwelling, line;

int main() {
    srand(time(0));
    do {
        switch(displayMenuGetChoice()) {
            case(1):
                //The 
                cout << endl << "You chose to predict your future!" << endl << "First, I need just a little information." << endl << endl;
                getrest();
                cout << endl << endl << "******  YOUR FUTURE  ******" << endl;
                cout << "You and your spouse, " << getpeople() << " will live in a " << getdwelling() << " in " << getlocation() << " and drive a " << getcar() << "." << endl << "You and your spouse will have " << getchill() << " children." << endl << "You will work at " << getcompany() << " as a " << getjob() << " making $" << getmoney() << " a year." << endl;
                break;
            default:
                break;
        }
    } while (Choice != 2);
    cout << "you chose to end the program." << endl << "Bye!";
    return(0);
}

//displays the main menu and allows the user to choose an option
int displayMenuGetChoice() {
    cout << "Pick from the following menu:" << endl << "1.  Let's play MASH!" << endl << "2.  End program." << endl << "CHOOSE 1 or 2: ";
    cin >> Choice;
    while (Choice > 2 || Choice < 1) {
        cout << "Invalid choice. CHOOSE 1 or 2: ";
        cin >> Choice;
    }
    if (Choice == 1) {
        return(1);
    }
    else {
        return(2);
    }
}

//allows the user to input the rest of the needed data and verifies data according to prompt
void getrest() {
    cout << "Enter three numbers between 1 and 100, seperated by a space." << endl;
    cin >> p1 >> p2 >> p3;
    while (p1 > 100 || p1 < 1) {
        cout << "Invalid choice for the first number you entered." << endl << "Enter a number between 1 and 100. " << endl;
        cin >> p1;
    }
    while (p2 > 100 || p2 < 1) {
        cout << "Invalid choice for the second number you entered." << endl << "Enter a number between 1 and 100. " << endl;
        cin >> p2;
    }
    while (p3 > 100 || p3 < 1) {
        cout << "Invalid choice for the third number you entered." << endl << "Enter a number between 1 and 100. " << endl;
        cin >> p3;
    }
    cin.ignore();
    cout << endl << "Enter in an awesome job title: ";
    getline(cin, job1);
    cout << "Enter in another awesome job title: ";
    getline(cin, job2);
    cout << "Enter in the worst job title ever: ";
    getline(cin, job3);
    cout << endl << "Enter a company, organization, or restaurant you like: ";
    getline(cin, company1);
    cout << "Enter another company, organization, or restaurant you like: ";
    getline(cin, company2);
    cout << "Enter a company, organization, or restaurant you hate: ";
    getline(cin, company3);
    cout << endl << "Enter three numbers between 10,000 and 500,000, seperated by a space. " << endl;
    cin >> s1 >> s2 >> s3;
    while (s1 > 500000 || s1 < 10000) {
        cout << "The first number you entered was invalid." << endl << "Enter a number between 10000 and 500000. " << endl;
        cin >> s1;
    }
    while (s2 > 500000 || s2 < 10000) {
        cout << "The second number you entered was invalid." << endl << "Enter a number between 10000 and 500000. " << endl;
        cin >> s2;
    }
    while (s3 > 500000 || s3 < 10000) {
        cout << "The third number you entered was invalid." << endl << "Enter a number between 10000 and 500000. " << endl;
        cin >> s3;
    }
}

//randomly picks a dwelling from dwellings.txt
string getdwelling() {
    file.open("DWELLINGS_PC.txt");
    for (int i = 0; i < getrand(1, 15); ++i) {
        getline(file, line);
    }
    dwelling = line;
    file.close();
    return(dwelling);
}

//randomly picks a car from cars.txt
string getcar() {
    file.open("CARS.txt");
    for (int i = 0; i < getrand(1, 15); ++i) {
        getline(file, line);
    }
    car = line;
    file.close();
    return(car);
}

//randomly picks a location from locations.txt
string getlocation() {
    file.open("LOCATIONS.txt");
    for (int i = 0; i < getrand(1, 15); ++i) {
        getline(file, line);
    }
    location = line;
    file.close();
    return(location);
}

//randomly picks a person from people.txt
string getpeople() {
    file.open("PEOPLE.txt");
    for (int i = 0; i < getrand(1, 15); ++i) {
        getline(file, line);
    }
    people = line;
    file.close();
    return(people);
}

//get children from inputs by picking from 1 to 3
int getchill() {
    getrand(1, 3);
    if (randomnum == 1) {
        inte = p1;
    }
    else if (randomnum == 2) {
        inte = p2;
    }
    else {
        inte = p2;
    }
    return(inte);
}

string getcompany() {
    getrand(1, 3);
    if (randomnum == 1) {
        companyshtuff = company1;
    }
    else if (randomnum == 2) {
        companyshtuff = company2;
    }
    else {
        companyshtuff = company3;
    }
    return(companyshtuff);
}

string getjob() {
    getrand(1, 3);
    if (randomnum == 1) {
        jobshtuff = job1;
    }
    else if (randomnum == 2) {
        jobshtuff = job2;
    }
    else {
        jobshtuff = job3;
    }
    return(jobshtuff);
}

//get salary from inputs by picking from 1 to 3
int getmoney() {
    getrand(1, 3);
    if (randomnum == 1) {
        inte2 = s1;
    }
    else if (randomnum == 2) {
        inte2 = s2;
    }
    else {
        inte2 = s2;
    }
    return(inte2);
}

//return a random number from low input to high input
int getrand(int low, int high) {
    srand(time(0));
    randomnum = (rand() % high - low) + low + 1;
    return(randomnum);
}