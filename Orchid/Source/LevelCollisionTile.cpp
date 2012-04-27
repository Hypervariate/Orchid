#include "LevelCollisionTile.h"

LevelCollisionTile::LevelCollisionTile(int x, int y, int w, int h) : GameObject(x, y){
	position.Set(x, y);
	shape->SetW(w);
	shape->SetH(h);
}
LevelCollisionTile::~LevelCollisionTile(){

}
void LevelCollisionTile::Update(){
	GameObject::Update();
}
void LevelCollisionTile::Draw(){
	GameObject::Draw();

}
void LevelCollisionTile::HandleCollisionWithTarget(GameObject* target){
	


}