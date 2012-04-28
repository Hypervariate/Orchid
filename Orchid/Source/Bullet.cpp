#include "Bullet.h"

Bullet::Bullet(int x, int y, int r, float vx, float vy) : GameObject(x, y){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(x,y,r);
	position.x = x;
	position.y = y;
	Move(vx, vy);
	lifeSpan.Set(50);
	lifeSpan.Start();
	
}
Bullet::~Bullet(){

}
void Bullet::Update(){
	
	if(lifeSpan.Arrived())
		life = 0;

	GameObject::Update();
}
void Bullet::Draw(){
	GameObject::Draw();

}