#include "Witch.h"

Witch::Witch(int x, int y) : GameObject(x, y){
	/*delete shape;
	shape = NULL;
	shape = new Shape2DCircle(x,y,50);*/
	
	shape->SetW(40);
	shape->SetH(40);
    baseInertia.x = baseInertia.y = 2;
	animation = Animation::FactoryAnimation("Librarian_Idle");
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