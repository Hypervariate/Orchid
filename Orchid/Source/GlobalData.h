#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_

#define max(a,b)	(((a) > (b)) ? (a) : (b))
#define min(a,b)	(((a) < (b)) ? (a) : (b))

#include <string>
using namespace std;

#define MAX_PATH_LENGTH 512

#define IMAGE_DIRECTORY "Data/Images/"
#define IMAGE_EXTENSION ".png"

class GlobalData{
public:
	GlobalData();
	~GlobalData();

	static void RequestApplicationTermination(string reason);
	static bool ApplicationRunning();
private:
	static bool applicationRunning;

};

#endif