#include "SquareGrid.h"

SquareGrid::SquareGrid()
{
	SquareGrid(0,0);
}
SquareGrid::SquareGrid( int w,  int h)
{
	AllocateSquareGrid(w,h);
}
void SquareGrid::AllocateSquareGrid( int w,  int h)
{
	m_cells.clear();
	m_sizeX = w;
	m_sizeY = h;
	for( int i = 0; i < m_sizeX*m_sizeY; i++)
		m_cells.push_back(0);
}
SquareGrid::~SquareGrid()
{

}
 int SquareGrid::GetCell( int x,  int y)
{
	int index = GetIndexFromCoordinate(x,y);
	if(IndexIsValid(index))
		return m_cells.at(index);
	else
		return 0;
}
void SquareGrid::SetCell( int x,  int y,  int value)
{
	int index = GetIndexFromCoordinate(x,y);
	if(IndexIsValid(index)){
		m_cells.at(index) = value;
	}
}
bool SquareGrid::IndexIsValid( int index)
{
	if( index >= 0 && index < m_cells.size())
		return true;
	else
		return false;
}
 int SquareGrid::GetSizeX()
{
	return m_sizeX;
}
 int SquareGrid::GetSizeY()
{
	return m_sizeY;
}
 int SquareGrid::GetIndexFromCoordinate( int x,  int y)
{
	return x + y * m_sizeX;
}