#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_

#define max(a,b)	(((a) > (b)) ? (a) : (b))
#define min(a,b)	(((a) < (b)) ? (a) : (b))
#define ABS(N)      (((N) >= 0 ? (N) : -(N)))

#define PTM_RATIO 32
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/regex.hpp>


#include <string>
using namespace std;


class GlobalData{
public:
	GlobalData();
	~GlobalData();

	//Public Routines
	//---------------
	static void RequestApplicationTermination(string reason);
	static bool ApplicationRunning();
	//---------------

private:
	static bool applicationRunning;

};

#endif