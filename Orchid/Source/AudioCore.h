#ifndef AUDIOCORE_H_
#define AUDIOCORE_H_

#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include "FileReader.h"
#include <map>
#include <string>

#define AUDIO_DIRECTORY "Data/Audio/"
#define AUDIO_EXTENSION ".ogg"

class AudioCore{
public:
	AudioCore();
	~AudioCore();

	//Core Routines
	//------------------
	static void Initialize();		//setup routine
	static void Update();			//per-frame update
	static void Deinitialize();		//shutdown routine
	//------------------

	//Public Functionality
	//------------------
	static void PlaySample(string sampleName);	//play an effect
	static void PlayMusic(string songName);		//play a song
	static void StopMusic();					//stop playing a song
	//------------------

private:
	static string currentSong;
	
	static bool LoadSample(char* fileName);

	static FileReader fileReader;

	static std::map<string, ALLEGRO_SAMPLE *> samples;
	static std::map<string, ALLEGRO_SAMPLE *>::iterator samplesIter;

	static std::map<string, ALLEGRO_SAMPLE_INSTANCE *> instances;
	static std::map<string, ALLEGRO_SAMPLE_INSTANCE *>::iterator instancesIter;

};

#endif