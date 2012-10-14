#include "BreakoutBlock.h"
#include "AudioCore.h"
#include <cstdlib>
#include <time.h>

BreakoutBlock::BreakoutBlock(int x, int y) : GameObject(x, y){
	shape->SetW(48);
	shape->SetH(24);
    baseInertia.x = baseInertia.y = 0;
	life = 10;
	srand ( time(NULL) );
	
}
BreakoutBlock::~BreakoutBlock(){

}
void BreakoutBlock::Update(){
	GameObject::Update();
	
}
void BreakoutBlock::Draw(){
	GraphicsCore::BlitImage("BreakoutBlock", position.x - shape->GetHalfOfWidth(), position.y - shape->GetHalfOfHeight());
	GameObject::Draw();
}
void BreakoutBlock::HandleCollisionWithTarget(GameObject* target){
	GameObject::HandleCollisionWithTarget(target);
	if(shape->IsColliding()){
		target->Move(rand() % 8 - 4, -target->GetVelocityY());
		life = 0;
		alive = false;
		AudioCore::PlaySample("BreakoutBall");
	}
	
}