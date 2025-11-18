#ifndef WASM_API_H
#define WASM_API_H

#ifdef __cplusplus
extern "C" {
#endif

// Initialize the player before running any scene-related functions.
void set_player(const char *name, const char *gender, const char *playerClass,
                int strength, int charisma, int intelligence);

// Returns a formatted summary of the current player state.
const char *get_player_summary();

// Returns the intro narrative for the first scene and available options.
const char *get_starting_scene();

// Resolves the first scene choice (1 or 2) and returns the resulting narrative.
const char *resolve_starting_choice(int choice);

#ifdef __cplusplus
}
#endif

#endif
