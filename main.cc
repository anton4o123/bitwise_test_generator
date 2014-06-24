#include "Headers/basic.hh"
#include "Headers/generate.hh"

string num_of_tasks;
string points;

SDL_Surface* screen;
SDL_Surface* text;
SDL_Surface* numbers;
SDL_Surface* manual;
SDL_Surface* indication_msg;

SDL_Color textColor={0, 0, 0};
TTF_Font* font;
SDL_Event event;
SDL_Thread* thread;

vector<string> task_rows;
vector<string> results;

void apply_all() {
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 180, 180, 180));
	apply_surface(0, 0, text, screen, NULL);
	apply_surface(275, 0, numbers, screen, NULL);
	apply_surface(0, 20, manual, screen, NULL);
	apply_surface(0, 40, indication_msg, screen, NULL);
}

void erase_last_four_elems_of_points() {
	for(short i=0;i<4;++i) {
		points.erase(points.size()-1);
	}
}

int indication(void* data) {
	while(true) {
		points+=".";
		indication_msg=TTF_RenderText_Solid(font, points.c_str(), textColor);
		if(points.size()==14) {
			erase_last_four_elems_of_points();
		}
		SDL_Delay(500);
		apply_all();
		SDL_Flip(screen);
	}
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
			thread=SDL_CreateThread(indication, NULL);
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
	points="Generating";
	numbers=TTF_RenderText_Solid(font, num_of_tasks.c_str(), textColor);
	
	if(!start_SDL() || !load_files()) {
		return -1;
	}
	
	system("rm -rf web/");
	
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
