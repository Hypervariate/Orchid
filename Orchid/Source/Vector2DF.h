#ifndef VECTOR2DF_H
#define VECTOR2DF_H

class Vector2DF{

public:
	Vector2DF();
	Vector2DF(float x, float y);
	~Vector2DF();

	void Set(float x, float y);
	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();

private:
	float X;
	float Y;

};

#endif