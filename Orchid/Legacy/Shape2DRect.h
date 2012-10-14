#ifndef SHAPE2DRECT_H_
#define SHAPE2DRECT_H_


#include "Shape2D.h"
#include "GraphicsCore.h"

class Shape2DRect : public Shape2D{
private:
	
	 int halfOfWidth;
	 int halfOfHeight;
	
public:
	Shape2DRect();
	Shape2DRect( int x,  int y,  int w,  int h);
	~Shape2DRect();

	
	void SetW(int w);
	void SetH(int h);


    int GetHalfOfWidth();
    int GetHalfOfHeight();


	virtual void DrawShape();
	
	virtual SHAPE_TYPE GetType();
	bool DetectCollision(Shape2D* target);
};

#endif