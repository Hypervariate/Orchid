#include "Bullet.h"

Bullet::Bullet(int x, int y, float vx, float vy) : GameObject(x, y){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(x,y,25);
	position.x = x;
	position.y = y;
	baseInertia.x = baseInertia.y = 10;
	drag.x = drag.y = 1.0f;	
	Move(vx, vy);
	lifeSpan.Set(50);
	lifeSpan.Start();
	
}
Bullet::~Bullet(){

}
void Bullet::Update(){

	
	if((velocity.x == 0 && velocity.y == 0) || lifeSpan.Arrived())
		SetLife(0);

	GameObject::Update();
}
void Bullet::Draw(){
	GameObject::Draw();

}