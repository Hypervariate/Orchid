#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "FileReader.h"


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

	static bool LoadAnimation(char* animation_name, Animation* animation);	//loads animation from a file name. Do not pass directory/extension	
	unsigned int GetFrameCount();				//returns the total frame count for the animation sequence

	
	string UpdateAnimation(float delta_time);	//updates the current frame if necessary. Always returns current frame name.
	string GetFrameName(unsigned int index);		//returns the name of the current frame image accepted by Graphics::BlitImage(name)

	void PauseAnimation();	//halt the animation at the current frame
	void StopAnimation();	//stop the animation and set the current frame to 0
	void PlayAnimation();	//resume the animation
	
	bool IsAnimationPlaying(); //returns true if animation is animating, false if paused or stopped

	void SetAnimationBehavior(ANIMATION_BEHAVIOR behavior);
	void ClearAnimation();	//delete all frames on the heap
	char* GetAnimationName();

private:

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
};

#endif