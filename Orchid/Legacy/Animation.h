#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "FileReader.h"
#include <map>
#include "Vector2D.h"
#include "Timer.h"

#define ANIMATION_DIRECTORY "Data/Animations/"
#define ANIMATION_EXTENSION ".txt"

enum ANIMATION_BEHAVIOR{
	PLAY_ONCE = 0,
	BOUNCE,
	REPEAT
};

class Animation{
public:
	Animation();
	~Animation();
		
	//Create an animation and return it to the caller
	static Animation FactoryAnimation(string animationName);

	//updates the current frame if necessary. Always returns current frame name.
	string UpdateAnimation();	

	//halt the animation at the current frame
	void PauseAnimation();	

	//stop the animation and set the current frame to 0
	void StopAnimation();	

	//resume the animation
	void PlayAnimation();	
	
	//returns true if animation is animating, false if paused or stopped
	bool IsAnimationPlaying(); 

	//set the animation to PLAY_ONCE, BOUNCE or REPEAT
	void SetAnimationBehavior(ANIMATION_BEHAVIOR behavior);
		

private:
	static std::map<string, Animation> animationFactory;
	static std::map<string, Animation>::iterator iter;
	
	static void CacheAllAnimationFiles();

	static bool LoadAnimation(char* animation_name, Animation* animation);	//loads animation from a file name. Do not pass directory/extension	
	 int GetFrameCount();				//returns the total frame count for the animation sequence
	string GetFrameName( int index);		//returns the name of the current frame image accepted by Graphics::BlitImage(name)
	char* GetAnimationName();
	void ClearAnimation();	//delete all frames on the heap

	char m_animationName[MAX_PATH_LENGTH];
	static FileReader m_fileReader;

	vector<string> m_frames;
	
	int m_frameIndex;
	float frameDeltaTime;
	float m_frameRate;
	float m_lastFrameTimeStamp;

	bool m_animationIsPlaying;
	ANIMATION_BEHAVIOR m_behavior;
	int m_direction;
	Vector2D m_imageOffset;
};

#endif