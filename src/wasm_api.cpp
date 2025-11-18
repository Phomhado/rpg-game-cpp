#include "wasm_api.h"

#include "dice.h"
#include "player.h"

#include <sstream>
#include <string>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#define WASM_EXPORT EMSCRIPTEN_KEEPALIVE
#else
#define WASM_EXPORT
#endif

namespace {
std::string last_message;
Player current_player{"", "", "knight", Attributes(3, 3, 3)};
bool player_initialized = false;

void ensure_player_initialized() {
    if (!player_initialized) {
        set_player("Adventurer", "unknown", "knight", 3, 3, 3);
    }
}
}

extern "C" {

WASM_EXPORT void set_player(const char *name, const char *gender, const char *playerClass,
                            int strength, int charisma, int intelligence) {
    Attributes attributes(strength, charisma, intelligence);
    current_player = Player(name ? name : "", gender ? gender : "", playerClass ? playerClass : "knight", attributes);
    player_initialized = true;

    std::ostringstream builder;
    builder << "Welcome, " << current_player.player_name << " (" << current_player.player_class
            << ")! The cavern wind chills you as you take your first step.\n";
    last_message = builder.str();
}

WASM_EXPORT const char *get_player_summary() {
    ensure_player_initialized();
    std::ostringstream builder;
    builder << "Name: " << current_player.player_name << "\n";
    builder << "Gender: " << current_player.player_gender << "\n";
    builder << "Class: " << current_player.player_class << "\n";
    builder << "HP: " << current_player.player_health_points << " | Mana: " << current_player.player_mana << "\n";
    builder << "STR: " << current_player.attributes.strength << " | CHA: " << current_player.attributes.charisma
            << " | INT: " << current_player.attributes.intelligence << "\n";

    last_message = builder.str();
    return last_message.c_str();
}

WASM_EXPORT const char *get_starting_scene() {
    ensure_player_initialized();
    std::ostringstream builder;
    builder << "You wake up in a cold place, your body aching, you can't see a thing.\n";
    builder << "The air is humid and you can hear a water stream somewhere.\n";
    builder << "Your hands are tied, and you have no clothes on besides old rags covering your private parts.\n\n";
    builder << "You can either:\n";
    builder << "1. Try to break free from the ties.\n";
    builder << "2. Try to get up and search for any tools to help you.\n";

    last_message = builder.str();
    return last_message.c_str();
}

WASM_EXPORT const char *resolve_starting_choice(int choice) {
    ensure_player_initialized();
    bool success = false;
    std::ostringstream builder;

    if (choice == 1) {
        builder << "You tense your muscles and try to snap the ropes...\n";
        success = skillCheck(current_player.attributes.strength, 15);
    } else if (choice == 2) {
        builder << "You focus your mind, trying to spot or feel anything nearby that could help...\n";
        success = skillCheck(current_player.attributes.intelligence, 15);
    } else {
        builder << "You hesitate, doing nothing as the cold seeps into your bones.\n";
        last_message = builder.str();
        return last_message.c_str();
    }

    builder << checkResult(success) << "\n";

    if (success && choice == 1) {
        builder << "With a burst of effort, the ropes snap! You're free.\n";
    } else if (success && choice == 2) {
        builder << "Your fingers find a sharp rock nearby enough to cut through the ropes!\n";
    } else {
        builder << "You struggle for a while, but exhaustion overtakes you...\n";
    }

    last_message = builder.str();
    return last_message.c_str();
}

} // extern "C"
