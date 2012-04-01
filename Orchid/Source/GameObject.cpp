#include "GameObject.h"

std::list<GameObject *> GameObject::objects;
std::list<GameObject *>::iterator GameObject::iter1;
std::list<GameObject *>::iterator GameObject::iter2;


GameObject::GameObject(){
	shape = new Shape2DRect();

	position.Set(50,50);
	velocity.Set(0,0);

	shape->SetX(position.x);
	shape->SetY(position.y);
	shape->SetW(50);
	shape->SetH(50);	
		
	maxSpeed = 4.0;
	minSpeed = 0.8;

	baseInertia.x = baseInertia.y = 3;
	drag.x = drag.y = 0.85f;	
	

	inertia.x = baseInertia.x;
	inertia.y = baseInertia.y;

	moveUp = moveDown = moveLeft = moveRight = false;
	
	objects.push_back(this);
}
GameObject::~GameObject(){
	delete shape;
	objects.remove(this);
}
void GameObject::UpdateAll(){
	//update all game objects
	for(iter1 = objects.begin(); iter1 != objects.end(); ++iter1){
		(*iter1)->Update();
		(*iter1)->Draw();
	}
}
void GameObject::Update(){

	if(moveLeft) Move(-1,0);
	if(moveRight) Move(1,0);	
	if(!moveLeft && !moveRight) inertia.x = 0;

	if(moveUp) Move(0,-1);
	if(moveDown) Move(0,1);
	if(!moveUp && !moveDown) inertia.y = 0;
	
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
	if(dirX) velocity.x = dirX * inertia.x;
	if(dirY) velocity.y = dirY * inertia.y;
}
void GameObject::StartMovingUp(){
	moveUp = true;
}
void GameObject::StartMovingDown(){
	moveDown = true;
}
void GameObject::StartMovingLeft(){
	moveLeft = true;
}
void GameObject::StartMovingRight(){
	moveRight = true;
}
void GameObject::StopMovingUp(){
	moveUp = false;
	if(velocity.y < 0 && !moveDown) inertia.y = 0;
}
void GameObject::StopMovingDown(){
	moveDown = false;
	if(velocity.y > 0 && !moveUp) inertia.y = 0;
}
void GameObject::StopMovingLeft(){
	moveLeft = false;
	if(velocity.x < 0 && !moveRight) inertia.x = 0;
}
void GameObject::StopMovingRight(){
	moveRight = false;
	if(velocity.x > 0 && !moveLeft) inertia.x = 0;
}
void GameObject::ResumeMovement(){
	if(moveLeft) StartMovingLeft();
	if(moveRight) StartMovingRight();
	if(moveUp) StartMovingUp();
	if(moveDown) StartMovingDown();
}