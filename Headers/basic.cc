#include "basic.hh"

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip=NULL) {
	SDL_Rect offset;
	offset.x=x;
	offset.y=y;
    SDL_BlitSurface(source, clip, destination, &offset);
}

SDL_Surface* load_image(string filename) {
	SDL_Surface* loadedImage=NULL;
	SDL_Surface* optimizedImage=NULL;

	loadedImage=IMG_Load(filename.c_str());
	if(loadedImage!=NULL) {
		optimizedImage=SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
		if(optimizedImage!=NULL) {
			Uint32 colorkey=SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
		}
	}
	return optimizedImage;
}

bool start_SDL() {
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1 || TTF_Init()==-1) {
		return false;
	}
	
	SDL_EnableUNICODE(SDL_ENABLE);

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if( screen == NULL ) {
		return false;
	}
	SDL_WM_SetCaption("Sudoku solver", NULL);

	return true;
}

bool load_files() {
	
	return true;
}

void clean_up() {
	TTF_CloseFont(font);

	SDL_EnableUNICODE(SDL_DISABLE);
	TTF_Quit();
	SDL_Quit();
}
