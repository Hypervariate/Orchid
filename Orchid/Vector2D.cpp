#include "Vector2D.h"

Vector2D::Vector2D(){
	Vector2D(0,0);
}
Vector2D::Vector2D(int x, int y){
	this->X = x;
	this->Y = y;
}
Vector2D::~Vector2D(){

}
void Vector2D::Set(int x, int y){
	this->X = x;
	this->Y = y;
}
void Vector2D::SetX(int x){
	this->X = x;
}
void Vector2D::SetY(int y){
	this->Y = y;
}
int Vector2D::GetX(){
	return X;
}
int Vector2D::GetY(){
	return Y;
}

