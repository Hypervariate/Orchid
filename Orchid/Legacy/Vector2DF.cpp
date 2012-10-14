#include "Vector2DF.h"

Vector2DF::Vector2DF(){
	Vector2DF(0,0);
}
Vector2DF::Vector2DF(float x, float y){
	this->x = x;
	this->y = y;
}
Vector2DF::~Vector2DF(){

}
void Vector2DF::Set(float x, float y){
	this->x = x;
	this->y = y;
}