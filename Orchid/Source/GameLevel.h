#ifndef GAMELEVEL_H_
#define GAMELEVEL_H_

#include "GraphicsCore.h"
#include "mappy_A5.h"
#include "Vector2DF.h"

class GameLevel{
public:
	GameLevel();
	~GameLevel();

	bool Load(char* fileName);
	void Unload();
	void DrawBackground();
	void DrawForeground();

private:
	Vector2DF scrollingOffset;

};


#endif