#include <iostream>
#include <string>
// headers from /include
#include "player.h"
#include "attributes.h"
#include "utils.h"
#include "scenes.h"

using namespace std;

Player getPlayerInfo() {
    string name, gender, playerClass;
    textAnimation("First of all, what is your character name?\n", 40);
    getline(cin, name);

    textAnimation("A pleasure to meet you " + name + "! Are you a male or a female? Type M for male or F for female:\n", 40);
    getline(cin, gender);

    if (gender == "M" || gender == "m")
        gender = "male";
    else
        gender = "female";

    textAnimation("Ok, you are " + name + ". But, what is your weapon? A sword, or your own mind?\n", 40);
    textAnimation("Do you prefer to wear a robust armour, or magic robes with a fashioned hat?\n", 40);
    textAnimation("Type K for Knight or W for Wizard.\n", 40);
    getline(cin, playerClass);

    if (playerClass == "K" || playerClass == "k") {
        playerClass = "knight";
    } else {
        playerClass = "wizard";
    }

    textAnimation("\nNow let's choose your attributes!\n", 40);
    textAnimation("You have three attributes: Strength, Charisma, and Intelligence.\n", 40);
    textAnimation("You have 9 points and you need to assign these 9 points into each attribute, example: 5, 3, 1... Don't cheat!!! Otherwise there will be punishment\n", 60);

    int str, cha, intel;
    textAnimation("Strength: ", 40);
    cin >> str;
    textAnimation("Charisma: ", 40);
    cin >> cha;
    textAnimation("Intelligence: ", 40);
    cin >> intel;

    // Default rule if player tries to cheat or don't assign
    if (str + cha + intel != 9) {
        textAnimation("I told you to not cheat... now suffer the consequences. Assigning defaults!\n", 60);
        (playerClass == "K" || playerClass == "k") ? str = 5, cha = 3, intel = 1 : str = 1, cha = 3, intel = 5;
    }

    Attributes attrs(str, cha, intel);

    textAnimation("Ok! Ready to start your adventure?\n", 40);

    return Player(name, gender, playerClass, attrs);
}

int main() {
    textAnimation("Hello player! Welcome to a simple, yet fun, mini RPG game! Made with love.\n", 40);
    textAnimation("Before we begin, we need to create your character! So follow the instructions below.\n", 40);

    Player player = getPlayerInfo();
    player.showStats();

    startingScene(player);
}
