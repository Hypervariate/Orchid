#include "Frog.h"
#include "AudioCore.h"
#include "Balloon.h"


Frog::Frog(int x, int y) : GameObject(x, y){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(x,y,32);
	position.x = x;
	position.y = y;
	baseInertia.x = baseInertia.y = 2;
	maxSpeed = 4;
	
	
	balloon = new Balloon(x, y - 64);
	GameObject::AddToWorld(balloon);
	
}
Frog::~Frog(){

}
void Frog::Update(){
	
	if(GetX() < 0 || GetX() > WIDTH - GetHalfOfWidth()) velocity.x *= -1;
	if(GetY() < 0 || GetY() > HEIGHT - GetHalfOfHeight()) velocity.y *= -1;
	
	balloon->MoveTo(GetX(), GetY() - 64);

	GameObject::Update();
}

void Frog::Draw(){
	if(velocity.x < 0)
		direction = 1;
	else if(velocity.x > 0)
		direction = 0;
	
	GraphicsCore::BlitImage("Frog", position.x - shape->GetHalfOfWidth(), position.y - shape->GetHalfOfHeight(), direction);
	
	GameObject::Draw();
}