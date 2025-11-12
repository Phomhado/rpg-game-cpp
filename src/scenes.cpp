#include <iostream>
#include <string>
#include "player.h"
#include "utils.h"
#include "dice.h"
using namespace std;

void startingScene(Player &player) {
    textAnimation("You wake up in a cold place, your body aching, you can't see a thing.\n", 40);
    pause(600);

    textAnimation("The air is humid and you can hear a water stream somewhere.\n", 40);
    pause(800);

    textAnimation("Your hands are tied, and you have no clothes on besides old rags covering your private parts.\n", 40);
    pause(700);

    textAnimation("You can either:\n", 40);
    textAnimation("1. Try to break free from the ties.\n", 40);
    textAnimation("2. Try to get up and search for any tools to help you.\n", 40);

    int choice;
    cout << "\nChoose an action (1 or 2): ";
    cin >> choice;

    bool success = false;

    if (choice == 1) {
        textAnimation("\nYou tense your muscles and try to snap the ropes...\n", 40);
        success = skillCheck(player.attributes.strength, 15);
    } 
    else if (choice == 2) {
        textAnimation("\nYou focus your mind, trying to spot or feel anything nearby that could help...\n", 40);
        success = skillCheck(player.attributes.intelligence, 15);
    } 
    else {
        textAnimation("\nYou hesitate, doing nothing as the cold seeps into your bones.\n", 40);
        return;
    }

    pause(800);
    textAnimation("\n" + checkResult(success) + "\n", 40);
    pause(600);

    if (success && choice == 1) {
        textAnimation("With a burst of effort, the ropes snap! You're free.\n", 40);
    } 
    else if (success && choice == 2) {
        textAnimation("Your fingers find a sharp rock nearby enough to cut through the ropes!\n", 40);
    } 
    else {
        textAnimation("You struggle for a while, but exhaustion overtakes you...\n", 40);
    }
}
