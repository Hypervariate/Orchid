#include "Vector2DF.h"

Vector2DF::Vector2DF(){
	Vector2DF(0,0);
}
Vector2DF::Vector2DF(float x, float y){
	this->X = x;
	this->Y = y;
}
Vector2DF::~Vector2DF(){

}
void Vector2DF::Set(float x, float y){
	this->X = x;
	this->Y = y;
}
void Vector2DF::SetX(float x){
	this->X = x;
}
void Vector2DF::SetY(float y){
	this->Y = y;
}
float Vector2DF::GetX(){
	return X;
}
float Vector2DF::GetY(){
	return Y;
}

