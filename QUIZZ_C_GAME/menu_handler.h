
bool init_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** bg, unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS)
{
	al_draw_bitmap(*bg, 0, 0, 0);
	al_flip_display();

}