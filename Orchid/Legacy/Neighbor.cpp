#include "Neighbor.h"
#include "AudioCore.h"

const int walkingRight = 0;
const int walkingUp = 90;
const int walkingLeft = 180;
const int walkingDown = 270;
const int standing = -1;

Neighbor::Neighbor(int x, int y) : GameObject(x, y){
	
	position.x = x;
	position.y = y;

	shape->SetW(14);
	shape->SetH(19);

	maxSpeed = 1;
	
	walkRight = Animation::FactoryAnimation("GabeWalkRight");
	walkUp = Animation::FactoryAnimation("GabeWalkUp");
	walkLeft = Animation::FactoryAnimation("GabeWalkLeft");
	walkDown = Animation::FactoryAnimation("GabeWalkDown");

	currentAnimation = &walkDown;
}
Neighbor::~Neighbor(){

}
void Neighbor::Update(){
	if(!velocity.x && !velocity.y){
		direction = standing;
	}
	else{
		if(velocity.x > 0)
			direction = walkingRight;
		else if(velocity.x < 0)
			direction = walkingLeft;

		if(velocity.y > 0)
			direction = walkingDown;
		else if(velocity.y < 0)
			direction = walkingUp;
	}

	GameObject::Update();
}

void Neighbor::Draw(){
	

	switch(direction){
		case walkingRight:
			currentAnimation = &walkRight;
			break;
		case walkingUp:
			currentAnimation = &walkUp;
			break;
		case walkingLeft:
			currentAnimation = &walkLeft;
			break;
		case walkingDown:
			currentAnimation = &walkDown;
			break;
		case standing:
			currentAnimation->StopAnimation();
			break;

	}

	if(direction != standing)
		currentAnimation->PlayAnimation();
	
	GraphicsCore::BlitImage(currentAnimation->UpdateAnimation(), GetX() - shape->GetHalfOfWidth(), GetY() - shape->GetHalfOfHeight());
	
	GameObject::Draw();
}
void Neighbor::HandleCollisionWithTarget(GameObject* target){
	
	if(shape->IsColliding()){
		Move(-velocity.x/2, -velocity.y/2);
	}
}