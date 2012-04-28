#include "Timer.h"

Timer::Timer(){
	Timer(500);		//0.5 seconds (arbitrary init value)
}
Timer::Timer(double duration){
	Set(duration);
	running = false;
	remainingTime = 0;	
	coreTimer = NULL;
	coreTimer = al_create_timer(1.0 / 60);
	startingTime = al_get_timer_count(coreTimer);
	lastTick = al_get_timer_count(coreTimer);
	al_start_timer(coreTimer);
}
Timer::~Timer(){
	al_destroy_timer(coreTimer);
}
void Timer::Update(){
	deltaTime = al_get_timer_count(coreTimer) - lastTick;
	if(running)
		remainingTime -= deltaTime;
	lastTick = al_get_timer_count(coreTimer);
}
void Timer::Set(double duration){
	this->duration = duration;
}
double Timer::GetRemainingTime(){
	Update();
	return remainingTime;
}
double Timer::Reset(){
	return Reset(duration);
}
double Timer::Reset(double newDuration){
	remainingTime = duration = newDuration;
	startingTime = al_get_timer_count(coreTimer);
	Update();
	return duration;
}
bool Timer::Arrived(){
	Update();
	if(remainingTime <= 0)
		return true;
	return false;
}
double Timer::Start(){
	startingTime = al_get_timer_count(coreTimer);
	remainingTime = startingTime + duration;
	running = true;
	return remainingTime;
}
double Timer::Pause(double pauseTime){
	remainingTime += pauseTime;
	Update();
	return remainingTime;
}
double Timer::Stop(){
	Update();
	running = false;
	return remainingTime;
}
