#include "Witch.h"

Witch::Witch(){
	shape.SetX(50);
	shape.SetY(50);
	shape.SetW(50);
	shape.SetH(50);	
	
	speed = 2;
}
Witch::~Witch(){

}
void Witch::Draw(){
	shape.DrawShape();
}
void Witch::MoveUp(){
	shape.SetY(shape.GetY() - speed);
}
void Witch::MoveDown(){
	shape.SetY(shape.GetY() + speed);
}
void Witch::MoveLeft(){
	shape.SetX(shape.GetX() - speed);
}
void Witch::MoveRight(){
	shape.SetX(shape.GetX() + speed);
}