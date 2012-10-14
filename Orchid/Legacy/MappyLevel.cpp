#include "MappyLevel.h"

MappyLevel::MappyLevel(){
	

}
MappyLevel::~MappyLevel(){
	Unload();
}
bool MappyLevel::Load(char* levelName, GameObject* cameraTarget){

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
void MappyLevel::DrawBackground(){
	
	MapDrawBG(GraphicsCore::GetMapScrollingOffsetX(), GraphicsCore::GetMapScrollingOffsetY(), 0, 0, WIDTH, HEIGHT);
}
void MappyLevel::DrawForeground(){
	//MapDrawFG(scrollingOffset.x, scrollingOffset.y, 0, 0, WIDTH, HEIGHT);
}
void MappyLevel::Unload(){
	MapFreeMem();
}
void MappyLevel::Update(){
	//deprecated code
	//breaks encapsulation so commented out

	////update the map scroll position
	//GraphicsCore::SetMapScrollingOffsetX(cameraTarget->GetX() + cameraTarget->GetHalfOfWidth());
	//GraphicsCore::SetMapScrollingOffsetX( GraphicsCore::GetMapScrollingOffsetX() - WIDTH/2);

	//GraphicsCore::SetMapScrollingOffsetY(cameraTarget->GetY() + cameraTarget->GetHalfOfHeight());
	//GraphicsCore::SetMapScrollingOffsetY( GraphicsCore::GetMapScrollingOffsetY() - HEIGHT/2);

	////update animations
	//MapUpdateAnims();

	//GameObject *g;
	////collide with all entities
	//for(GameObject::iter1 = GameObject::objects.begin(); GameObject::iter1 != GameObject::objects.end(); ++GameObject::iter1){
	//	g = (*GameObject::iter1);


	//	if(		collided_tl(g->GetX() - g->GetHalfOfWidth(), g->GetY() - g->GetHalfOfHeight())	//top-left corner
	//		||	collided_tl(g->GetX() + g->GetHalfOfWidth(), g->GetY() - g->GetHalfOfHeight())	//top-right corner
	//		||	collided_tl(g->GetX() - g->GetHalfOfWidth(), g->GetY() + g->GetHalfOfHeight())	//bottom-left corner
	//		||	collided_tl(g->GetX() + g->GetHalfOfWidth(), g->GetY() + g->GetHalfOfHeight())	//bottom-right corner
	//		||	collided_tl(g->GetX() , g->GetY() + g->GetHalfOfHeight())	//bottom side
	//		||	collided_tl(g->GetX() , g->GetY() - g->GetHalfOfHeight())	//top side
	//		||	collided_tl(g->GetX() - g->GetHalfOfWidth(), g->GetY() )	//left side
	//		||	collided_tl(g->GetX() + g->GetHalfOfWidth(), g->GetY() ))	//right side
	//		GraphicsCore::DrawFilledRectangle(g->GetX() - g->GetHalfOfWidth(), g->GetY() - g->GetHalfOfHeight(), g->GetX() + g->GetHalfOfWidth(), g->GetY() + g->GetHalfOfHeight(), 255, 255, 0);
	//		//GraphicsCore::DrawFilledCircle(g->GetX() - g->GetHalfOfWidth() - 2, g->GetY() - g->GetHalfOfHeight() - 2, 5, 0, 255, 0);
	//}
}
int MappyLevel::collided_tl(int x, int y)
{
	if (x < 0 || y < 0 || x >= mapwidth*mapblockwidth || y >= mapheight*mapblockheight) 
		return 0;

	BLKSTR *blockdata;
	blockdata = MapGetBlock(x/mapblockwidth, y/mapblockheight);
	//GraphicsCore::DrawFilledCircle(x - 2, y - 2, 5, 255, 255, 0);
	
	return blockdata->tl;
}
 long MappyLevel::GetTileData(int blockX, int blockY, BLOCK_FIELD field, int layer){
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
