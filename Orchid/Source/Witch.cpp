#include "Witch.h"

Witch::Witch(){
	delete shape;
	shape = NULL;
	shape = new Shape2DCircle(50,50,50);
}
Witch::~Witch(){

}
