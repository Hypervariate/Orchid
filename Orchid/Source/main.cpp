#include "EventCore.h"
#include "GlobalData.h"
#include "UtilityRectangle.h"
#include "UtilityCircle.h"
#include "AudioCore.h"
#include "Witch.h"

#include "TiledLevel.h"

struct Hello 
{
	Hello(){ 
		cout << "Hello constructor" << endl;
	}

	~Hello(){
		cout << "Hello destructor" << endl;
		cin.get();
	}
};

int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();
	
	Witch b = Witch();
	EventCore::RegisterGameObjectAsPlayer(&b, 0);	

	UtilityCircle c = UtilityCircle(WIDTH/2, HEIGHT/2, 50);
	EventCore::RegisterGameObjectAsPlayer(&c, 1);

	TiledLevel level = TiledLevel();
	level.Load("desert", &b);
	
	while(GlobalData::ApplicationRunning()){
		EventCore::Update();
		
		level.Update();
		level.Draw();
		GameObject::UpdateAll();
		
		
	}

	level.Unload();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
