#ifndef CUBEGRID_H_
#define CUBEGRID_H_

#include <vector>
using namespace std;

class CubeGrid{

public:
	CubeGrid();
    CubeGrid(unsigned int w, unsigned int h, unsigned int l);
    ~CubeGrid();

	//resize the vector to accomodate the specified grid size
	//populate all indeces with 0
	void AllocateCubeGrid(unsigned int w, unsigned int h, unsigned int l);

	//return the unsigned int value within the specified cell
    unsigned int GetCell(unsigned int x, unsigned int y, unsigned int z);

	//set the int value contained within the cell
    void SetCell(unsigned int x, unsigned int y, unsigned int z, unsigned int value);


	unsigned int GetSizeX();
	unsigned int GetSizeY();
	unsigned int GetSizeZ();


private:
    vector<unsigned int> m_cells;
	unsigned int m_sizeX;
	unsigned int m_sizeY;
	unsigned int m_sizeZ;

	unsigned int GetIndexFromCoordinate(unsigned int x, unsigned int y, unsigned int z);
	bool IndexIsValid(unsigned int index);

};

#endif