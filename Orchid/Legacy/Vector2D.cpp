#include "Vector2D.h"

Vector2D::Vector2D(){
	Vector2D(0,0);
}
Vector2D::Vector2D(int x, int y){
	this->x = x;
	this->y = y;
}
Vector2D::~Vector2D(){

}
void Vector2D::Set(int x, int y){
	this->x = x;
	this->y = y;
}
