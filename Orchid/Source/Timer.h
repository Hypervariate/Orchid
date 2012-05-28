#ifndef TIMER_H_
#define TIMER_H_

#include <allegro5\allegro.h>

class Timer{
public:
	Timer();
	Timer(double duration);
	~Timer();

	static double GetDeltaTime();
	static void UpdateGlobalDeltaTime();
	static void DestroyGlobalFrameTimer();

	void Set(double duration);			//set the timer target millisecond count
	double GetRemainingTime();			//get the remaining milliseconds in the countdown
	double Reset();						//reset the timer to the preset target millisecond count
	double Reset(double newDuration);	//reset the timer to a new target millisecond count
	bool Arrived();						//timer has reached 0 in the countdown

	double Start();						//start the timer
	double Stop();						//stop the timer
	double Pause(double pauseTime);		//pause the timer for n milliseconds

private:
	void Update();				//get the current milliseconds. called at the beginning of every function.
	double startingTime;		//milliseconds past at the time the timer started
	double remainingTime;		//milliseconds remaining
	double duration;			//starting time n (timers count down from n to 0)
	bool running;				//the timer is currently running
	double lastTick;			//timesteamp of the timer the last time it was updated
	double deltaTime;			//current time - lastTick
	ALLEGRO_TIMER *coreTimer;	//Allegro timer struct which lets this class function


	static ALLEGRO_TIMER *globalFrameTimer;
	static double globalDeltaTime;		//delta time since last frame in the program
	static double lastFrameTimeStamp;	//timestamp of the previous frame
	
};


#endif