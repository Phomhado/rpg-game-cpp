Hey.. so this is a simple game I am making with C++

I'm having fun coding this and learning C++ with some other topics in the meantime... so it's a win-win

The game is played entirely on the terminal. It has some animations for the text, ascii colors, etc...
I plan to make a GUI for the game in the future, but since I just started studying about GUI with C++, that
will need to wait.

In the game we have 3 attributes: Strenght, Charisma and Intelligence. When the player is building the character they need
to assing values on these attributes (1, 3 and 5). During the gameplay, the player might have some choices or actions (like
breaking things, searching for things...) and these attributes will wither help them or not. 

The game will have a "dice" setting too, similtar to the DnD but waaaay simpler. 

Anyways, Im enjoying building this! And its a fun way to learn C++ and practice important things like OOP, Structs and Classes, etc...

#POTENTIAL IMPROVEMENTS (list of improvements, new features and fixes I might add)

//Features
1. XP system with level-ups
2. Dice system
//Improvements
1. More animations like dramatic pauses and ASCII colors on the terminal
 //Fixes
 1. Treat errors on the keyboard typing (Example: Gender selection is between M and F, but user can type other things OR just hit enter)

## WebAssembly prototype (browser UI)

There's now a small HTML front-end in `web/` that talks to the engine compiled to WebAssembly. It keeps the text-driven feel, but lets you click buttons for choices and edit the character through a form.

### Building the wasm bundle

1. Install [Emscripten](https://emscripten.org/docs/getting_started/downloads.html) and run `source /path/to/emsdk_env.sh`.
2. Compile the wasm build (no terminal I/O functions are needed for the browser layer):

```bash
em++ -std=c++17 -Iinclude \
  src/wasm_api.cpp src/player.cpp src/dice.cpp \
  -s WASM=1 -s MODULARIZE=1 -s EXPORT_NAME=createRpgModule \
  -s EXPORTED_FUNCTIONS='["_set_player","_get_player_summary","_get_starting_scene","_resolve_starting_choice"]' \
  -o web/game.js
```

This generates `web/game.js` and `web/game.wasm`. Open `web/index.html` in a static server (for example `python -m http.server 8000`) and you should see the dungeon UI calling into the wasm functions.
