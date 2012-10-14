//void Particle_Emitter::spawn(int col_x, int col_y, int col_w, int col_h, char* file, int velocity_x, int velocity_y, int spread, int life, int damage, float gravityX, float gravityY){
//	
//	
//	if(spread < 1) spread = 1;
//
//	Entity::EntityList.push_back(new Particle(col_x,col_y,col_w,col_h));
//	
//	Entity::EntityList.at(Entity::EntityList.size()-1)->life = life;
//	Entity::EntityList.at(Entity::EntityList.size()-1)->weight = 1;
//	Entity::EntityList.at(Entity::EntityList.size()-1)->sprite.load_image( file );
//	Entity::EntityList.at(Entity::EntityList.size()-1)->sprite.SetRects(0,0,col_w,col_h,  col_x,col_y,col_w,col_h);
//	
//	//temp fix to origin bug
//	Entity::EntityList.at(Entity::EntityList.size()-1)->camera.x = WIDTH;
//	Entity::EntityList.at(Entity::EntityList.size()-1)->camera.y = HEIGHT;
//
//	Entity::EntityList.at(Entity::EntityList.size()-1)->EntityListIndex = Entity::EntityList.size()-1;
//	
//	
//	Vec2 temp;
//	temp.x = rand()%spread;	
//	temp.y = rand()%spread;
//
//	if(rand()%2) temp.x = -temp.x;
//	if(rand()%2) temp.y = -temp.y;
//
//	Entity::EntityList.at(Entity::EntityList.size()-1)->velocity.x = velocity_x + temp.x;
//	Entity::EntityList.at(Entity::EntityList.size()-1)->velocity.y = velocity_y + temp.y;
//	Entity::EntityList.at(Entity::EntityList.size()-1)->gravity.x = gravityX;
//	Entity::EntityList.at(Entity::EntityList.size()-1)->gravity.y = gravityY;
//
//	Entity::EntityList.at(Entity::EntityList.size()-1)->collide_with_player = true;
//	Entity::EntityList.at(Entity::EntityList.size()-1)->damage = damage;
//	
//	
//}
#include "GameObjectEmitter.h"

GameObjectEmitter::GameObjectEmitter(){

}
GameObjectEmitter::~GameObjectEmitter(){

}
