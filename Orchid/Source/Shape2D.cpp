#include "Shape2D.h"
Shape2D::Shape2D(){
	r = 0;
	g = 175;
	b = 0;
	solid = false;
	colliding = false;
}
Shape2D::~Shape2D(){}
void Shape2D::SetX(unsigned int x){
	this->x = x;
}
void Shape2D::SetY(unsigned int y){
	this->y = y;
}
void Shape2D::SetW(unsigned int w){
	this->w = w;
}
void Shape2D::SetH(unsigned int h){
	this->h = h;
}
unsigned int Shape2D::GetX(){
	return x;
}
unsigned int Shape2D::GetY(){
	return y;
}
unsigned int Shape2D::GetW(){
	return w;
}
unsigned int Shape2D::GetH(){
	return h;
}
void Shape2D::DrawShape(){
	if(colliding){
		r = 255;
		g = 0;
		b = 0;
	}
	else{
		r = 0;
		g = 175;
		b = 0;
	}
}
bool Shape2D::AreCoordinatesWithinShape(unsigned int x, unsigned int y){
    return false;
}
void Shape2D::SetAppearance(unsigned char r, unsigned char g, unsigned char b, bool solid){
	this->r = r;
	this->g = g;
	this->b = b;
	this->solid = solid;
}
SHAPE_TYPE Shape2D::GetType(){
	return NO_SHAPE;
}
bool Shape2D::DetectCollision(Shape2D* target){
	return false;
}