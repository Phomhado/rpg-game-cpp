#include <iostream>
#include <string>
#include "player.h"
#include "attributes.h"

using namespace std;

Player getPlayerInfo() {
    string name, gender, playerClass;
    cout << "First of all, what is your character name?\n";
    getline(cin, name);

    cout << "A pleasure to meet you " << name << "! Are you a male or a female? Type M for male or F for female:\n";
    getline(cin, gender);

    if (gender == "M" || gender == "m")
        gender = "male";
    else
        gender = "female";

    cout << "Ok, you are " << name << ". But, what is your weapon? A sword, or your own mind?\n"
         << "Do you prefer to wear a robust armour, or magic robes with a fashioned hat?\n"
         << "Type K for Knight or W for Wizard.\n";
    getline(cin, playerClass);

       if (playerClass == "K" || playerClass == "k") {
        playerClass = "knight";
    } else {
        playerClass = "wizard";
    }

    cout << "\nNow let's choose your attributes!\n";
    cout << "You have three attributes: Strength, Charisma, and Intelligence.\n";
    cout << "You must assign 1, 3, and 5 — each number must be used once... Don't cheat!!! Otherwise there will be punishment\n";

    int str, cha, intel;
    cout << "Strength (1, 3, or 5): ";
    cin >> str;
    cout << "Charisma (remaining numbers): ";
    cin >> cha;
    cout << "Intelligence (remaining number): ";
    cin >> intel;

    // Default rule if player tries to cheat or don't assign
    if (str + cha + intel != 9) {
        cout << "I told you to not cheat... now suffer the consequences. Assigning defaults!\n";
        (playerClass == "K" || playerClass == "k") ? str = 5, cha = 3, intel = 1 : str = 1, cha = 3, intel = 5;
    }

    Attributes attrs(str, cha, intel);

    cout << "Ok! Ready to start your adventure?\n";

    return Player(name, gender, playerClass, attrs);
}

int main() {
    cout << "Hello player! Welcome to a simple, yet fun, mini rpg game! Made with love.\n";
    cout << "Before we begin, we need to create your character! So follow the instructions below.\n";

    Player player = getPlayerInfo();
    player.showStats();
}
