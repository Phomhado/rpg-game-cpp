#include <iostream>
#include <string>
#include "player.h"
#include "utils.h"
using namespace std;

void startingScene() {
    textAnimation("You wake up in a cold place, your body aching, you can't see a thing.\n", 40);
    pause(600);

    textAnimation("The air is humid and you can hear a water stream somewhere.\n", 40);
    pause(800);

    textAnimation("Your hands are tied, and you have no clothes on besides old rags covering your private parts.\n", 40);
    pause(700);

    textAnimation("You can either:\n", 40);
    textAnimation("1. Try to break free from the ties.\n", 40);
    textAnimation("2. Try to get up and search for any tools to help you.\n", 40);
}
