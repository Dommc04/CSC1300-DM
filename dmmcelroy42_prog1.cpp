/*
Title: Program 1 
Author: Dominic McElroy
Date: February 11 2023
Purpose: Life Expectancy Calulator*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {

string firstName;
int age;
int gender;
int weight;
char yesno;
int fitnessAmount;
char petOwn;
int marriedLife;
char careTake;
int jobStuff;
char breakFast;
char grandParents;
char fruitEater;
char veggieTales;
int friendHang;
int educationLev;
int totalAge;
char drink;
 /* Setting up the questions*/
 cout << endl << "Enter your name! ";
 getline(cin, firstName);

    cout <<  endl << "What is your current age? "; 
    cin >> age;

    cout <<  endl << "What is your gender?" << endl << "(1) male, (2) female ";
    cin >> gender;

    cout <<  endl <<"what is your current weight? " << endl << "(1) underweight , (2) Just right, (3) Overweight, (4) Obese ";
    cin >> weight;

    cout <<  endl <<"smoke or vape (y or n) ";
    cin >> yesno;

    cout <<  endl <<"Drink more than one alcoholic beverage a day? (y or n) ";
    cin >> drink; 
    
    cout << endl <<"how much do your exercise " << endl << "(1) none, (2) very little, (3) periodically, (4) active, (5) athlete?) ";
    cin >> fitnessAmount;

    cout <<  endl <<"Own pet (y or n) ";
    cin >> petOwn;

    cout << endl << "Married? "<< endl << "(1) divorced,(2) single, (3) married, (4 )happily married) ";
    cin >> marriedLife;
    
    cout << endl << "Caretaker (y or n) ";
    cin >> careTake;

    cout <<  endl << "Job " << endl << "(1) hate job, (2) dislike job, (3) it's ok, (4) enjoyable, (5) love it!!) ";
    cin >> jobStuff;

    cout << endl << "Eat breakfast every day (y or n) ";
    cin >> breakFast;

    cout <<  endl << "Parents/grandparents die before age 50 (y or n) ";
    cin >> grandParents;

    cout <<  endl << "Eats fruits daily (y or n) ";
    cin >> fruitEater;

    cout <<  endl << "Eat vegetables daily (y or n) ";
    cin >> veggieTales;

     cout <<  endl << "Hang out with friends" << endl <<"(1) never, (2) periodically, (3) often) ";
     cin >> friendHang;

     cout << endl <<"Education level" << endl <<"(1) No degrees, (2) HS degree, (3) Associates degree, (4) Bachelors degree, (5) Masters/PHD degree) ";
     cin >> educationLev;

/* MATH TIME */
if  (age > 60) {
    totalAge = age;
}
 
else {
    totalAge = 60;
}
cout << endl << " Starting Life Expectancy: " << totalAge;
if  (gender == 2 ) {
    totalAge = totalAge + 4;
}
cout << endl << " Life Expectancy gender: " << totalAge;

if (weight == 1) {
    totalAge = totalAge -1;
}
 else if (weight == 2) {
    totalAge = totalAge +5;
}

else if (weight == 3) {
    totalAge = totalAge -2;
}
else {
     totalAge = totalAge -5;
}
cout << endl << " Life Expectancy after weight: " << totalAge;

if (yesno == 'y') {
  totalAge = totalAge -5;  
}
  
   else {
    totalAge = totalAge +5;
  }
cout << endl << " Life Expectancy after smoking: " << totalAge;
  if (drink == 'y') {
    totalAge = totalAge -5;
  }

  else {
    totalAge = totalAge + 2;
}
cout << endl << " Life Expectancy after alcohol: " << totalAge;
if (fitnessAmount == 1){
    totalAge = totalAge -5;
}

else if (fitnessAmount == 2) {
 totalAge = totalAge -2;
}

else if (fitnessAmount == 4) {
    totalAge = totalAge + 5;
}

else {
    totalAge = totalAge +7;
}
cout << endl << " Life Expectancy after exercise: " <<  totalAge;
if (petOwn== 'y'){
 totalAge = totalAge +3;
}

else if (petOwn == 'n'){
  totalAge = totalAge -1;  
}
cout << endl << " Life Expectancy after pet: " << totalAge;
if (marriedLife == 1){
totalAge = totalAge -5;
}

else if (marriedLife == 2){
 totalAge = totalAge -2;
}

else if (marriedLife == 3){
    totalAge = totalAge + 2;
}

else {
    totalAge = totalAge +5;
}
cout << endl << " Life Expectancy after married: " << totalAge;
if (careTake == 'y'){
    totalAge = totalAge -2;
}
cout << endl << " Life Expectancy after caretaker: " << totalAge;
if (jobStuff ==1){
    totalAge = totalAge -5;
}

else if (jobStuff == 2){
    totalAge = totalAge -2;
}

else if (jobStuff == 4) {
    totalAge = totalAge + 2;
}

else { 
    totalAge = totalAge + 5;
}
cout << endl << " Life Expectancy after job stress: " << totalAge;
if (breakFast == 'y'){
    totalAge = totalAge +5;
}

else if (breakFast == 'n'){
 totalAge = totalAge -2;
}
cout << endl << " Life Expectancy after breakfast: " << totalAge;
if (grandParents == 'y'){
    totalAge = totalAge -2;
}

else if (grandParents == 'n'){
    totalAge = totalAge +5;
}
cout << endl << " Life Expectancy after died: " << totalAge;
 if (fruitEater == 'y' ){
    totalAge = totalAge +5;
 }

 else if (fruitEater == 'n'){
   totalAge = totalAge -5;
 }
cout << endl << " Life Expectancy after fruits: " << totalAge;
 
 if(veggieTales == 'y'){
    totalAge = totalAge +5;
 }
 
 else if (veggieTales == 'n'){
 totalAge = totalAge -5;
 }
 cout << endl << " Life Expectancy after vegetables: " << totalAge;
 if (friendHang == 1 ){
    totalAge = totalAge -2;
 }

 else if (friendHang == 3){
   totalAge = totalAge +2;
 }
 
   else { totalAge = totalAge -5;
 
 }
cout << endl << " Life Expectancy after friends: " <<  totalAge;

if (educationLev == 1){
 totalAge = totalAge -5;
}
 else if (educationLev == 2){
   totalAge = totalAge -2;
 }

 else if (educationLev == 3 ){
    totalAge = totalAge + 2;
 }

 else if (educationLev == 4){
   totalAge = totalAge + 5;
 }

 else {
    totalAge = totalAge + 7;
 }
 cout << endl << " Life Expectancy after education level: " << totalAge << endl;

cout << "****************************************************************************************" << endl;
cout << "            Name:     " << firstName << endl;
cout << "     current age:    " << age << endl;
cout <<" Life Expectancy:    " << totalAge << endl << endl;
cout << "****************************************************************************************" << endl;
}


