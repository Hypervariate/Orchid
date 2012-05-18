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
	drag.x = drag.y = 0.99f;
	maxSpeed = 5;
	
	
	balloon = new Balloon(x, y - 64);
	GameObject::AddToWorld(balloon);
	
}
Frog::~Frog(){

}
void Frog::Update(){
	

	if(GetX() < -GetHalfOfWidth())
		position.x = WIDTH - GetHalfOfWidth();
	else if(GetX() > WIDTH - GetHalfOfWidth())
		position.x = -GetHalfOfWidth();

	if(GetY() < -GetHalfOfHeight())
		position.y = HEIGHT - GetHalfOfHeight();
	else if(GetY() > HEIGHT - GetHalfOfHeight())
		position.y = -GetHalfOfHeight();
	
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
void Frog::HandleCollisionWithTarget(GameObject* target){
	
	if(shape->IsColliding()){
		Move(-velocity.x/2, -velocity.y/2);
	
	}
}