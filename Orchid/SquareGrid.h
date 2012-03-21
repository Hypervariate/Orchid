#ifndef SQUAREGRID_H_
#define SQUAREGRID_H_

#include <vector>
using namespace std;

class SquareGrid{

public:
	SquareGrid();
    SquareGrid(unsigned int w, unsigned int h);
    ~SquareGrid();

	//resize the vector to accomodate the specified grid size
	//populate all indeces with 0
	void AllocateSquareGrid(unsigned int w, unsigned int h);

	//return the unsigned int value within the specified cell
    unsigned int GetCell(unsigned int x, unsigned int y);

	//set the int value contained within the cell
    void SetCell(unsigned int x, unsigned int y, unsigned int value);


	unsigned int GetSizeX();
	unsigned int GetSizeY();


private:
    vector<unsigned int> m_cells;
	unsigned int m_sizeX;
	unsigned int m_sizeY;

	unsigned int GetIndexFromCoordinate(unsigned int x, unsigned int y);
	bool IndexIsValid(unsigned int index);

};

#endif