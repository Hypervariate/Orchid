#include "Shape2DCircle.h"

Shape2DCircle::Shape2DCircle(){
	Shape2DCircle(4, 4, 2);
}
Shape2DCircle::Shape2DCircle(unsigned int x, unsigned int y, unsigned int diameter){
	SetX(x);
	SetY(y);
	SetDiameter(diameter);
}
Shape2DCircle::~Shape2DCircle(){
	
}

void Shape2DCircle::SetDiameter(unsigned int diameter){
	this->diameter = diameter;
	radius = diameter/2;
}
unsigned int Shape2DCircle::GetDiameter(){
	return diameter;
}
void Shape2DCircle::SetRadius(unsigned int radius){
	this->radius = radius;
	diameter = radius*2;
}
unsigned int Shape2DCircle::GetRadius(){
	return radius;
}
bool Shape2DCircle::AreCoordinatesWithinShape(unsigned int x, unsigned int y){
	return false;
}
bool Shape2DCircle::IsShape2DCircleWithin(Shape2DCircle* circle){
	return false;
}
bool Shape2DCircle::AreShape2DCirclesIntersecting(Shape2DCircle* c1, Shape2DCircle* c2){
	//dx=ax-bx
	int dx = c1->GetX() - c2->GetX();

	//dy=ay-by
	int dy = c1->GetY() - c2->GetY();

	//r=ar+br
	unsigned int r = c1->GetRadius() + c2->GetRadius();

	//collision=r*r>dx*dx+dy*dy
	if(r * r > dx * dx + dy * dy)
		return true;
	else
		return false;
}
void Shape2DCircle::DrawShape(){
	if(solid)
		GraphicsCore::DrawFilledCircle(x, y, radius, r, g, b);
	else
		GraphicsCore::DrawCircle(x, y, radius, r, g, b, 2);
}