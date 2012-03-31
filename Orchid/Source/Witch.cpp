#include "Witch.h"

Witch::Witch(){
	position.Set(50,50);
	velocity.Set(0,0);

	shape.SetX(position.x);
	shape.SetY(position.y);
	shape.SetW(50);
	shape.SetH(50);	
		
	maxSpeed = 0.01;
	minSpeed = 0.01;

	drag.x = 0.995f;
	drag.y = 0.995f;

	baseInertia.x = 1.5;
	baseInertia.y = 1.5;

	inertia.x = baseInertia.x;
	inertia.y = baseInertia.y;
	
	
}
Witch::~Witch(){

}
