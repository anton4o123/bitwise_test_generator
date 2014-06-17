#include "Headers/basic.hh"
#include "Headers/generate.hh"

SDL_Surface* screen;
SDL_Surface* text;
TTF_Font* font;
SDL_Event event;
SDL_Color textColor={0, 0, 0};
vector<string> task_rows;

void apply_all() {
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 180, 180, 180));
	apply_surface(0, 0, text, screen, NULL);
}

int main() {
	srand((unsigned)time(NULL));
	int number_of_tests=1;
	/*
	if(!start_SDL() || !load_files()) {
		return -1;
	}
	
	apply_all();
	while(true) {
		if(SDL_PollEvent(&event)) {
			if(event.type==SDL_QUIT) {
				break;
			}
			apply_all();
		}
		SDL_Flip(screen);
		SDL_Delay(2);
	}
	
	clean_up();
	*/
	generate_a_b(true);
	for(int i=0;i<task_rows.size();++i) {
		cout << task_rows[i] << endl;
	}
	cout << endl;
	
	generate_a_b(false);
	for(int i=0;i<task_rows.size();++i) {
		cout << task_rows[i] << endl;
	}
	
	generate_logic_and_xor(false);
	for(int i=0;i<task_rows.size();++i) {
		cout << task_rows[i] << endl;
	}
	
	return 0;
}
