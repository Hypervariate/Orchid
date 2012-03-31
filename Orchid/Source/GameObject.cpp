#include "GameObject.h"

GameObject::GameObject(){
	shape = new Shape2DRect();

	position.Set(50,50);
	velocity.Set(0,0);

	shape->SetX(position.x);
	shape->SetY(position.y);
	shape->SetW(50);
	shape->SetH(50);	
		
	maxSpeed = 0.01;
	minSpeed = 0.01;

	drag.x = 0.995f;
	drag.y = 0.995f;

	baseInertia.x = 1.5;
	baseInertia.y = 1.5;

	inertia.x = baseInertia.x;
	inertia.y = baseInertia.y;

	moveUp = moveDown = moveLeft = moveRight = false;
	
	
}
GameObject::~GameObject(){
	delete shape;
}
void GameObject::Update(){

	velocity.x = min(velocity.x, maxSpeed);
	velocity.x = max(velocity.x, -maxSpeed);

	velocity.y = min(velocity.y, maxSpeed);
	velocity.y = max(velocity.y, -maxSpeed);

	position.x += velocity.x;
	position.y += velocity.y;

	shape->SetX(position.x);
	shape->SetY(position.y);

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
void GameObject::Draw(){
	shape->DrawShape();
}
void GameObject::Move(float dirX, float dirY){
	inertia.Set(baseInertia.x, baseInertia.y);
	velocity.x += dirX * inertia.x;
	velocity.y += dirY * inertia.y;
}
void GameObject::StartMovingUp(){
	moveUp = true;
	Move(0,-1);
}
void GameObject::StartMovingDown(){
	moveDown = true;
	Move(0,1);
}
void GameObject::StartMovingLeft(){
	moveLeft = true;
	Move(-1,0);
}
void GameObject::StartMovingRight(){
	moveRight = true;
	Move(1,0);
}
void GameObject::StopMovingUp(){
	moveUp = false;
	if(velocity.y < 0 && !moveDown) inertia.y = 0;
	else if(moveDown) StartMovingDown();
}
void GameObject::StopMovingDown(){
	moveDown = false;
	if(velocity.y > 0 && !moveUp) inertia.y = 0;
	else if(moveUp) StartMovingUp();
}
void GameObject::StopMovingLeft(){
	moveLeft = false;
	if(velocity.x < 0 && !moveRight) inertia.x = 0;
	else if(moveRight) StartMovingRight();
}
void GameObject::StopMovingRight(){
	moveRight = false;
	if(velocity.x > 0 && !moveLeft) inertia.x = 0;
	else if(moveLeft) StartMovingLeft();
}