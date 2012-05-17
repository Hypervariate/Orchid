#pragma once

#include "GlobalData.h"
#include "EventCore.h"
#include "AudioCore.h"


#include "Balloon.h"
#include "Frog.h"
#include "FrogController.h"


class BalloonFightGame{
public:

	BalloonFightGame(void){}
	~BalloonFightGame(void){}

	//All the game logic for Breakout
	static void Run(void){
		//create blocks
		
		
			

		Frog* f = new Frog(WIDTH/2, HEIGHT/2 + 64);
			GameObject::AddToWorld(f);
		
		//register the player with a controller for the object
		EventCore::RegisterGameObjectAsPlayer(f, 0, new FrogController());
			
		
		//use a timer object to display "press space to start" for the first 2.5 seconds
		Timer timer = Timer(250);
		timer.Start();
	
		////play a song
		//AudioCore::PlayMusic("BreakoutBGM");

		//game loop
		while(GlobalData::ApplicationRunning()){

			//process new events every frame
			EventCore::Update();

			//update all game objects every frame
			GameObject::UpdateAll();

			//print message to user in the first few seconds of the game
			if(!timer.Arrived())
				GraphicsCore::PrintToDisplay("Press space to start.", WIDTH/3, HEIGHT/2,"Arcade", 255);
		

		}
	}
};

