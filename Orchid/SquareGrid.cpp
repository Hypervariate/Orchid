#include "SquareGrid.h"

SquareGrid::SquareGrid()
{
	SquareGrid(0,0);
}
SquareGrid::SquareGrid(unsigned int w, unsigned int h)
{
	AllocateSquareGrid(w,h);
}
void SquareGrid::AllocateSquareGrid(unsigned int w, unsigned int h)
{
	m_cells.clear();
	m_sizeX = w;
	m_sizeY = h;
	for(unsigned int i = 0; i < m_sizeX*m_sizeY; i++)
		m_cells.push_back(0);
}
SquareGrid::~SquareGrid()
{

}
unsigned int SquareGrid::GetCell(unsigned int x, unsigned int y)
{
	int index = GetIndexFromCoordinate(x,y);
	if(IndexIsValid(index))
		return m_cells.at(index);
	else
		return 0;
}
void SquareGrid::SetCell(unsigned int x, unsigned int y, unsigned int value)
{
	int index = GetIndexFromCoordinate(x,y);
	if(IndexIsValid(index)){
		m_cells.at(index) = value;
	}
}
bool SquareGrid::IndexIsValid(unsigned int index)
{
	if( index >= 0 && index < m_cells.size())
		return true;
	else
		return false;
}
unsigned int SquareGrid::GetSizeX()
{
	return m_sizeX;
}
unsigned int SquareGrid::GetSizeY()
{
	return m_sizeY;
}
unsigned int SquareGrid::GetIndexFromCoordinate(unsigned int x, unsigned int y)
{
	return x + y * m_sizeX;
}