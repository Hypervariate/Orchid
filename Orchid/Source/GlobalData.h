#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_

#include <string>
using namespace std;

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