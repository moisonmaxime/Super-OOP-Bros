#ifndef GRAVITY_H
#define GRAVITY_H

#include "Character.h"

class Gravity{
	int force;

public:

	Gravity(){
		force = 0.5;
	}

	Gravity(int force){
			this->force = force;
	}

	// Maybe a powerup can disable gravity or something... probably wont use this though.
	void setForce(int force){
		this->force = force;
	}

};

#endif
