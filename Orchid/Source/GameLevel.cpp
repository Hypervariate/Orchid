#include "GameLevel.h"

GameLevel::GameLevel(){
	

}
GameLevel::~GameLevel(){
	Unload();
}
bool GameLevel::Load(char* levelName, GameObject* cameraTarget){

	char path[MAX_PATH_LENGTH];

	for(int i = 0; i < MAX_PATH_LENGTH; i++)
		path[i] = '\0';

	strcat(path, LEVEL_DIRECTORY);
	strcat(path, levelName);
	strcat(path, LEVEL_EXTENSION);

	bool successful = false;
	if(!MapLoad(path, 1))
		successful = true;
	
	layerCount = 0;
	while(MapChangeLayer(layerCount) != -1)
		layerCount++;
	MapChangeLayer(0);


	this->cameraTarget = cameraTarget;

	GraphicsCore::SetMapDimensions(mapwidth, mapheight);
	GraphicsCore::SetMapTileDimensions(mapblockwidth, mapblockheight);

	return successful;
		
	
	
}
void GameLevel::DrawBackground(){
	
	MapDrawBG(GraphicsCore::GetMapScrollingOffsetX(), GraphicsCore::GetMapScrollingOffsetY(), 0, 0, WIDTH, HEIGHT);
}
void GameLevel::DrawForeground(){
	//MapDrawFG(scrollingOffset.x, scrollingOffset.y, 0, 0, WIDTH, HEIGHT);
}
void GameLevel::Unload(){
	MapFreeMem();
}
void GameLevel::Update(){
	//update the map scroll position
	GraphicsCore::SetMapScrollingOffsetX(cameraTarget->GetX() + cameraTarget->GetHalfOfWidth());
	GraphicsCore::SetMapScrollingOffsetX( GraphicsCore::GetMapScrollingOffsetX() - WIDTH/2);

	GraphicsCore::SetMapScrollingOffsetY(cameraTarget->GetY() + cameraTarget->GetHalfOfHeight());
	GraphicsCore::SetMapScrollingOffsetY( GraphicsCore::GetMapScrollingOffsetY() - HEIGHT/2);

	//update animations
	MapUpdateAnims();
}
unsigned long GameLevel::GetTileData(int blockX, int blockY, BLOCK_FIELD field, int layer){
	if(layer < 0 || layer >= layerCount)
		return 0;

	MapChangeLayer(layer);

	BLKSTR * myblock;
	myblock = MapGetBlock(blockX, blockY);
	switch(field){
		case USER1:
			return myblock->user1;
			break;
		case USER2:
			return myblock->user2;
			break;
		case USER3:
			return myblock->user3;
			break;
		case USER4:
			return myblock->user4;
			break;
		case USER5:
			return myblock->user5;
			break;
		case USER6:
			return myblock->user6;
			break;
		case USER7:
			return myblock->user7;
			break;
		case TL:
			return myblock->tl;
			break;
		case TR:
			return myblock->tr;
			break;
		case BL:
			return myblock->bl;
			break;
		case BR:
			return myblock->br;
			break;
		case TRIGGER:
			return myblock->trigger;
			break;
		case UNUSED1:
			return myblock->unused1;
			break;
		case UNUSED2:
			return myblock->unused2;
			break;
		case UNUSED3:
			return myblock->unused3;
			break;
		default:
			return -1;
			break;
	}
	delete myblock;
}
