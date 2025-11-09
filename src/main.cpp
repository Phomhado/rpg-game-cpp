#include <iostream>
#include <string>
#include "player.h"
using namespace std;

Player getPlayerInfo() {
    string name, gender, playerClass;
    cout << "First of all, what is your character name?\n";
    getline(cin, name);
    cout << "A pleasure to meet you " << name << "! Are you a male or a female? Type M for male or F for female:\n";
    getline(cin, gender);

    if (gender == "M" || gender == "m")
        cout << "By the gods! A hero! Or perhaps not...\n";
    else
        cout << "By the gods! A heroine! Or perhaps not...\n";

    cout << "Ok, you are " << name << ", a " << "But, what is your weapon? A sword, or your own mind? "
         << "Do you prefer to wear a robust armour, or magic robes with a fashioned hat? "
         << "Type K for Knight or W for Wizard.\n";
    getline(cin, playerClass);

    if (playerClass == "K" || playerClass == "k")
        playerClass = "knight";
    else
        playerClass = "wizard";

    cout << "Ok! Ready to start your adventure?\n";

    return Player(name, gender, playerClass);
}

int main() {
    cout << "Hello player! Welcome to a simple, yet fun, mini rpg game! Made with love.\n";
    cout << "Before we begin, we need to create your character! So follow the instructions below.\n";

    Player player = getPlayerInfo();
    player.showStats();
}
