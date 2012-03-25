#include "GraphicsCore.h"
#include "InputCore.h"
#include "GlobalData.h"
#include "Shape2DRect.h"
#include "Shape2DCircle.h"

int main(void)
{
	if(!al_init())			//initialize Allegro
		return -1;
	
	GraphicsCore::Initialize();
	InputCore::Initialize();

	Shape2DCircle c = Shape2DCircle(WIDTH/2, HEIGHT/2, 100);

	
	while(GlobalData::ApplicationRunning()){

		
		c.DrawShape();
		
		GraphicsCore::Update();
		InputCore::Update();
		
		
	}
	

	GraphicsCore::Deinitialize();
	InputCore::Deinitialize();

	return 0;
}
