#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <vector>
using namespace std;

enum SHAPE_TYPE{
	NO_SHAPE = 0,
	CIRCLE,
	RECTANGLE
};

class Shape2D{
protected:
	int x, y;
	 int w, h, halfOfWidth, halfOfHeight;
	 char r, g, b;
	bool solid;
public:
    Shape2D();
    ~Shape2D();

	virtual void SetX(int x);				//X coordinate of shape (center)
	virtual void SetY(int y);				//Y coordinate of shape (center)
	virtual void SetW( int w);		//width of shape
	virtual void SetH( int h);		//height of shape
	virtual int GetX();						//X coordinate of shape (center)
	virtual int GetY();						//Y coordinate of shape (center)
	virtual int GetW();			//width of shape
	virtual int GetH();			//height of shape
	virtual int GetHalfOfWidth();	//use this instead of "GetW() / 2"
    virtual int GetHalfOfHeight();	//use this instead of "GetH() / 2"

	void SetCollision(bool isColliding);	//store the result of collision detection
	bool IsColliding();						//is this shape colliding with another?

	//color and fill the shape
	void SetAppearance( char r,  char g,  char b, bool solid);

	//let the shape draw itself
	virtual void DrawShape();

	//return the enumerated type of shape any subclass of Shape2D might be
	//this is used in the collision detection routines so that different shapes 
	//can collide with one another
	virtual SHAPE_TYPE GetType();

	//detect collision with another shape which need not be of the same type
	virtual bool DetectCollision(Shape2D* target);


protected:
	bool colliding;
	
};

#endif