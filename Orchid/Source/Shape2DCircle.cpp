#include "Shape2DCircle.h"
#include "Shape2DRect.h"
Shape2DCircle::Shape2DCircle(){
	Shape2DCircle(4, 4, 2);
}
Shape2DCircle::Shape2DCircle( int x,  int y,  int diameter){
	SetX(x);
	SetY(y);
	SetDiameter(diameter);
}
Shape2DCircle::~Shape2DCircle(){
	
}
void Shape2DCircle::SetDiameter( int diameter){
	this->diameter = diameter;
	radius = diameter/2;
}
 int Shape2DCircle::GetDiameter(){
	return diameter;
}
void Shape2DCircle::SetRadius( int radius){
	this->radius = radius;
	diameter = radius*2;
}
 int Shape2DCircle::GetRadius(){
	return radius;
}
void Shape2DCircle::DrawShape(){
	Shape2D::DrawShape();
	if(solid)
		GraphicsCore::DrawFilledCircle(x, y, radius, r, g, b);
	else
		GraphicsCore::DrawCircle(x, y, radius, r, g, b, 2);
}
SHAPE_TYPE Shape2DCircle::GetType(){
	return CIRCLE;
}
bool Shape2DCircle::DetectCollision(Shape2D* target){
	float difX = 0;
	float difY = 0;

	float distance = 0;
	int combinedRadii = 0;
	
	

	switch(target->GetType()){
		case NO_SHAPE:
			
			break;
		case CIRCLE:
			difX = x - target->GetX();
			difY = y - target->GetY();			
			distance = sqrt(pow(difX, 2) + pow(difY, 2));
			combinedRadii = radius + ((Shape2DCircle*)target)->GetRadius();
			if(distance < combinedRadii){
				SetCollision(true);
				return true;
			}
			break;
		case RECTANGLE:

			if( x + radius > ((Shape2DRect*)target)->GetX() - ((Shape2DRect*)target)->GetHalfOfWidth() &&
				x - radius < ((Shape2DRect*)target)->GetX() + ((Shape2DRect*)target)->GetHalfOfWidth() &&
				y + radius > ((Shape2DRect*)target)->GetY() - ((Shape2DRect*)target)->GetHalfOfHeight() &&
				y - radius < ((Shape2DRect*)target)->GetY() + ((Shape2DRect*)target)->GetHalfOfHeight())
			{
				SetCollision(true);
				return true;
			}
			break;
	}
	return false;
	
}

int Shape2DCircle::GetW(){
	return diameter;
}
int Shape2DCircle::GetH(){
	return diameter;
}
int Shape2DCircle::GetHalfOfWidth(){
    return radius;
}
int Shape2DCircle::GetHalfOfHeight(){
    return radius;
}