#include "player.h"
#include <iostream>
using namespace std;

Player::Player(string n, string g, string c, Attributes a) {
    player_name = n;
    player_gender = g;
    player_class = c;
    attributes = a;

    if (c == "knight") {
        player_health_points = 120;
        player_mana = 30;
    } else if (c == "wizard") {
        player_health_points = 70;
        player_mana = 100;
    }
}

void Player::showStats() {
    cout << "\n--- Player Info ---\n";
    cout << "Name: " << player_name << endl;
    cout << "Gender: " << player_gender << endl;
    cout << "Class: " << player_class << endl;
    cout << "HP: " << player_health_points << endl;
    cout << "Mana: " << player_mana << endl;
    cout << "-------------------\n";
}
