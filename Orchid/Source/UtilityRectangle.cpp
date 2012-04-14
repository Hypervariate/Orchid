#include "UtilityRectangle.h"

UtilityRectangle::UtilityRectangle(int x, int y, int w, int h) : GameObject(x, y){
	position.Set(x, y);
	shape->SetW(w);
	shape->SetH(h);
}
UtilityRectangle::~UtilityRectangle(){

}
void UtilityRectangle::Update(){
	GameObject::Update();
}
void UtilityRectangle::Draw(){
	GameObject::Draw();

}