#ifndef PLAYER_H
#define PLAYER_H
#include "attributes.h"

#include <iostream>
using namespace std;

class Player {
public: 
    string player_name;
    string player_class;
    int player_health_points;
    int player_mana;
    string player_gender;
    Attributes attributes;
    
    Player(string n, string g, string c, Attributes a);
    void showStats();

    void playerHeal() {
      player_gender == "male" ? cout << player_name << " healed himself.\n" : cout << player_name << " healed herself.\n";
    }

    void playerEats() {
      cout << "You eat your food. It's delicious and it restores your health!\n";
    }

    void playerDrinks() {
      cout << "You drink your beverage. It's awesome and it also replenish your health!\n";
    }

    void playerSleeps() {
      cout << "You sleep and wake up feeling rested\n";
    }
};

#endif

