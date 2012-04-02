#include "AudioCore.h"

FileReader AudioCore::fileReader;

std::map<string, ALLEGRO_SAMPLE *> AudioCore::samples;
std::map<string, ALLEGRO_SAMPLE *>::iterator AudioCore::samplesIter;

std::map<string, ALLEGRO_SAMPLE_INSTANCE *> AudioCore::instances;
std::map<string, ALLEGRO_SAMPLE_INSTANCE *>::iterator AudioCore::instancesIter;

AudioCore::AudioCore(){}
AudioCore::~AudioCore(){}
void AudioCore::Initialize(){
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(8);

	//load all font files located in fonts directory
	vector<string> audioFileNames;
	fileReader.GetAllFileNamesInDirectory(AUDIO_DIRECTORY, audioFileNames);
	for(int i = 0; i < audioFileNames.size(); i++){
		LoadSample((char*)audioFileNames.at(i).c_str());
	}
}
void AudioCore::Deinitialize(){
	
	for(instancesIter = instances.begin(); instancesIter != instances.end(); instancesIter++){
		al_destroy_sample_instance((*instancesIter).second);
	}
	
	for(samplesIter = samples.begin(); samplesIter != samples.end(); samplesIter++){
		al_destroy_sample((*samplesIter).second);
	}
	
}
void AudioCore::Update(){

}
void AudioCore::PlaySample(string fileName){
	if(instances.find(fileName) == instances.end())
		return;

	al_play_sample_instance(instances[fileName]);
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

	ALLEGRO_SAMPLE_INSTANCE *instance = NULL;
	instance = al_create_sample_instance(sample);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
	instances[fileName] = instance;

	return true;
}