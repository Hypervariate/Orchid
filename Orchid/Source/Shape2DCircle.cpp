#include "Shape2DCircle.h"
#include "Shape2DRect.h"
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
	ClearCollisions();
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
				AddCollision(target);
				return true;
			}
			break;
		case RECTANGLE:

			/*GraphicsCore::PrintToDisplay(x, x, y - 48, "Acknowledge", 0, 255, 0);
			GraphicsCore::PrintToDisplay(y, x, y - 36, "Acknowledge", 0, 255, 0);
			GraphicsCore::PrintToDisplay(radius, x, y - 12, "Acknowledge", 0, 255, 0);*/

			if( x + radius > ((Shape2DRect*)target)->GetX() - ((Shape2DRect*)target)->GetHalfOfWidth() &&
				x - radius < ((Shape2DRect*)target)->GetX() + ((Shape2DRect*)target)->GetHalfOfWidth() &&
				y + radius > ((Shape2DRect*)target)->GetY() - ((Shape2DRect*)target)->GetHalfOfHeight() &&
				y - radius < ((Shape2DRect*)target)->GetY() + ((Shape2DRect*)target)->GetHalfOfHeight())
			{
				AddCollision(target);
				return true;
			}
			break;
	}

	return false;
	
}