#include "UtilityCircle.h"

UtilityCircle::UtilityCircle(){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(50,50,50);
}
UtilityCircle::~UtilityCircle(){

}
void UtilityCircle::Update(){
	GameObject::Update();
}
void UtilityCircle::Draw(){
	GameObject::Draw();

}