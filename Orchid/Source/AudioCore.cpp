#include "AudioCore.h"

FileReader AudioCore::fileReader;
std::map<string, ALLEGRO_SAMPLE *> AudioCore::samples;
std::map<string, ALLEGRO_SAMPLE *>::iterator AudioCore::iter;

AudioCore::AudioCore(){}
AudioCore::~AudioCore(){}
void AudioCore::Initialize(){
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);

	//load all font files located in fonts directory
	vector<string> audioFileNames;
	fileReader.GetAllFileNamesInDirectory(AUDIO_DIRECTORY, audioFileNames);
	for(int i = 0; i < audioFileNames.size(); i++)
		LoadSample((char*)audioFileNames.at(i).c_str());
}
void AudioCore::Deinitialize(){
	
	for(iter = samples.begin(); iter != samples.end(); iter++)
		al_destroy_sample((*iter).second);
	
}
void AudioCore::Update(){

}
void AudioCore::PlaySample(string fileName){
	if(samples.find(fileName) == samples.end())
		return;

	al_play_sample(samples[fileName], 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
}
bool AudioCore::LoadSample(char* fileName)
{
	//check if image already exists
	if(samples[fileName] != NULL)
	{
		ALLEGRO_SAMPLE* sample = samples[fileName];
        al_destroy_sample(sample);
        sample = NULL;
	}

	char path[MAX_PATH_LENGTH];

	for(int i = 0; i < MAX_PATH_LENGTH; i++)
		path[i] = '\0';

	strcat(path, AUDIO_DIRECTORY);
	strcat(path, fileName);
	strcat(path, AUDIO_EXTENSION);

	ALLEGRO_SAMPLE *sample = NULL;
	sample = al_load_sample(path);
	if ( !sample )
    {
      cout << "sample load failed: " <<  path << endl;
      return false;
    }
	samples[fileName] = sample;

	return true;
}