#ifndef GAME_H
#define GAME_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Character.hpp"

using namespace std;

class Game{
    vector<Character*> players;
    Character* winner;
    bool isFirstGame;
    int frame;
    bool* keyStates;
    
public:
    
    // Default game constructor
    Game(){
        frame = 0;
        keyStates = new bool[256];
    }
    
    // the Menu class will set players.
    void setCharacters(Character* p1, Character* p2){
        players.push_back(p1);
        players.push_back(p2);
    }
    
    void keyDown(int key) {
        keyStates[key] = true;
    }
    
    void keyUp(int key) {
        keyStates[key] = false;
    }
    
    void draw(){
        
        for (int i=0; i<256; i++) {
            if (keyStates[i]) {
                cout << "Key " << i << " is being pressed" << endl;
            }
        }
        
        cout << "Frame " << frame << endl;
        frame++;
        if (frame == 11){ frame = 0; }
    }
    
};

#endif
