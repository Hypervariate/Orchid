#include "GraphicsCore.h"
#include "InputCore.h"
#include "GlobalData.h"

int main(void)
{
	if(!al_init())			//initialize Allegro
		return -1;
	
	GraphicsCore::Initialize();
	InputCore::Initialize();
	
	while(GlobalData::ApplicationRunning()){

		float points[] = {0, 0, 400, 100, 50, 200, WIDTH, HEIGHT};
		GraphicsCore::DrawSpline(points, 255, 0, 255, 10);

		GraphicsCore::DrawRectangle(10, 10, 250, 250, 255, 0, 255, 5);
		GraphicsCore::DrawRoundedRectangle(WIDTH - 200, 10, WIDTH - 10, 50, 5, 5, 0, 0, 255, 15);
		GraphicsCore::DrawFilledRectangle(10, 280, 250, HEIGHT - 10, 255, 255, 255);
		GraphicsCore::DrawFilledRoundedRectangle(WIDTH - 200, 180, WIDTH - 10, HEIGHT - 10, 10, 10, 0, 255, 0);

		GraphicsCore::DrawLine(100, 100, WIDTH - 100, 100, 255, 0, 0, 3);

		GraphicsCore::DrawTriangle(10, 200, 100, 10, 190, 200, 255, 0, 255, 5);
		GraphicsCore::DrawFilledTriangle(300, 400, 400, 200, 500, 400, 0, 0, 255);

		GraphicsCore::DrawCircle(100, 100, 50, 255, 255, 0, 3);
		GraphicsCore::DrawFilledCircle(400, 400, 70, 255, 128, 255);

		GraphicsCore::DrawEllipse(150, 100, 100, 50, 127, 3, 34, 7);
		GraphicsCore::DrawFilledEllipse(400, 250, 100, 200, 0, 255, 255);

		GraphicsCore::PrintToDisplay(3436346, 10, 350, "acknowledge", 128, 255);
		GraphicsCore::PrintToDisplay("Hi! Howareya?", 10, 400, "acknowledge", 128, 128);
		
		InputCore::Update();
		GraphicsCore::Update();
		
	}
	

	GraphicsCore::Deinitialize();
	InputCore::Deinitialize();

	return 0;
}
