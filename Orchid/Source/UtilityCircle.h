#ifndef UTILITYCIRCLE_H_
#define UTILITYCIRCLE_H_


#include "GameObject.h"
#include "Shape2DCircle.h"

class UtilityCircle : public GameObject{

public:
	UtilityCircle(int x = 100, int y = 100, int r = 50);
	~UtilityCircle();

	void Update();
	void Draw();

private:
	

	

};

#endif