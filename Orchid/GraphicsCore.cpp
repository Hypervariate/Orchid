#include "GraphicsCore.h"

bool GraphicsCore::initialized = false;
ALLEGRO_DISPLAY* GraphicsCore::display;
//Fonts
//------------------
map<string, ALLEGRO_FONT*> GraphicsCore::fonts;	//archived fonts loaded at load-time
map<string, ALLEGRO_FONT*>::iterator GraphicsCore::fontIterator;
//------------------


GraphicsCore::GraphicsCore(){}
GraphicsCore::~GraphicsCore(){}
void GraphicsCore::Initialize(){
	if(!initialized){
		//create display object
		ALLEGRO_DISPLAY* display = NULL;
		display = al_create_display(WIDTH, HEIGHT);			

		//initialize modules
		al_init_primitives_addon();							
		al_init_font_addon();
		al_init_ttf_addon();
		
		//load fonts
		LoadFont("acknowledge", 36);

		
		
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
	al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_rounded_rectangle(x1, y1, x2, y2, rx, ry, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledRectangle(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawFilledRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_rounded_rectangle(x1, y1, x2, y2, rx, ry, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawLine(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_line(x1, y1, x2, y2, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawCircle(float cx, float cy, float rad, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_circle(cx, cy, rad, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledCircle(float cx, float cy, float rad, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_circle(cx, cy, rad, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawEllipse(float cx, float cy, float rx, float ry, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_ellipse(cx, cy, rx, ry, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledEllipse(float cx, float cy, float rx, float ry, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_ellipse(cx, cy, rx, ry, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawSpline(float points[8], unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_spline(points, al_map_rgb(r, g, b), thickness);
}
bool GraphicsCore::LoadFont(string font_name, unsigned int size)
{
    const unsigned int path_length = 256;
    char path[path_length];
    for(int i = 0; i < path_length; i++)
        path[i] = '\0';
    strcat(path, "Data/Fonts/");
    strcat(path, font_name.c_str());
    strcat(path, ".ttf");	
    
    cout << "\nLoading font \"" << path;
    ALLEGRO_FONT *font = al_load_font(path, size, 0);
    if(!font) {
        al_show_native_message_box(NULL, NULL, NULL, "failed to load font.", NULL, NULL);
        return false;
    }
    cout << "\" Success.";
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
