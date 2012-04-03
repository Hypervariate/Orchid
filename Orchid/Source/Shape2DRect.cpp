#include "Shape2DRect.h"
#include "Shape2DCircle.h"

Shape2DRect::Shape2DRect(){
	Shape2DRect(0,0,0,0);
}
Shape2DRect::Shape2DRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	halfOfWidth = w/2;
	halfOfHeight = h/2;
}
Shape2DRect::~Shape2DRect(){

}
void Shape2DRect::SetW(unsigned int w){
	this->w = w;
	halfOfWidth = w/2;
}
void Shape2DRect::SetH(unsigned int h){
	this->h = h;
	halfOfHeight = h/2;
}
unsigned int Shape2DRect::GetHalfOfWidth(){
    return halfOfWidth;
}
unsigned int Shape2DRect::GetHalfOfHeight(){
    return halfOfHeight;
}
void Shape2DRect::DrawShape(){
    Shape2D::DrawShape();
	if(solid)
		GraphicsCore::DrawFilledRectangle(x - halfOfWidth, y - halfOfHeight, x + halfOfWidth, y + halfOfHeight, r, g, b);
	else
		GraphicsCore::DrawRectangle(x - halfOfWidth, y - halfOfHeight, x + halfOfWidth, y + halfOfHeight, r, g, b, 2);
	
}
SHAPE_TYPE Shape2DRect::GetType(){
	return RECTANGLE;
}
bool Shape2DRect::DetectCollision(Shape2D* target){
	ClearCollisions();
	float difX = 0;
	float difY = 0;
	float distance = 0;
	switch(target->GetType()){
		case NO_SHAPE:
			
			break;
		case CIRCLE:
			difX = x - target->GetX();
			difY = y - target->GetY();
			distance = sqrt(pow(difX, 2) + pow(difY, 2));
			if(distance < w + ((Shape2DCircle*)target)->GetRadius() || distance < h + ((Shape2DCircle*)target)->GetRadius()){
				AddCollision(target);
				return true;
			}
			break;
		case RECTANGLE:
			if( x + halfOfWidth > ((Shape2DRect*)target)->GetX() - ((Shape2DRect*)target)->GetHalfOfWidth() &&
				x - halfOfWidth < ((Shape2DRect*)target)->GetX() + ((Shape2DRect*)target)->GetHalfOfWidth() &&
				y + halfOfHeight > ((Shape2DRect*)target)->GetY() - ((Shape2DRect*)target)->GetHalfOfHeight() &&
				y - halfOfHeight < ((Shape2DRect*)target)->GetY() + ((Shape2DRect*)target)->GetHalfOfHeight())
			{
				AddCollision(target);
				return true;
			}
			break;
	}
	
	
	

	return false;
}