#include "GameLevel.h"

GameLevel::GameLevel(){
	scrollingOffset.x = 10.5;
	scrollingOffset.y = 10.5;

}
GameLevel::~GameLevel(){
	Unload();
}
bool GameLevel::Load(char* fileName){
	if(MapLoad(fileName, 1))
		true;

	return false;
}
void GameLevel::DrawBackground(){
	MapDrawBG(scrollingOffset.x, scrollingOffset.y, 0, 0, WIDTH, HEIGHT);
}
void GameLevel::DrawForeground(){
	//MapDrawFG(scrollingOffset.x, scrollingOffset.y, 0, 0, WIDTH, HEIGHT);
}
void GameLevel::Unload(){
	MapFreeMem();
}