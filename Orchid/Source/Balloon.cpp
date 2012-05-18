#include "Balloon.h"
#include "AudioCore.h"

const int POPPED = 1;

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
	
	GameObject::Update();
}

void Balloon::Draw(){
	if(GetLife() > POPPED)
		GraphicsCore::BlitImage("Balloon", position.x - shape->GetHalfOfWidth(), position.y - shape->GetHalfOfHeight());
	GameObject::Draw();
}
void Balloon::HandleCollisionWithTarget(GameObject* target){
	if(target->GetObjectType() == "Frog"){
		SetLife(POPPED);
	}
}