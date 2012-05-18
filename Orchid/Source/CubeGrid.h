#ifndef CUBEGRID_H_
#define CUBEGRID_H_

#include <vector>
using namespace std;

class CubeGrid{

public:
	CubeGrid();
    CubeGrid( int w,  int h,  int l);
    ~CubeGrid();

	//resize the vector to accomodate the specified grid size
	//populate all indeces with 0
	void AllocateCubeGrid( int w,  int h,  int l);

	//return the  int value within the specified cell
     int GetCell( int x,  int y,  int z);

	//set the int value contained within the cell
    void SetCell( int x,  int y,  int z,  int value);


	 int GetSizeX();
	 int GetSizeY();
	 int GetSizeZ();


private:
    vector< int> m_cells;
	 int m_sizeX;
	 int m_sizeY;
	 int m_sizeZ;

	 int GetIndexFromCoordinate( int x,  int y,  int z);
	bool IndexIsValid( int index);

};

#endif