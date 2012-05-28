#pragma once

#include "GlobalData.h"
#include "EventCore.h"
#include "AudioCore.h"

#include "NeighborController.h"
#include "Neighbor.h"


class AnimalCrossingGame{
public:

	AnimalCrossingGame(void){}
	~AnimalCrossingGame(void){}

	//All the game logic for AnimalCrossing
	static void Run(void){
		
	//create the player
	Neighbor* n = new Neighbor(WIDTH*2/3, HEIGHT/2);
	GameObject::AddToWorld(n);
		
	//register the player with a controller for the object
	EventCore::RegisterGameObjectAsPlayer(n, 0, new NeighborController());

		//game loop
		while(GlobalData::ApplicationRunning()){

			//process new events every frame
			EventCore::Update();

			//update all game objects every frame
			GameObject::UpdateAll();


		

		}
	}
};

