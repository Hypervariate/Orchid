#include "CubeGrid.h"

CubeGrid::CubeGrid()
{
	CubeGrid(0,0,0);
}
CubeGrid::CubeGrid(unsigned int w, unsigned int h, unsigned int l)
{
	AllocateCubeGrid(w,h,l);
}
void CubeGrid::AllocateCubeGrid(unsigned int w, unsigned int h, unsigned int l)
{
	m_cells.clear();
	m_sizeX = w;
	m_sizeY = h;
	m_sizeZ = l;
	for(unsigned int i = 0; i < m_sizeX * m_sizeY * m_sizeZ; i++)
		m_cells.push_back(i);
}
CubeGrid::~CubeGrid()
{

}
unsigned int CubeGrid::GetCell(unsigned int x, unsigned int y, unsigned int z)
{
	int index = GetIndexFromCoordinate(x,y,z);
	if(IndexIsValid(index))
		return m_cells.at(index);
	else
		return 0;
}
void CubeGrid::SetCell(unsigned int x, unsigned int y, unsigned int z, unsigned int value)
{
	int index = GetIndexFromCoordinate(x,y,z);
	if(IndexIsValid(index)){
		m_cells.at(index) = value;
	}
}
bool CubeGrid::IndexIsValid(unsigned int index)
{
	if( index >= 0 && index < m_cells.size())
		return true;
	else
		return false;
}
unsigned int CubeGrid::GetSizeX()
{
	return m_sizeX;
}
unsigned int CubeGrid::GetSizeY()
{
	return m_sizeY;
}
unsigned int CubeGrid::GetSizeZ()
{
	return m_sizeZ;
}
unsigned int CubeGrid::GetIndexFromCoordinate(unsigned int x, unsigned int y, unsigned int z)
{
	return x + y * m_sizeX + z * m_sizeY * m_sizeX;
}