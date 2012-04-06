#ifndef GAMELEVEL_H_
#define GAMELEVEL_H_

#include "GraphicsCore.h"
#include "GameObject.h"
#include "mappy_A5.h"
#include "Vector2DF.h"

#define LEVEL_DIRECTORY "Data/Maps/"
#define LEVEL_EXTENSION ".fmp"

enum BLOCK_FIELD {
	USER1 = 1,
	USER2,
	USER3,
	USER4,
	USER5,
	USER6,
	USER7,
	TL,
	TR,
	BL,
	BR,
	TRIGGER,
	UNUSED1,
	UNUSED2,
	UNUSED3
};

class GameLevel{
public:
	GameLevel();
	~GameLevel();

	bool Load(char* levelName, GameObject* cameraTarget);
	void Unload();
	void DrawBackground();
	void DrawForeground();
	void Update();
	unsigned long GetTileData(int blockx, int blocky, BLOCK_FIELD field, int layer = 0);
	int collided_tl(int x, int y);
	

private:
	
	int layerCount;
	GameObject* cameraTarget;
	
};


#endif