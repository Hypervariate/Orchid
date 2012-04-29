#include "TiledLevel.h"
#include "EventCore.h"

#include "UtilityCircle.h"
#include "UtilityRectangle.h"
#include "WitchController.h"
#include "Witch.h"

TiledLevel::TiledLevel(){
	mapDimensions.Set(0,0);
	cellDimensions.Set(0,0);

}
TiledLevel::~TiledLevel(){
	Unload();
}
bool TiledLevel::Load(char* levelName){

	char path[MAX_PATH_LENGTH];

	for(int i = 0; i < MAX_PATH_LENGTH; i++)
		path[i] = '\0';

	strcat(path, LEVEL_DIRECTORY);
	strcat(path, levelName);
	strcat(path, LEVEL_EXTENSION);

	GraphicsCore::SetMapDimensions(0, 0);
	GraphicsCore::SetMapTileDimensions(0, 0);

	bool successful = false;
	if(parseTMXFile(path))
		successful = true;
	
	
	return successful;
}
void TiledLevel::SetCameraTarget(GameObject* cameraTarget){
	this->cameraTarget = cameraTarget;
	Update();
}
void TiledLevel::Draw(){
	
	int tile = 0;
	int xStart = GraphicsCore::GetMapScrollingOffsetX() / cellDimensions.x;
	int yStart = GraphicsCore::GetMapScrollingOffsetY() / cellDimensions.y;
	int xCount = WIDTH / cellDimensions.x + xStart + 1;
	int yCount =  HEIGHT / cellDimensions.y + yStart + 1;
	
	if(orientation == ORTHOGONAL){
		for(int i = xStart; i < xCount && i < cells.GetSizeX(); i++){
			for(int j = yStart; j < yCount && j < cells.GetSizeY(); j++){
				tile = cells.GetCell(i,j) - 1;
				int sx = tile * cellDimensions.x % tileMapPixelDimensions.x;
				int sy = tile / tileMapTileDimensions.x * cellDimensions.y;
				GraphicsCore::BlitImageRegion(
					sx,
					sy,
					cellDimensions.x,
					cellDimensions.y,
					i * cellDimensions.x,
					j * cellDimensions.y,
					tileMapFileName
				);
			}
		}
	}
	else if(orientation == ISOMETRIC){
		//for (i = 0; i < tile_map.size; i++)
		//	for (j = tile_map[i].size; j >= 0; j--)  // Changed loop condition here.
		//		draw(
		//			tile_map[i][j],
		//			x = (j * tile_width / 2) + (i * tile_width / 2)
		//			y = (i * tile_height / 2) - (j * tile_height / 2)
		//		)
		for (int i = 0; i < xCount && i < 1; i++){
			for (int j = 0; j < xCount && j < 2; j++){
				tile = cells.GetCell(i,j) - 1;
				int sx = tile * cellDimensions.x % tileMapPixelDimensions.x;
				int sy = tile / tileMapTileDimensions.x * cellDimensions.y;
				GraphicsCore::BlitImageRegion(
					sx,
					sy,
					cellDimensions.x,
					cellDimensions.y * 2,
					(j * cellDimensions.x ) + (i * cellDimensions.x),
					(i * cellDimensions.y ) + (j * cellDimensions.y),
					tileMapFileName
				);
			}
		}
	}
}
void TiledLevel::Unload(){
	
}
void TiledLevel::Update(){
	
	GraphicsCore::SetMapScrollingOffsetX(cameraTarget->GetX() + cameraTarget->GetHalfOfWidth());
	GraphicsCore::SetMapScrollingOffsetX(GraphicsCore::GetMapScrollingOffsetX() - WIDTH/2);

	GraphicsCore::SetMapScrollingOffsetY(cameraTarget->GetY() + cameraTarget->GetHalfOfHeight());
	GraphicsCore::SetMapScrollingOffsetY(GraphicsCore::GetMapScrollingOffsetY() - HEIGHT/2);
}
const bool TiledLevel::parseTMXFile(const std::string &filename)
{            
        
		boost::property_tree::ptree pt;
        boost::property_tree::xml_parser::read_xml(filename, pt);
       
		orientation = ORTHOGONAL;
		string perspective = pt.get<std::string>("map.<xmlattr>.orientation");
		if(perspective == "isometric")
			orientation = ISOMETRIC;

		mapDimensions.x		 = pt.get<int>( "map.<xmlattr>.width", 0 );
        mapDimensions.y		 = pt.get<int>( "map.<xmlattr>.height", 0 );
		
		

		GraphicsCore::SetMapDimensions(mapDimensions.x, mapDimensions.y);


        cellDimensions.x	 = pt.get<int>( "map.<xmlattr>.tilewidth", 0 );
        cellDimensions.y	 = pt.get<int>( "map.<xmlattr>.tileheight", 0 );
		GraphicsCore::SetMapTileDimensions(cellDimensions.x, cellDimensions.y);

		cells.AllocateSquareGrid(mapDimensions.x, mapDimensions.y);


        BOOST_FOREACH( boost::property_tree::ptree::value_type &v, pt.get_child("map") )
        {
			
			if(v.first == "tileset"){
				tileMapPixelDimensions.x = v.second.get<int>("image.<xmlattr>.width");
				tileMapPixelDimensions.y = v.second.get<int>("image.<xmlattr>.height");
				tileMapTileDimensions.x  = tileMapPixelDimensions.x / cellDimensions.x;
				tileMapTileDimensions.y  = tileMapPixelDimensions.y / cellDimensions.y;
				tileMapTileCount = tileMapTileDimensions.x * tileMapTileDimensions.y;

				mapName = v.second.get<std::string>("<xmlattr>.name");
				tileMapFileName  = v.second.get<std::string>("image.<xmlattr>.source");
				int startIndex = tileMapFileName.find_last_of("/") + 1;
				int endIndex = tileMapFileName.find_last_of(".");
				tileMapFileName = tileMapFileName.substr(startIndex, endIndex - startIndex);
				
			}
            if(v.first == "layer")
            {                
                LayerData layer;
                layer.name    = v.second.get<std::string>("<xmlattr>.name");               
                
				
				//collision layer is special
				if(layer.name == "Collision"){
					std::string csv = v.second.get<std::string>("data");

					typedef boost::char_separator<char> sep;
					typedef boost::tokenizer< sep > tk;
               
					tk tokens(csv, sep(",\n\r"));
					int index = 0;
               
					int x = 0;
					int y = 0;
               
					for (tk::iterator i(tokens.begin()); i!=tokens.end(); ++i)
					{
						int tile = boost::lexical_cast<int>( *i );
						
						if(tile != 0){
							LevelCollisionTile* collisionTile = new LevelCollisionTile(x * cellDimensions.x, y * cellDimensions.y, cellDimensions.x, cellDimensions.y);
							GameObject::AddToWorld(collisionTile);
						}
                   
						if(++x >= mapDimensions.x)
						{
							y++;
							x = 0;
						}
                                 
						index++;
					}
               
					
				}
				else{
					layer.opacity = v.second.get<double>	 ("<xmlattr>.opacity", 1);
					layer.visible = v.second.get<bool>		 ("<xmlattr>.visible", true);
				

					std::string csv = v.second.get<std::string>("data");

					typedef boost::char_separator<char> sep;
					typedef boost::tokenizer< sep > tk;
               
					tk tokens(csv, sep(",\n\r"));
					int index = 0;
               
					int x = 0;
					int y = 0;
               
					for (tk::iterator i(tokens.begin()); i!=tokens.end(); ++i)
					{
						int tile = boost::lexical_cast<int>( *i );
						cells.SetCell( x, y, tile);
                   
						if(++x >= mapDimensions.x)
						{
							y++;
							x = 0;
						}
                                 
						index++;
					}
               
					layers.push_back( layer );
				}
			}
        }    

		
       
        BOOST_FOREACH( boost::property_tree::ptree::value_type &v, pt.get_child("map") )
        {
            if(v.first == "objectgroup")
            {              
                
                string tiled_object_name = v.second.get<std::string>("<xmlattr>.name");
               
                BOOST_FOREACH( boost::property_tree::ptree::value_type &o, v.second )
                {
                    if(o.first == "object")
                    {
                        string object_name = o.second.get<std::string>( "<xmlattr>.name", "Object" );
                       
                        int x = o.second.get<int>( "<xmlattr>.x" );
						int y = o.second.get<int>( "<xmlattr>.y" );
						string name = o.second.get<std::string>( "<xmlattr>.name", "Object" );
						string type = o.second.get<std::string>( "<xmlattr>.type", "Object" );
						
						if(type == "UtilityCircle"){
							UtilityCircle* o = new UtilityCircle(x, y);
							GameObject::AddToWorld(o);
						}
						else if(type == "UtilityRectangle"){
							UtilityRectangle* o = new UtilityRectangle(x, y);
							GameObject::AddToWorld(o);	
						}
						else if(type == "Witch"){
							Witch* o = new Witch(x, y);
							GameObject::AddToWorld(o);	
						}

						BOOST_FOREACH( boost::property_tree::ptree::value_type &p, o.second )
						{
							if(p.first == "properties"){
								string propertyName = p.second.get<std::string>( "property.<xmlattr>.name", "Object" );
								int propertyValue = p.second.get<int>( "property.<xmlattr>.value" );
								if(propertyName == "player" && type == "Witch"){
									GameObject* gameObject = GameObject::GetGameObject();
									EventCore::RegisterGameObjectAsPlayer(gameObject, propertyValue, new WitchController());	
									if(propertyValue == 0)
										SetCameraTarget(gameObject);
								}
								else if(propertyName == "player"){
									GameObject* gameObject = GameObject::GetGameObject();
									EventCore::RegisterGameObjectAsPlayer(gameObject, propertyValue, new WitchController());	
									if(propertyValue == 0)
										SetCameraTarget(gameObject);
								}
								
							}
						}

                    }
					
                }
            }
        }
       
        return true; // Parsing succeeded
    
}
