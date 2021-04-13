#include "STATUS.h"
#include "init_structures.h"
#include "data_structures_wizard.h"
#include "load_game_file.h"
#include "allegro_lib_handler.h"
#include "menu_handler1.h"


// ____CONSTANTS____ //
const float FPS = 30.0;
const int no_option = 3;
unsigned int resolution_x = 1920;
unsigned int resolution_y = 1080;

// ____FUNCTION SECTION____ //



int main() {
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_BITMAP* background = NULL;

	
    //allegro_game_init(&timer, &display, &queue, &font, &background, &resolution_x, &resolution_y, &FPS);
    load_saved_info();
    scan_file();
	//init_menu(&timer, &display, &queue, &font, &background, &resolution_x, &resolution_y, &FPS);
    al_rest(15.0);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}