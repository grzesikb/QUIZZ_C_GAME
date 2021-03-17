#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/mouse.h>

void must_init(bool test, const char* description)
{
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 1.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
    must_init(disp, "display");
    al_set_window_position(disp, 0, 0);
    al_set_window_title(disp, "QUIZZ GAME :)");


    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");
    must_init(al_install_mouse(), "mouse");
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;
    bool redraw = true;
    int x = 10, y = 10, spin = 0, flag = 1;
    char c1[] = "ala ma kota";
    char c2[] = "ala nie ma kota";
    char* c0;
    ALLEGRO_EVENT event;
    ALLEGRO_COLOR set0 = al_map_rgb(1, 1, 1);
    ALLEGRO_COLOR set1 = al_map_rgb(100, 100, 100);
    ALLEGRO_COLOR set2 = al_map_rgb(1, 1, 1);

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = event.mouse.x;
            y = event.mouse.y;
            printf(" %d  %d ", x, y);
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }
        if ((x > 240 && x < 340) && (y > 260 && y < 340)) {
            set0 = set1;
            //redraw = true;
        }
        else {
            set0 = set2;
            redraw = true;
        }
        if (spin == 300) flag = 0;
        if (spin < 300 && flag) {
            spin++;
        }
        else spin--;
        if (spin == 0) flag = 1;
        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Ala ma kota");
            al_draw_filled_triangle(35, 350, spin, 375, 35, 400, al_map_rgb_f(0, 1, 0));
            al_draw_filled_rectangle(240, 260, 340, 340, set0);
            al_draw_circle(x, y, 30, al_map_rgb_f(1, 0, 1), 2);
            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}