#include "Headers/basic.hh"
#include "Headers/generate.hh"

string num_of_tasks;
SDL_Surface* screen;
SDL_Surface* text;
SDL_Color textColor={0, 0, 0};
SDL_Surface* numbers;
TTF_Font* font;
SDL_Event event;
vector<string> task_rows;
vector<string> results;

void apply_all() {
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 180, 180, 180));
	apply_surface(0, 0, text, screen, NULL);
	apply_surface(275, 0, numbers, screen, NULL);
}

bool handle_events() {
	bool change=false;

	if(event.type==SDL_KEYDOWN) {
		if(event.key.keysym.unicode>=(Uint16)'0' && event.key.keysym.unicode<=(Uint16)'9') {
			num_of_tasks+=event.key.keysym.unicode;
			change=true;
		} else if(event.key.keysym.sym==SDLK_BACKSPACE) {
			if(num_of_tasks.size()>0) {
				num_of_tasks.erase(num_of_tasks.size()-1);
				change=true;
			}
		} else if(event.key.keysym.sym==SDLK_RETURN) {
			write_files_for_ruby(atoi(num_of_tasks.c_str()));
			system("ruby html_creator.rb -w");
			return false;
		}
		
		if(change) {
			numbers=TTF_RenderText_Solid(font, num_of_tasks.c_str(), textColor);
		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));
	bool running=true;
	num_of_tasks="";
	numbers=TTF_RenderText_Solid(font, num_of_tasks.c_str(), textColor);
	
	if(!start_SDL() || !load_files()) {
		return -1;
	}
	
	apply_all();
	while(running) {
		if(SDL_PollEvent(&event)) {
			if(event.type==SDL_QUIT) {
				break;
			}
			
			running=handle_events();
			apply_all();
		}
		SDL_Flip(screen);
		SDL_Delay(2);
	}
	
	clean_up();
	return 0;
}
