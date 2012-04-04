#ifndef UTILITYRECTANGLE_H_
#define UTILITYRECTANGLE_H_


#include "GameObject.h"
#include "Shape2DRect.h"

class UtilityRectangle : public GameObject{

public:
	UtilityRectangle(int x = 100, int y = 100, int w = 50, int h = 50);
	~UtilityRectangle();

	void Update();
	void Draw();

private:
	

	

};

#endif