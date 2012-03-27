#ifndef VECTOR2DF_H
#define VECTOR2DF_H

class Vector2DF{

public:
	Vector2DF();
	Vector2DF(float x, float y);
	~Vector2DF();

	void Set(float x, float y);

	float x;
	float y;

};

#endif