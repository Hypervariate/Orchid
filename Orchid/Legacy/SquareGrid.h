#ifndef SQUAREGRID_H_
#define SQUAREGRID_H_

#include <vector>
using namespace std;

class SquareGrid{

public:
	SquareGrid();
    SquareGrid( int w,  int h);
    ~SquareGrid();

	//resize the vector to accomodate the specified grid size
	//populate all indeces with 0
	void AllocateSquareGrid( int w,  int h);

	//return the  int value within the specified cell
     int GetCell( int x,  int y);

	//set the int value contained within the cell
    void SetCell( int x,  int y,  int value);


	 int GetSizeX();
	 int GetSizeY();


private:
    vector< int> m_cells;
	 int m_sizeX;
	 int m_sizeY;

	 int GetIndexFromCoordinate( int x,  int y);
	bool IndexIsValid( int index);

};

#endif