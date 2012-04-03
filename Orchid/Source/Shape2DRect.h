#ifndef SHAPE2DRECT_H_
#define SHAPE2DRECT_H_


#include "Shape2D.h"
#include "GraphicsCore.h"

class Shape2DRect : public Shape2D{
private:
	
	unsigned int halfOfWidth;
	unsigned int halfOfHeight;
	
public:
	Shape2DRect();
	Shape2DRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	~Shape2DRect();

	
	void SetW(unsigned int w);
	void SetH(unsigned int h);


    unsigned int GetHalfOfWidth();
    unsigned int GetHalfOfHeight();


	virtual void DrawShape();
	
	virtual SHAPE_TYPE GetType();
	bool DetectCollision(Shape2D* target);
};

#endif