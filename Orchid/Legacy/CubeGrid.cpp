#include "CubeGrid.h"

CubeGrid::CubeGrid()
{
	CubeGrid(0,0,0);
}
CubeGrid::CubeGrid( int w,  int h,  int l)
{
	AllocateCubeGrid(w,h,l);
}
void CubeGrid::AllocateCubeGrid( int w,  int h,  int l)
{
	m_cells.clear();
	m_sizeX = w;
	m_sizeY = h;
	m_sizeZ = l;
	for( int i = 0; i < m_sizeX * m_sizeY * m_sizeZ; i++)
		m_cells.push_back(i);
}
CubeGrid::~CubeGrid()
{

}
 int CubeGrid::GetCell( int x,  int y,  int z)
{
	int index = GetIndexFromCoordinate(x,y,z);
	if(IndexIsValid(index))
		return m_cells.at(index);
	else
		return 0;
}
void CubeGrid::SetCell( int x,  int y,  int z,  int value)
{
	int index = GetIndexFromCoordinate(x,y,z);
	if(IndexIsValid(index)){
		m_cells.at(index) = value;
	}
}
bool CubeGrid::IndexIsValid( int index)
{
	if( index >= 0 && index < m_cells.size())
		return true;
	else
		return false;
}
 int CubeGrid::GetSizeX()
{
	return m_sizeX;
}
 int CubeGrid::GetSizeY()
{
	return m_sizeY;
}
 int CubeGrid::GetSizeZ()
{
	return m_sizeZ;
}
 int CubeGrid::GetIndexFromCoordinate( int x,  int y,  int z)
{
	return x + y * m_sizeX + z * m_sizeY * m_sizeX;
}