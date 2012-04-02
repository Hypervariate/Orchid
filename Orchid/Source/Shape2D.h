#ifndef SHAPE2D_H
#define SHAPE2D_H


enum SHAPE_TYPE{
	NO_SHAPE = 0,
	CIRCLE,
	RECTANGLE
};

class Shape2D{
protected:
	unsigned int x, y, w, h;
	unsigned char r, g, b;
	bool solid;
public:
    Shape2D();
    ~Shape2D();

	virtual void SetX(unsigned int x);
	virtual void SetY(unsigned int y);
	virtual void SetW(unsigned int w);
	virtual void SetH(unsigned int h);
	virtual unsigned int GetX();
	virtual unsigned int GetY();
	virtual unsigned int GetW();
	virtual unsigned int GetH();

	void SetAppearance(unsigned char r, unsigned char g, unsigned char b, bool solid);

	virtual void DrawShape();

    virtual bool AreCoordinatesWithinShape(unsigned int x, unsigned int y);
   /* virtual bool IsShapeWithin(Shape2D* shape);
    static bool AreShapesIntersecting(Shape2D* s1, Shape2D* s2);*/

	virtual SHAPE_TYPE GetType();
	virtual bool DetectCollision(Shape2D* target);


protected:
	bool colliding;
};

#endif