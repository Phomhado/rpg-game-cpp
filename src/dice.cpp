#include "dice.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

int rollDice(int sides) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(1, sides);
  return distrib(gen);
}

bool skillCheck(int attributeBonus, int difficultyClass) {
    int roll = rollDice(20);
    int total = roll + attributeBonus;

    cout << "Rolled a " << roll << " + " << attributeBonus 
         << " = " << total << " (Difficulty " << difficultyClass << ")\n";

    return total >= difficultyClass;
}

string checkResult(bool success) {
    if (success)
        return "Success!";
    else
        return "Failure...";
}