#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void textAnimation(const string &text, int delayMs) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

void pause(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}
