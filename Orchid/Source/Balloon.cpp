#include "Balloon.h"
#include "AudioCore.h"



Balloon::Balloon(int x, int y) : GameObject(x, y){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(x,y,32);
	position.x = x;
	position.y = y;
	baseInertia.x = baseInertia.y = 10;
	maxSpeed = 5;
	drag.x = drag.y = 1.0f;	
	

	
}
Balloon::~Balloon(){

}
void Balloon::Update(){
	
	if(GetX() < 0 || GetX() > WIDTH - GetHalfOfWidth()) velocity.x *= -1;
	if(GetY() < 0 || GetY() > HEIGHT - GetHalfOfHeight()) velocity.y *= -1;
	
	GameObject::Update();
}

void Balloon::Draw(){
	GraphicsCore::BlitImage("Balloon", position.x - shape->GetHalfOfWidth(), position.y - shape->GetHalfOfHeight());
	GameObject::Draw();
}