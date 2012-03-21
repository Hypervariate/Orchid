#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D{

public:
	Vector2D();
	Vector2D(int x, int y);
	~Vector2D();

	void Set(int x, int y);
	void SetX(int x);
	void SetY(int y);

	int GetX();
	int GetY();

private:
	int X;
	int Y;

};

#endif