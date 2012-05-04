#pragma once

#include "GlobalData.h"
#include "EventCore.h"
#include "AudioCore.h"


#include "BreakoutBlock.h"
#include "BreakoutPaddle.h"
#include "BreakoutPaddleController.h"

class BreakoutGame{
public:

	BreakoutGame(void){}
	~BreakoutGame(void){}

	//All the game logic for Breakout
	static void Run(void){
		//create blocks
		int bx = 48;
		int by = 24;
		for(int i = 1; i < 13; i++){
			for(int j = 1; j < 5; j++){
				BreakoutBlock* b = new BreakoutBlock(i * bx, j * by);
				GameObject::AddToWorld(b);
			}
		}
	
		//create the player (a paddle object)
		BreakoutPaddle* p = new BreakoutPaddle(WIDTH/2, HEIGHT - 100);
	
		//register the player with a controller for the object
		EventCore::RegisterGameObjectAsPlayer(p, 0, new BreakoutPaddleController());
	
		//add it to the world so that it becomes "real"
		GameObject::AddToWorld(p);
	
		//use a timer object to display "press space to start" for the first 2.5 seconds
		Timer timer = Timer(250);
		timer.Start();
	
		//play a song
		AudioCore::PlayMusic("BreakoutBGM");

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

