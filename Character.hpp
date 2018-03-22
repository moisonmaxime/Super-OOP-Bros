#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character{
	string name;
	int health;
	int x, y; // location in window where x&y | [a, b]
	int vx, vy;

public:

	Character(){
		this->name = "default name";
		this->health = 10;
		this->x = 1;
		this->y = 1;
	}

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
	void move_left(){
		if (x > -0.95){
			x -= 0.05;
		}
	}

	void right(){
		if (x < 0.95){
			x += 0.05;
		}
	}

	void setVelocity(int vx, int vy){
		this->vx = vx;
		this->vy = vy;
	}

	void attack(){
		// todo
	}

	void die(){
		// todo
	}

};

#endif
