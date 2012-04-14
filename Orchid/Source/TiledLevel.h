#ifndef TILEDLEVEL_H_
#define TILEDLEVEL_H_

#include "GraphicsCore.h"
#include "GameObject.h"
#include "Vector2DF.h"
#include "Vector2D.h"
#include "SquareGrid.h"
#include <vector>
#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>


#include <iostream>

#define LEVEL_DIRECTORY "Data/Maps/"
#define LEVEL_EXTENSION ".tmx"

struct LayerData{
	string name;
	double opacity;
	bool visible;
};

class TiledLevel{
public:
	TiledLevel();
	~TiledLevel();

	bool Load(char* levelName, GameObject* cameraTarget);
	void Unload();
	void Draw();
	void Update();
	
	const bool TiledLevel::parseTMXFile(const std::string &filename);

private:
	GameObject* cameraTarget;
	SquareGrid cells;
	vector<LayerData> layers;

	string mapName;
	Vector2D mapDimensions;
	Vector2D cellDimensions;
	
	Vector2D tileOffset;
	
	
	string tileMapFileName;
	Vector2D tileMapPixelDimensions; //x pixels wide, y pixels tall
	Vector2D tileMapTileDimensions;	//x tiles wide, y tiles tall
	int tileMapTileCount;
};


#endif