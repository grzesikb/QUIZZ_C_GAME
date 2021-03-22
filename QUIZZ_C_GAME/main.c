#include "allegro_lib_handler.h"

// ____CONSTANTS____ //
const float FPS = 30.0;
const int no_option = 3;
unsigned int resolution = 1920;
// ____FUNCTION SECTION____ //







int main(void) {
    ALLEGRO_TIMER* timer = NULL;
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_BITMAP* background = NULL;
    allegro_init(&timer, &display, &queue, &font, &background, &resolution, &FPS);
    al_rest(15.0);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}