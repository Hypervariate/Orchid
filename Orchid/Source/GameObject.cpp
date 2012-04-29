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
float GameObject::GetVelocityX(){
	return velocity.x;
}
float GameObject::GetVelocityY(){
	return velocity.y;
}
void GameObject::Destroy(){	//does not work. must implement correctly
	objects.remove(this);
	delete this;
	
}
void GameObject::DestroyAll(){
	while(!objects.empty()){
		delete objects.front();
		objects.pop_front();
	}
		
}
void GameObject::UpdateAll(){
	for(iter1 = objects.begin(); iter1 != objects.end(); ++iter1){
		if((*iter1)->life <= 0){
			(*iter1)->Destroy();
			iter1 = objects.begin();			
		}
	}

	//reset collisions
	for(iter1 = objects.begin(); iter1 != objects.end(); ++iter1){
		(*iter1)->shape->SetCollision(false);
	}

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
void GameObject::MoveTo(int x, int y){
	if(x != position.x){
		position.x = x;
		shape->SetX(position.x);
	}
	if(y != position.y){
		position.y = y;
		shape->SetY(position.y);
	}
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
	bool collision = shape->DetectCollision(target->GetShape());
	if(collision)
		HandleCollisionWithTarget(target);

	return collision;
}
void GameObject::HandleCollisionWithTarget(GameObject* target){

    Vector2DF correction = Vector2DF(0,0);
    Vector2D direction = Vector2D(0,0);

    float x1 = GetX() + GetHalfOfWidth()  - (target->GetX() - target->GetHalfOfWidth());
    float y1 = GetY() + GetHalfOfHeight() - (target->GetY() - target->GetHalfOfHeight());

    float x2 = GetX() - GetHalfOfWidth();
    x2 -= (target->GetX() + target->GetHalfOfWidth());
    float y2 = GetY() - GetHalfOfHeight();
    y2 -= (target->GetY() + target->GetHalfOfHeight());

    if(x1 < 0) x1 *= -1;
    if(x2 < 0) x2 *= -1;
    if(y1 < 0) y1 *= -1;
    if(y2 < 0) y2 *= -1;

    // calculate displacement along X-axis
    if (x1 < x2)
    {
        correction.x = x1;
        direction.x = -1;    //left
    }
    else if (x1 > x2)
    {
        correction.x = x2;
        direction.x = 1; //right
    }

    // calculate displacement along Y-axis
    if (y1 < y2)
    {
        correction.y = y1;
        direction.y = -1; //up
    }
    else if (y1 > y2)
    {
        correction.y = y2;
        direction.y = 1; //down
    }


    float targetX = target->GetX();
    float targetY = target->GetY();


    if(direction.x < 0 && ABS(correction.x) < ABS(correction.y)){   //colliding with right side
        targetX -= correction.x * direction.x;
        target->MoveTo(targetX, target->GetY());
    }
    else if(direction.x > 0 && ABS(correction.x) < ABS(correction.y)){   //colliding with left side
        targetX -= correction.x * direction.x;
        target->MoveTo(targetX, target->GetY());
    }
    else if(direction.y < 0 && ABS(correction.x) > ABS(correction.y)){  //colliding with bottom side
        targetY -= correction.y * direction.y;
        target->MoveTo(target->GetX(), targetY);
    }
    else if(direction.y > 0 && ABS(correction.x) > ABS(correction.y)){  //colliding with top side
        targetY -= correction.y * direction.y;
        target->MoveTo(target->GetX(), targetY);
    }
}
Shape2D* GameObject::GetShape(){
	return shape;
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