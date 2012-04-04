A5 Allegro, version 1

DISCLAIMER:

 This software and associated files are provided 'as is'
with no warranty or guarantees of any kind, you use them
at your own risk and in doing so agree that the author is
in no way liable and cannot be held responsible for any
loss of time/data/hair or anything else that may occur
either directly or indirectly from the use of this
software or associated files.

==============================================
http://www.tilemap.co.uk

Allegro 5 converted by Neil Walker

C++ notes: MappyAL will work fine with C++, but the file 'mappyal.c'
must be compiled as 'C'. With MSVC there is no problem as it uses
the filename extension (.c/.cpp) to determine how to compile, but
IDE's like DevC++ and VIDE don't do this with C++ projects, so 
instead of adding mappyal.c to your list of sourcefiles (like with 
MSVC) be sure you have mappyal.o by manually compiling with:

gcc mappy_A5.c -O2 -Wall -c -o mappy_A5.o

then adding mappy_A5.o to the compiler

Please report any bugs!


Function reference:
-------------------------------------------------
IMPORTANT: You must have initialised allegro first. See the demo.

Quick list:
MAPS
  MapLoad : load a map from file
  MapDecode : load a map from memory
  MapFreeMem : frees up all memory. must be called on exit
  MapMakeParallaxBitmap : make a parallax bitmap for the map
  MapChangeLayer : change map layer. mappy supports 8 different layers
  MapUpdateAnims: update map animations
  
DRAWING:
  MapDrawBG : draw the background tile from the current map layer
  MapDrawFG : draw foreground tiles (layer 1,2,3) from the current map layer
  MapDrawParallax: draw the parallax layer (call this first before BG and FG!)
  
BLOCKS/TILES:
  MapGetBlock/MapGetBlockInPixels: get a block/tile from a given location
  MapSetBlock/MapSetBlockInPixels: set a block at a given position to be a new block type
  
OTHER STUFF
  MapRestore: regenerate bitmaps (in case of loss through video switching in windows)
  MapLoadMAR: load a .mar file (cut-down map file)
  MapDrawRow: row by row drawing, needed for isometric
  MapGetXOffset/MapGetYOffset: handy for translating pixel to block co-ordinates

-------------------------------------------------

int MapLoad (char * mapname, int converttoalpha);

mapname: filename, e.g. "test.fmp"
converttoalpha: if 8bpp then 'magic pink' or index 0 will be converted to alpha
                if any other resolution then black or 'magic pink' will be converted to alpha
                
Uses allegro file functions so physfs is supported.

Default uses default allegro bitmaps, i.e. video. If the call fails you need to set new bitmaps to MEMORY then load

The array abmTiles is available and points to each tile graphic, 
eg. if you want to get at the third BITMAP, use abmTiles[2]. 

-------------------------------------------------
int MapDecode (unsigned char * mapmempt,int converttoalpha);

Same as MapLoad, but loads from an area of memory containing an FMP file.
(Useful if your maps are stored compressed, just uncompress to memory and
call MapDecode).

-------------------------------------------------
void MapRestore (void);

Restores the graphics to video bitmaps in hardware rendering.
Useful in Windows that loses video memory on app switching.
However A5 attempts to recover these for you so the function may not be that useful

-------------------------------------------------
void MapFreeMem (void);

When you've had enough of the map, this frees all the memory mappypb
has used.MapLoad and MapDecode call this so no need if loading a new map.

-------------------------------------------------
int MapLoadMAR (char * filename, int layer);
int MapDecodeMAR (unsigned char * marmemory, int layer);

Loads a .MAR file into a specified layer. Decode does it from memory, 
you can dealloc that memory afterwards. If you called MapGenerateYLookup,
call it again after this function. Returns -1 on error, 0 on success.

MAR files are like FMP map files but without the graphics, animation, etc.
i.e. they are simple boxed arrays storing tile numbers

-------------------------------------------------
void MapDrawBG (int mapxo, int mapyo, int mapx, int mapy,
	int mapw, int maph);

Draws the blocks referenced in bgoff. Will clip the map to the specified area.
Note: the normal clipping on the bitmap is ignored, so trying to draw off the
edges of a bitmap will crash your programme.

Draws to the current target bitmap, i.e. you need to set this, or just leave it alone
if using standard backbuffer

Refer to mapload for drawing of transparent areas (i.e. alpha channels)

int mapxo           offset, in pixels, from left edge of map, this is
                    the first visible column of pixels you are drawing
int mapyo           offset, in pixels, from top edge of map, this is
                    the first visible row of pixels you are drawing
int mapx            offset, in pixels, from left edge of bitmap
int mapy            offset, in pixels, from top edge of bitmap
int mapw            width of area you want to draw
int maph            height of area you want to draw

-------------------------------------------------
void MapDrawFG (int mapxo, int mapyo, int mapx, int mapy,
	int mapw, int maph, int mapfg);

Same as MapDrawBG, except:

int mapfg           The foreground layer you want to draw, 0, 1, or 2

-------------------------------------------------
void MapDrawRow (int mapxo, int mapyo, int mapx, int mapy,
	int mapw, int maph, int maprw, void (*cellcall) (int cx, int cy, int dx, int dy))

Same as MapDrawBG, except:

int maprw is the row to draw
cellcall is a callback function for each cell, pass NULL if you are doing your
own depth sorting, or using another system
see demo for an example of this in ISOMETRIC test

-------------------------------------------------
BITMAP * MapMakeParallaxBitmap (BITMAP * sourcebm);

Only on regular rectangular maps.
Pass a bitmap you would like to use for the parallax bitmap. 

You must use this function to make the bitmap you pass to MapDrawParallax.
The source bitmap MUST be a multiple of your block size (ie if you are
using 32*32 blocks, 128*128 and 96*64 are valid, but 100*100 is not).

-------------------------------------------------
void MapDrawParallax (BITMAP * parbm, int mapxo, int mapyo, int mapx, int mapy,
	int mapw, int maph);

This behaves like MapDrawBG etc, except the 'parbm' bitmap is created
with 'MapMakeParallaxBitmap' and this is tiled in the transparent
regions of the map. 

This is more efficient than drawing the whole screen as it only draws
in areas not obscured by higher layers, there is minimal overdraw
(pixels aren't overwritten by higher layers where possible).

-------------------------------------------------
int MapChangeLayer (int)

This changes to a different map layer, returns -1 if failed, or the new
layer number if success. See mpgame.c

-------------------------------------------------
int MapGetXOffset (int x, int y)
int MapGetYOffset (int x, int y)

These functions are handy for translating a pixel coordinate to block
coordinates, especially for non-rectangular blocks (see mousecrd.c).

-------------------------------------------------
BLKSTR * MapGetBlockInPixels (int x, int y)

Returns a BLKSTR pointer, useful for collision detection and examining a
blockstructure. This is more useful on non-rectangular maps as it is pixel
perfect.

-------------------------------------------------
BLKSTR * MapGetBlock (int x, int y);

Returns a BLKSTR pointer, useful for collision detection and examining a
blockstructure. Note: the x and y paramaters are the offset from the left
and top of the map in _BLOCKS_ NOT pixels. See mpgame.c for an example.

-------------------------------------------------
void MapSetBlockInPixels (int x, int y, int strvalue)

The x and y paramaters are the offset from the left and top of the map
in pixels. If strvalue is positive, the cell is set to that block structure.
If strvalue is negative the cell is set to that anim structure-1 (ie if
you want to put anim 3 in, strvalue would be -4).

-------------------------------------------------
void MapSetBlock (int x, int y, int strvalue);

The x and y paramaters are the offset from the left and top of the map
in _BLOCKS_ NOT pixels. See mpgame.c for an example. If strvalue is
positive, the cell is set to that block structure. If strvalue is
negative the cell is set to that anim structure-1 (ie if you want to
put anim 3 in, strvalue would be -4).
-------------------------------------------------
int MapGenerateYLookup (void);

This is now called for you on MapLoad and is not required, however for an explanation:

It will generate a lookup table that _may_ slightly speed up the functions
MapGetBlock and MapSetBlock, and allows you to use the maparraypt. If you
use this, you _must_ use MapChangeLayer if you want to swap between layers.
Another advantage is you can access block or anim offsets simply with:
maparraypt[y][x];
Where x is the offset from the left in _BLOCKS_, and y is the offset from
the top in _BLOCKS_. Note you can get the actual block structure with the
functions MapGetBlock and MapSetBlock.
The memory allocated is freed when either MapFreeMem is called, or another
map is loaded.

-------------------------------------------------
int MapGetBlockID (int blid, int usernum)

returns the number of the first block that matches 'blid' in the field 
specified with usernum (1 to 7, user1 to user7). If no match, returns -1



-------------------------------------------------
void MapInitAnims (void);

Call to reset the animated blocks to their defaults
Called on loading of a map for you

-------------------------------------------------
void MapUpdateAnims (void);

Animation control. Call from your game loop, moves blocks to next anim
Animations are set up in the map editor


Don't forget to look at the example source code, I've documented them.


Version Changes:
================

version 1.