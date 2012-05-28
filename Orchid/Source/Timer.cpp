#include "Timer.h"


ALLEGRO_TIMER* Timer::globalFrameTimer = NULL;
double Timer::globalDeltaTime = 0.0f;
double Timer::lastFrameTimeStamp = 0;


Timer::Timer(){
	Set(500);
	running = false;
	remainingTime = 0;	
	coreTimer = NULL;
	coreTimer = al_create_timer(1.0 / 60);
	startingTime = al_get_timer_count(coreTimer);
	lastTick = al_get_timer_count(coreTimer);
	al_start_timer(coreTimer);

	if(!al_get_timer_started(Timer::globalFrameTimer)){
		al_start_timer(globalFrameTimer);		
	}
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
	lastFrameTimeStamp = al_get_timer_count(coreTimer);
	globalDeltaTime = 0;
}
Timer::~Timer(){
	al_destroy_timer(coreTimer);
}
double Timer::GetDeltaTime(){
	return globalDeltaTime;
}
void Timer::UpdateGlobalDeltaTime(){
	if(globalFrameTimer == NULL){
		globalFrameTimer = al_create_timer(100.0/60);
		al_start_timer(globalFrameTimer);
	}

	globalDeltaTime = al_get_timer_count(globalFrameTimer) - lastFrameTimeStamp;
	lastFrameTimeStamp = al_get_timer_count(globalFrameTimer);
}
void Timer::DestroyGlobalFrameTimer(){
	al_destroy_timer(globalFrameTimer);
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
	if(running)
		return remainingTime;
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
