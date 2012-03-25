#include "Shape2DRect.h"

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
bool Shape2DRect::AreCoordinatesWithinShape(unsigned int x, unsigned int y){
	if(x >= this->x - halfOfWidth)	//if x is > left bound
		if(x <= this->x + halfOfWidth)	//if x < right bound
			if(y >= this->y - halfOfHeight)	//if y > upper bound
				if(y <= this->y + halfOfHeight)	//if y < lower bound
					return true;	//yes, within rect

	return false;	//otherwise, no
}
bool Shape2DRect::IsShape2DRectWithin(Shape2DRect* rect){
	//is this rectangle within the rectangle passed to it?
	if(rect->AreCoordinatesWithinShape(x - halfOfWidth, y - halfOfHeight))	//rect top left within this
		return true;
	if(rect->AreCoordinatesWithinShape(x - halfOfWidth, y + halfOfHeight))	//rect top right within this
		return true;
	if(rect->AreCoordinatesWithinShape(x + halfOfWidth, y - halfOfHeight))	//rect bottom left within this
		return true;
	if(rect->AreCoordinatesWithinShape(x + halfOfWidth, y + halfOfHeight))	//rect bottom right within this
		return true;
	
	return false;
}
bool Shape2DRect::AreShape2DRectsIntersecting(Shape2DRect* rect1, Shape2DRect* rect2){
	
	//SAT collision
	int a = rect1->GetX() - rect1->GetHalfOfWidth();
	int b = rect1->GetX() + rect1->GetHalfOfWidth();

	int c = rect2->GetX() - rect2->GetHalfOfWidth();
	int d = rect2->GetX() + rect2->GetHalfOfWidth();

	int e = rect1->GetY() - rect1->GetHalfOfHeight();
	int f = rect1->GetY() + rect1->GetHalfOfHeight();

	int g = rect2->GetY() - rect2->GetHalfOfHeight();
	int h = rect2->GetY() + rect2->GetHalfOfHeight();

	if( ((a < c && c < b) || (a < d && d < b)) && ((e < g && g < f) || (e < h && h < f)) )
		return true;

	if(rect1->IsShape2DRectWithin(rect2) || rect2->IsShape2DRectWithin(rect1))
		return true;

	return false;
}
void Shape2DRect::DrawShape(){
    if(solid)
		GraphicsCore::DrawFilledRectangle(x - halfOfWidth, y - halfOfHeight, x + halfOfWidth, y + halfOfHeight, r, g, b);
	else
		GraphicsCore::DrawRectangle(x - halfOfWidth, y - halfOfHeight, x + halfOfWidth, y + halfOfHeight, r, g, b, 2);
}