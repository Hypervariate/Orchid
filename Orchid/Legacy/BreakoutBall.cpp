#include "BreakoutBall.h"
#include "AudioCore.h"



BreakoutBall::BreakoutBall(int x, int y, float vx, float vy) : GameObject(x, y){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(x,y,15);
	position.x = x;
	position.y = y;
	baseInertia.x = baseInertia.y = 10;
	maxSpeed = 5;
	drag.x = drag.y = 1.0f;	
	Move(vx, vy);

	
}
BreakoutBall::~BreakoutBall(){

}
void BreakoutBall::Update(){
	
	if(GetX() < 0 || GetX() > WIDTH - GetHalfOfWidth()) velocity.x *= -1;
	if(GetY() < 0 || GetY() > HEIGHT - GetHalfOfHeight()) velocity.y *= -1;
	
	GameObject::Update();
}

void BreakoutBall::Draw(){
	GraphicsCore::BlitImage("BreakoutBall", position.x - shape->GetHalfOfWidth(), position.y - shape->GetHalfOfHeight());
	GameObject::Draw();
}