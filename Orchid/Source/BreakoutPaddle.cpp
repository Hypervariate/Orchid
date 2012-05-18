#include "BreakoutPaddle.h"
#include "AudioCore.h"
#include <cstdlib>
#include <time.h>

BreakoutPaddle::BreakoutPaddle(int x, int y) : GameObject(x, y){
	shape->SetW(96);
	shape->SetH(24);
    baseInertia.x = baseInertia.y = 8;
	maxSpeed = 8;
	SetLife(10);
	srand ( time(NULL) );
}
BreakoutPaddle::~BreakoutPaddle(){

}
void BreakoutPaddle::Update(){
	GameObject::Update();
	if(GetX() < GetHalfOfWidth()+8) position.x = GetHalfOfWidth()+9;
	else if(GetX() > WIDTH - GetHalfOfWidth()) position.x = WIDTH - GetHalfOfWidth();
}
void BreakoutPaddle::Draw(){
	GraphicsCore::BlitImage("BreakoutPaddle", position.x - shape->GetHalfOfWidth(), position.y - shape->GetHalfOfHeight());
	GameObject::Draw();
}
void BreakoutPaddle::HandleCollisionWithTarget(GameObject* target){
	GameObject::HandleCollisionWithTarget(target);
	if(shape->IsColliding()){
		target->Move(rand() % 8 - 4, -target->GetVelocityY());
		//AudioCore::PlaySample("BreakoutBall");
	}
}