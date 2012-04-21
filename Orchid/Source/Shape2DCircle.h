#ifndef SHAPE2DCIRCLE_H_
#define SHAPE2DCIRCLE_H_

#include "Shape2D.h"
#include "GraphicsCore.h"
#include <math.h>

class Shape2DCircle : public Shape2D{
private:
	unsigned int diameter;
	unsigned int radius;

public:
	Shape2DCircle();
	Shape2DCircle(unsigned int x, unsigned int y, unsigned int diameter);
	~Shape2DCircle();

	void SetDiameter(unsigned int diameter);
	unsigned int GetDiameter();

	void SetRadius(unsigned int radius);
	unsigned int GetRadius();


    void DrawShape();
	SHAPE_TYPE GetType();

	bool DetectCollision(Shape2D* target);


	virtual unsigned int GetW();
	virtual unsigned int GetH();
	virtual unsigned int GetHalfOfWidth();
    virtual unsigned int GetHalfOfHeight();
	
};

#endif