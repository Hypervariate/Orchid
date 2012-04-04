#include "UtilityCircle.h"

UtilityCircle::UtilityCircle(int x, int y, int r){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(x,y,r);
}
UtilityCircle::~UtilityCircle(){

}
void UtilityCircle::Update(){
	GameObject::Update();
}
void UtilityCircle::Draw(){
	GameObject::Draw();

}