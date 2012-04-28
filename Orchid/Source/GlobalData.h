#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_

#define max(a,b)	(((a) > (b)) ? (a) : (b))
#define min(a,b)	(((a) < (b)) ? (a) : (b))
#define ABS(N)      (((N) >= 0 ? (N) : -(N)))

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/regex.hpp>


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