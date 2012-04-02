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

	//Audio Core Routines
	//------------------
	static void Initialize();
	static void Update();
	static void Deinitialize();
	
	//------------------
	static void PlaySample(string sampleName);

private:
	static bool LoadSample(char* fileName);

	static FileReader fileReader;

	static std::map<string, ALLEGRO_SAMPLE *> samples;
	static std::map<string, ALLEGRO_SAMPLE *>::iterator samplesIter;

	static std::map<string, ALLEGRO_SAMPLE_INSTANCE *> instances;
	static std::map<string, ALLEGRO_SAMPLE_INSTANCE *>::iterator instancesIter;

};

#endif