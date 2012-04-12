#include "TiledLevel.h"

TiledLevel::TiledLevel(){
	cellDimensions.Set(0,0);
	mapDimensions.Set(0,0);

}
TiledLevel::~TiledLevel(){
	Unload();
}
bool TiledLevel::Load(char* levelName, GameObject* cameraTarget){

	char path[MAX_PATH_LENGTH];

	for(int i = 0; i < MAX_PATH_LENGTH; i++)
		path[i] = '\0';

	strcat(path, LEVEL_DIRECTORY);
	strcat(path, levelName);
	strcat(path, LEVEL_EXTENSION);

	bool successful = false;
	if(parseTMXFile(path))
		successful = true;
	
	GraphicsCore::SetMapDimensions(0, 0);
	GraphicsCore::SetMapTileDimensions(0, 0);

	this->cameraTarget = cameraTarget;
	return successful;
}
void TiledLevel::Draw(){
	//not supported yet
	/*int tile = 0;
	for(int i = 0; i < cells.GetSizeX(); i++)
		for(int j = 0; j < cells.GetSizeY(); j++){
				tile = cells.GetCell(i,j);
				GraphicsCore::BlitImageRegion(
					tile * cellDimensions.x,
					tile * cellDimensions.y,
					cellDimensions.x,
					cellDimensions.y,
					0 * cellDimensions.x,
					0 * cellDimensions.y,
					"tmw_desert_spacing"
				);
			}*/
}
void TiledLevel::Unload(){
	
}
void TiledLevel::Update(){
	//not supported yet
	/*GraphicsCore::SetMapScrollingOffsetX(cameraTarget->GetX() + cameraTarget->GetHalfOfWidth());
	GraphicsCore::SetMapScrollingOffsetX( GraphicsCore::GetMapScrollingOffsetX() - WIDTH/2);

	GraphicsCore::SetMapScrollingOffsetY(cameraTarget->GetY() + cameraTarget->GetHalfOfHeight());
	GraphicsCore::SetMapScrollingOffsetY( GraphicsCore::GetMapScrollingOffsetY() - HEIGHT/2);*/
}
const bool TiledLevel::parseTMXFile(const std::string &filename)
{            
        
		boost::property_tree::ptree pt;
        boost::property_tree::xml_parser::read_xml(filename, pt);
       
        mapDimensions.x		 = pt.get<int>( "map.<xmlattr>.width", 0 );
        mapDimensions.y		 = pt.get<int>( "map.<xmlattr>.height", 0 );
        cellDimensions.x	 = pt.get<int>( "map.<xmlattr>.tilewidth", 0 );
        cellDimensions.y	 = pt.get<int>( "map.<xmlattr>.tileheight", 0 );

		cells.AllocateSquareGrid(mapDimensions.x, mapDimensions.y);
		GraphicsCore::SetMapDimensions(mapDimensions.x, mapDimensions.y);
		GraphicsCore::SetMapTileDimensions(cellDimensions.x, cellDimensions.y);


        BOOST_FOREACH( boost::property_tree::ptree::value_type &v, pt.get_child("map") )
        {
            if(v.first == "layer")
            {                
                LayerData layer;
                layer.name    = v.second.get<std::string>("<xmlattr>.name");               
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
                       
                        int cell_x = o.second.get<int>( "<xmlattr>.x" );
                       
                        int cell_y = o.second.get<int>( "<xmlattr>.y" );
                       
						//objects not supported yet
                        //group.v_objects.push_back( object );
                    }
                }
				//objects not supported yet
                //objectgroups_data.push_back( group );
            }
        }
       
        return true; // Parsing succeeded
    
}