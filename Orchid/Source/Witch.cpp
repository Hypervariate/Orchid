#include "Witch.h"

Witch::Witch(){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(50,50,50);
	
	Animation::LoadAnimation("librarian_idle", &animation);
	animation.PlayAnimation();
}
Witch::~Witch(){

}
void Witch::Update(){
	GameObject::Update();
}
void Witch::Draw(){
	GraphicsCore::BlitImage(animation.UpdateAnimation(0.01), position.x, position.y);
	GameObject::Draw();
}