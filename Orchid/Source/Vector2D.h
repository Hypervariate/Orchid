#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D{

public:
	Vector2D();
	Vector2D(int x, int y);
	~Vector2D();

	void Set(int x, int y);

	int x;
	int y;

};

#endif