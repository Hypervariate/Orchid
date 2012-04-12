#include "GraphicsCore.h"

bool GraphicsCore::initialized = false;
ALLEGRO_DISPLAY* GraphicsCore::display;
//Fonts
//------------------
map<string, ALLEGRO_FONT*> GraphicsCore::fonts;	//archived fonts loaded at load-time
map<string, ALLEGRO_FONT*>::iterator GraphicsCore::fontIterator;
//------------------

Vector2DF GraphicsCore::scrollingOffset;
Vector2D GraphicsCore::mapTileDimensions;
Vector2D GraphicsCore::mapDimensions;

map<string, ALLEGRO_BITMAP*> GraphicsCore::m_images;

FileReader GraphicsCore::fileReader;


GraphicsCore::GraphicsCore(){}
GraphicsCore::~GraphicsCore(){}
void GraphicsCore::Initialize(){
	if(!initialized){
		//create display object
		display = NULL;
		display = al_create_display(WIDTH, HEIGHT);			

		//initialize modules
		al_init_primitives_addon();							
		al_init_font_addon();
		al_init_ttf_addon();
		al_init_image_addon();

		//load all font files located in fonts directory
		vector<string> fontFileNames;
		fileReader.GetAllFileNamesInDirectory(FONT_DIRECTORY, fontFileNames);
		for(int i = 0; i < fontFileNames.size(); i++)
			LoadFont(fontFileNames.at(i), 36);

		//load all images located in image directory
		vector<string> imageFileNames;
		fileReader.GetAllFileNamesInDirectory(IMAGE_DIRECTORY, imageFileNames);
		for(int i = 0; i < imageFileNames.size(); i++)
			LoadImage((char*)imageFileNames.at(i).c_str());

		
		
		
		initialized = true;
	}
}
void GraphicsCore::Deinitialize(){
	if(initialized){
	//destroy all fonts
	for(fontIterator=fonts.begin() ; fontIterator != fonts.end(); fontIterator++)
		al_destroy_font((*fontIterator).second);

	//shutdown modules
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();


	initialized = false;
	}
}
void GraphicsCore::Update()
{

	GraphicsCore::FlipDisplay();
	
}
void GraphicsCore::FlipDisplay(){
	
	al_flip_display();
	al_clear_to_color(al_map_rgb(0,0,0));		//enable when backbuffering has been implemented
	
}
void GraphicsCore::DrawRectangle(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_rectangle(x1-GetMapScrollingOffsetX(), y1-GetMapScrollingOffsetY(), x2-GetMapScrollingOffsetX(), y2-GetMapScrollingOffsetY(), al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_rounded_rectangle(x1-GetMapScrollingOffsetX(), y1-GetMapScrollingOffsetY(), x2-GetMapScrollingOffsetX(), y2-GetMapScrollingOffsetY(), rx, ry, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledRectangle(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_rectangle(x1-GetMapScrollingOffsetX(), y1-GetMapScrollingOffsetY(), x2-GetMapScrollingOffsetX(), y2-GetMapScrollingOffsetY(), al_map_rgb(r, g, b));
}
void GraphicsCore::DrawFilledRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_rounded_rectangle(x1-GetMapScrollingOffsetX(), y1-GetMapScrollingOffsetY(), x2-GetMapScrollingOffsetX(), y2-GetMapScrollingOffsetY(), rx, ry, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawLine(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_line(x1-GetMapScrollingOffsetX(), y1-GetMapScrollingOffsetY(), x2-GetMapScrollingOffsetX(), y2-GetMapScrollingOffsetY(), al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_triangle(x1-GetMapScrollingOffsetX(), y1-GetMapScrollingOffsetY(), x2-GetMapScrollingOffsetX(), y2-GetMapScrollingOffsetY(), x3-GetMapScrollingOffsetX(), y3-GetMapScrollingOffsetY(), al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_triangle(x1-GetMapScrollingOffsetX(), y1-GetMapScrollingOffsetY(), x2-GetMapScrollingOffsetX(), y2-GetMapScrollingOffsetY(), x3-GetMapScrollingOffsetX(), y3-GetMapScrollingOffsetY(), al_map_rgb(r, g, b));
}
void GraphicsCore::DrawCircle(float cx, float cy, float rad, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_circle(cx-GetMapScrollingOffsetX(), cy-GetMapScrollingOffsetY(), rad, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledCircle(float cx, float cy, float rad, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_circle(cx-GetMapScrollingOffsetX(), cy-GetMapScrollingOffsetY(), rad, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawEllipse(float cx, float cy, float rx, float ry, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_ellipse(cx-GetMapScrollingOffsetX(), cy-GetMapScrollingOffsetY(), rx, ry, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledEllipse(float cx, float cy, float rx, float ry, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_ellipse(cx-GetMapScrollingOffsetX(), cy-GetMapScrollingOffsetY(), rx, ry, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawSpline(float points[8], unsigned char r, unsigned char g, unsigned char b, float thickness){
	//doesn't work with scrolling
	al_draw_spline(points, al_map_rgb(r, g, b), thickness);
}
bool GraphicsCore::LoadFont(string font_name, unsigned int size)
{
    const unsigned int path_length = 256;
    char path[path_length];
    for(int i = 0; i < path_length; i++)
        path[i] = '\0';
    strcat(path, FONT_DIRECTORY);
    strcat(path, font_name.c_str());
    strcat(path, FONT_EXTENSION);
    
    cout << "\nLoading font \"" << path;
    ALLEGRO_FONT *font = al_load_font(path, size, 0);
    if(!font) {
        al_show_native_message_box(NULL, NULL, NULL, "failed to load font.", NULL, NULL);
        return false;
    }
    cout << "\" Success." << endl;
    fonts.insert( pair<string,ALLEGRO_FONT*>(font_name,font) );
    
    return true;
}
void GraphicsCore::PrintToDisplay(string text, int x, int y, string font, unsigned char r, unsigned char g, unsigned char b)
{
	fontIterator = fonts.find(font);
    if(fontIterator != fonts.end())
		al_draw_text((*fontIterator).second, al_map_rgb(r, g, b), x, y, 0, text.c_str());
	else if(fonts.size() > 0){
		fontIterator = fonts.begin();
		al_draw_text((*fontIterator).second, al_map_rgb(r, g, b), x, y, 0, text.c_str());
	}
}
void GraphicsCore::PrintToDisplay(int i, int x, int y, string font, unsigned char r, unsigned char g, unsigned char b)
{
	char buffer[32];
	itoa(i, buffer, 10);
	PrintToDisplay(buffer, x, y, font, r, g, b);
}
ALLEGRO_DISPLAY* GraphicsCore::GetDisplay(){
	if(initialized == false)
		GraphicsCore::Initialize();
	return display;
}
void GraphicsCore::BlitImage(string index, int x, int y){

	// CULLING - don't draw the object if it's not in view
	if( x-GetMapScrollingOffsetX() < 0		||
		x-GetMapScrollingOffsetX() > WIDTH	||
		y-GetMapScrollingOffsetY() < 0		||
		y-GetMapScrollingOffsetY() > HEIGHT) 
	return;


	char* name = (char*)index.c_str();
	bool success = true;
	if(m_images[name] == NULL)
		success = LoadImage(name);
	if(!success){
		return;
	}
	al_draw_bitmap(m_images[name], x-GetMapScrollingOffsetX(), y-GetMapScrollingOffsetY(), 0);	
	
}

void GraphicsCore::BlitImageRegion(int sx, int sy, int w, int h, int dx, int dy, string image_name){

	//// CULLING - don't draw the object if it's not in view
	//if( dx-GetMapScrollingOffsetX() < 0		||
	//	dx-GetMapScrollingOffsetX() > WIDTH	||
	//	dy-GetMapScrollingOffsetY() < 0		||
	//	dy-GetMapScrollingOffsetY() > HEIGHT) 
	//return;


	const char* name = image_name.c_str();
	bool success = true;
	if(m_images[name] == NULL)
		success = LoadImage((char*)name);
	if(!success){
		return;
	}
	al_draw_bitmap_region(m_images[name], sx, sy, w, h, dx, dy, 0);

}
bool GraphicsCore::LoadImage(char* image_name)
{
	//check if image already exists
	if(m_images[image_name] != NULL)
	{
		ALLEGRO_BITMAP* bitmap = m_images[image_name];
        al_destroy_bitmap(bitmap);
        bitmap=NULL;
	}

	char path[MAX_PATH_LENGTH];

	for(int i = 0; i < MAX_PATH_LENGTH; i++)
		path[i] = '\0';

	strcat(path, IMAGE_DIRECTORY);
	strcat(path, image_name);
	strcat(path, IMAGE_EXTENSION);

	ALLEGRO_BITMAP *bitmap = NULL;
	bitmap = al_load_bitmap(path);
	if ( !bitmap )
    {
      cout << "img load failed: " <<  path << endl;
      return false;
    }
	m_images[image_name] = bitmap;

	return true;
}
float GraphicsCore::GetMapScrollingOffsetX(){
	return scrollingOffset.x;
}
float GraphicsCore::GetMapScrollingOffsetY(){
	return scrollingOffset.y;
}
void GraphicsCore::SetMapScrollingOffsetX(int x){
	scrollingOffset.x = x;

	//avoid scrolling beyond the map edge
	if (scrollingOffset.x < 0) scrollingOffset.x = 0;
	if (scrollingOffset.x > (mapDimensions.x * mapTileDimensions.x - WIDTH))
		scrollingOffset.x = mapDimensions.x * mapTileDimensions.x - WIDTH;
	
}
void GraphicsCore::SetMapScrollingOffsetY(int y){
	scrollingOffset.y = y;

	if (scrollingOffset.y < 0) 
		scrollingOffset.y = 0;
	if (scrollingOffset.y > (mapDimensions.y * mapTileDimensions.y - HEIGHT)) 
		scrollingOffset.y = mapDimensions.y * mapTileDimensions.y - HEIGHT;
}
void GraphicsCore::SetMapTileDimensions(int x, int y){
	mapTileDimensions.x = x;
	mapTileDimensions.y = y;
}
void GraphicsCore::SetMapDimensions(int x, int y){
	mapDimensions.x = x;
	mapDimensions.y = y;
}