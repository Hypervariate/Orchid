#include "GlobalData.h"

bool GlobalData::applicationRunning = true;

GlobalData::GlobalData(){

}
GlobalData::~GlobalData(){

}
void GlobalData::RequestApplicationTermination(string reason){
	applicationRunning = false;
}
bool GlobalData::ApplicationRunning(){
	return applicationRunning;
}