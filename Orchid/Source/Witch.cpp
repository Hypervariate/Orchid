#include "Witch.h"

Witch::Witch(){
	position.Set(50,50);
	velocity.Set(0,0);

	shape.SetX(position.x);
	shape.SetY(position.y);
	shape.SetW(50);
	shape.SetH(50);	
	
	
	maxSpeed = 0.1;
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
void Witch::Update(){

	velocity.x = min(velocity.x, maxSpeed);
	velocity.x = max(velocity.x, -maxSpeed);

	velocity.y = min(velocity.y, maxSpeed);
	velocity.y = max(velocity.y, -maxSpeed);

	position.x += velocity.x;
	position.y += velocity.y;

	shape.SetX(position.x);
	shape.SetY(position.y);

	if(!inertia.x){
		velocity.x *= drag.x;
		
		if(velocity.x > 0 && velocity.x < minSpeed)
			velocity.x = 0;
		else if(velocity.x < 0 && velocity.x > -minSpeed)
			velocity.x = 0;
	}

	if(!inertia.y){
		velocity.y *= drag.y;
		
		if(velocity.y > 0 && velocity.y < minSpeed)
			velocity.y = 0;
		else if(velocity.y < 0 && velocity.y > -minSpeed)
			velocity.y = 0;
	}

	

		
}
void Witch::Draw(){
	shape.DrawShape();
}
void Witch::Move(float dirX, float dirY){
	inertia.Set(baseInertia.x, baseInertia.y);
	velocity.x += dirX * inertia.x;
	velocity.y += dirY * inertia.y;
}
void Witch::StopMovingX(){
	inertia.x = 0;
}
void Witch::StopMovingY(){
	inertia.y = 0;
}