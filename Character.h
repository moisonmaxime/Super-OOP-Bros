#ifndef CHARACTER_H
#define CHARACTER_H

#include "Gravity.h"
#include <string>

using namespace std;

class Character{
	string name;
	int health;
	int x, y; // location in window where x&y | [a, b]

public:

	// constructor
	Character(string name, int health, int x, int y){
		this->name = name;
		this->health = health;
		this->x = x;
		this->y = y;
	}

	// Getters
	string getName(){ return name; }
	int getHealth(){ return health; }

	// Setters
	void decrease_health(int dec){ health = health - dec; }
	void increase_health(int inc){ health = health + inc; }

	// Character actions are virtual in case we want some characters to have special implimentations later.
	virtual void move_left(){
		if (x > -0.95){
			x -= 0.05;
		}
	}

	virtual void right(){
		if (x < 0.95){
			x += 0.05;
		}
	}

	virtual void jump(){
		if (y = -0.4){ // if on ground (we will need to be aware of other platforms. deal with this later.)
			// todo
		}
	}

	virtual void attack(){
		// todo
	}

	virtual void die(){
		// todo
	}

};

#endif
