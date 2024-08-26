// Name: Dominic McElroy 
// Date 4/25/2023
// purpose : Monster zookeeper program thingy 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

const int SIZE = 75;
struct Cost {
    double numHours;
    double costWeek;
    double costFood;
    double costNotFood;
};

struct Monsters {
    string name;
    string description;
    double weight;
    double height;
    string location;
    int danger;
    Cost cost;
};

int loadMonstersFromFile(int Monsterz, Monsters *monsters);
int registerMonster(int Monsterz, Monsters *monsters);
int removeMonster(int Monsterz, Monsters *monsters);
void printMonsters(int Monsterz, Monsters *monsters);
void printCostInfo(int Monsterz, Monsters *monsters);
void saveMonstersToFile(int Monsterz, Monsters *monsters);