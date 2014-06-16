#ifndef basic
#define basic

#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;
const int SCREEN_BPP=32;

extern SDL_Surface* screen;
extern SDL_Surface* text;

extern TTF_Font* font;

extern SDL_Event event;
extern SDL_Color textColor;

SDL_Surface* load_image(string filename);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
bool load_files();
bool start_SDL();
void clean_up();

#endif
