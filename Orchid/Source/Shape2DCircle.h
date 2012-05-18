#ifndef SHAPE2DCIRCLE_H_
#define SHAPE2DCIRCLE_H_

#include "Shape2D.h"
#include "GraphicsCore.h"
#include <math.h>

class Shape2DCircle : public Shape2D{
private:
	 int diameter;
	 int radius;

public:
	Shape2DCircle();
	Shape2DCircle( int x,  int y,  int diameter);
	~Shape2DCircle();

	void SetDiameter( int diameter);
	 int GetDiameter();

	void SetRadius( int radius);
	 int GetRadius();


    void DrawShape();
	SHAPE_TYPE GetType();

	bool DetectCollision(Shape2D* target);


	int GetW();
	int GetH();
	int GetHalfOfWidth();
    int GetHalfOfHeight();
	
};

#endif