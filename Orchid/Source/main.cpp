#include "EventCore.h"
#include "GlobalData.h"
#include "Witch.h"
#include "FileReader.h"


int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	
	Witch w = Witch();
	EventCore::RegisterGameObjectAsPlayer(&w, 0);		

	FileReader f = FileReader();
	vector<string> files;
	f.GetAllFileNamesInDirectory(IMAGE_DIRECTORY, files);

	EventCore::Update();
	

	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
