#include "EventCore.h"
#include "GlobalData.h"
#include "UtilityRectangle.h"
#include "UtilityCircle.h"
#include "AudioCore.h"
#include "Witch.h"

#include "GameLevel.h"

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
	
	////Boost regex, compiled library
	//boost::regex regex("^(Hello|Bye) Boost$");
	//boost::cmatch helloMatches;
	//boost::regex_search("Hello Boost", helloMatches, regex);
	//cout << "The word between () is: " << helloMatches[1] << endl;

	//Boost shared pointer, header only library
	//boost::shared_ptr<Hello> sharedHello(new Hello);

	UtilityRectangle b = UtilityRectangle(WIDTH/2, HEIGHT/2, 50, 50);	
	//Witch b = Witch();
	EventCore::RegisterGameObjectAsPlayer(&b, 0);	

	UtilityCircle c = UtilityCircle(WIDTH/2, HEIGHT/2, 50);
	EventCore::RegisterGameObjectAsPlayer(&c, 1);

	GameLevel level = GameLevel();
	level.Load("0", &b);
	
	while(GlobalData::ApplicationRunning()){
		EventCore::Update();
		
		level.DrawBackground();
		GameObject::UpdateAll();
		level.Update();
		level.DrawForeground();
		
	}

	level.Unload();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
