#include "GameObject.h"

#include "UtilityCircle.h"
#include "UtilityRectangle.h"
#include "Witch.h"

std::list<GameObject *> GameObject::objects;
std::list<GameObject *>::iterator GameObject::iter1;
std::list<GameObject *>::iterator GameObject::iter2;


GameObject::GameObject(int x, int y){
	shape = new Shape2DRect();

	position.Set(x,y);
	velocity.Set(0,0);

	shape->SetX(position.x);
	shape->SetY(position.y);
	shape->SetW(50);
	shape->SetH(50);	
		
	maxSpeed = 4.0;
	minSpeed = 0.8;

	baseInertia.x = baseInertia.y = 3;
	drag.x = drag.y = 0.85f;	
	

	inertia.x = baseInertia.x;
	inertia.y = baseInertia.y;

	moveUp = moveDown = moveLeft = moveRight = false;

	life = 100;
}
GameObject::~GameObject(){
	delete shape;
}
void GameObject::Destroy(){
	delete this;
	objects.remove(this);
}
void GameObject::DestroyAll(){
	while(!objects.empty()){
		delete objects.front();
		objects.pop_front();
	}
		
}
void GameObject::UpdateAll(){
	//update all game objects
	for(iter1 = objects.begin(); iter1 != objects.end(); ++iter1){
		(*iter1)->Update();
		iter2 = iter1;
		iter2++;
		for(; iter2 != objects.end(); ++iter2){
			(*iter1)->DetectCollision((*iter2));
			(*iter2)->DetectCollision((*iter1));
		}
		(*iter1)->Draw();
		
	}
	GraphicsCore::PrintToDisplay(objects.size(), 0, 64, "Arcade");
}
void GameObject::Update(){
	if(life <= 0){
		Destroy();
		return;
	}
	if(moveLeft) Move(-1,0);
	if(moveRight) Move(1,0);	
	if(!moveLeft && !moveRight) inertia.x = 0;

	if(moveUp) Move(0,-1);
	if(moveDown) Move(0,1);
	if(!moveUp && !moveDown) inertia.y = 0;
	
	velocity.x = min(velocity.x, maxSpeed);
	velocity.x = max(velocity.x, -maxSpeed);

	velocity.y = min(velocity.y, maxSpeed);
	velocity.y = max(velocity.y, -maxSpeed);

	position.x += velocity.x;
	position.y += velocity.y;

	shape->SetX(position.x);
	shape->SetY(position.y);

	if(!inertia.x){
		velocity.x *= drag.x;
		
		if(velocity.x > 0 && velocity.x < minSpeed)
			velocity.x = 0;
		else if(velocity.x < 0 && velocity.x > -minSpeed)
			velocity.x = 0;
	}

	if(!inertia.y){
		velocity.y *= drag.y;
		
		if(velocity.y > 0 && velocity.y < minSpeed)
			velocity.y = 0;
		else if(velocity.y < 0 && velocity.y > -minSpeed)
			velocity.y = 0;
	}



}
int GameObject::GetX(){
	return shape->GetX();
}
int GameObject::GetY(){
	return shape->GetY();
}
unsigned int GameObject::GetW(){
	return shape->GetW();
}
unsigned int GameObject::GetH(){
	return shape->GetH();
}
unsigned int GameObject::GetHalfOfWidth(){
	return shape->GetHalfOfWidth();
}
unsigned int GameObject::GetHalfOfHeight(){
	return shape->GetHalfOfHeight();
}
void GameObject::Draw(){
	shape->DrawShape();
}
void GameObject::Move(float dirX, float dirY){
	inertia.Set(baseInertia.x, baseInertia.y);
	if(dirX) velocity.x = dirX * inertia.x;
	if(dirY) velocity.y = dirY * inertia.y;
}
void GameObject::StartMovingUp(){
	moveUp = true;
}
void GameObject::StartMovingDown(){
	moveDown = true;
}
void GameObject::StartMovingLeft(){
	moveLeft = true;
}
void GameObject::StartMovingRight(){
	moveRight = true;
}
void GameObject::StopMovingUp(){
	moveUp = false;
	if(velocity.y < 0 && !moveDown) inertia.y = 0;
}
void GameObject::StopMovingDown(){
	moveDown = false;
	if(velocity.y > 0 && !moveUp) inertia.y = 0;
}
void GameObject::StopMovingLeft(){
	moveLeft = false;
	if(velocity.x < 0 && !moveRight) inertia.x = 0;
}
void GameObject::StopMovingRight(){
	moveRight = false;
	if(velocity.x > 0 && !moveLeft) inertia.x = 0;
}
void GameObject::ResumeMovement(){
	if(moveLeft) StartMovingLeft();
	if(moveRight) StartMovingRight();
	if(moveUp) StartMovingUp();
	if(moveDown) StartMovingDown();
}
bool GameObject::DetectCollision(GameObject* target){
	return shape->DetectCollision(target->GetShape());
}
Shape2D* GameObject::GetShape(){
	return shape;
}
void GameObject::Spawn(string type, int x, int y){
	if(type == "UtilityCircle"){
		UtilityCircle* o = new UtilityCircle(x, y);
		AddToWorld(o);
	}
	else if(type == "UtilityRectangle"){
		UtilityRectangle* o = new UtilityRectangle(x, y);
		AddToWorld(o);	
	}
	else if(type == "Witch"){
		Witch* o = new Witch(x, y);
		AddToWorld(o);	
	}
}
void GameObject::AddToWorld(GameObject* g){
	objects.push_back(g);	
}
//return an entity pointer
GameObject* GameObject::GetGameObject(int number){
	
		
	int n = 0;
	iter1 = objects.begin();
	if(number < 0) {
		iter1 = objects.end();
	}
    while(iter1 != objects.end()){
       if(n == number) return (*iter1);
	   else{ 
		   n++;
		   iter1++;
	   }
    }
	//if not found, return last item in list
	iter1--;
	return (*iter1);
}