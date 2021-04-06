
/// <summary>
/// CHECKS WHAT ELEMENT WAS CLICKED 
/// </summary>
/// <param name="mouse_x">POINTER TO MOURSE HORICONTAL POSITION</param>
/// <param name="mouse_y">POINTER TO MOUSE VERTICAL POSITION</param>
/// <returns>
/// SINGLE-PLAYER: 1
/// MULTIPLE-PLAYER: 2
/// ADD NEW QUESTION: 3
/// EXIT: 4
/// UNDEFINDED: 5
/// </returns>
int check_event_click(unsigned int* mouse_x, unsigned int* mouse_y)
{
	if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 395) && (*mouse_y <= 607))) return 1; // jednoosobowy
	if (((*mouse_x >= 294) && (*mouse_x <= 782)) && ((*mouse_y >= 635) && (*mouse_y <= 847))) return 2; // wieloosobowy
	if (((*mouse_x >= 813) && (*mouse_x <= 1129)) && ((*mouse_y >= 396) && (*mouse_y <= 847))) return 3; // dodaj pytanie
	if (((*mouse_x >= 1159) && (*mouse_x <= 1619)) && ((*mouse_y >= 586) && (*mouse_y <= 847))) return 4; // wyjscie
}
/// <summary>
///	MENAGES FORWARDING TO OPTIONS
/// </summary>
/// <param name="check_returned">TYPE OF EVENT WHICH WAS CLICKED</param>
void forwarding(const int check_returned)
{
	switch(check_returned)
	{
	case 1:
	printf("jedonosobowy");
	break;
	case 2:
	printf("wieloosobowy");
	break;
	case 3:
	printf("dodaj pytanie");
	break;
	case 4:
	printf("wyjscie");
	break;
	}
}
/// <summary>
/// LISTENS TO MOUSE CLICK EVENT 
/// </summary>
/// <param name="timer">POINTER TO TIMER</param>
/// <param name="display">POINTER TO DISPLAY</param>
/// <param name="queue">POINTER TO QUEUE</param>
/// <param name="font">POINTER TO FONT</param>
/// <param name="bg">POINTER TO BACKGROUND</param>
/// <param name="resolution_x">POINTER TO HORIZONTAL RESOLUTION</param>
/// <param name="resolution_y">POINTER TO VERTICAL RESOLUTION</param>
/// <param name="FPS">POINTER TO FPS FLOAT VALUE</param>
/// <returns>NOTHING</returns>
void listener(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_BITMAP** bg, unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS)
{
	ALLEGRO_EVENT event;
	bool done = false;
	bool redraw = false;
	int check_returned;
	unsigned int mouse_x, mouse_y, mouse_click;
	while (1)
	{
		al_wait_for_event(*queue, &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
			must_init(check_returned=check_event_click(&mouse_x, &mouse_y), "check position");
			forwarding(check_returned);
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		default: break;
		}
		if (done) break;
		
	}
}
/// <summary>
/// INICIALIZES MAIN MENU
/// </summary>
/// <param name="timer">POINTER TO TIMER</param>
/// <param name="display">POINTER TO DISPLAY</param>
/// <param name="queue">POINTER TO QUEUE</param>
/// <param name="font">POINTER TO FONT</param>
/// <param name="bg">POINTER TO BACKGROUND</param>
/// <param name="resolution_x">POINTER TO HORIZONTAL RESOLUTION</param>
/// <param name="resolution_y">POINTER TO VERTICAL RESOLUTION</param>
/// <param name="FPS">POINTER TO FPS FLOAT VALUE</param>
/// <returns>TRUE IF MAIN MENU HAS BEEN INICIALIZED</returns>
bool init_menu(ALLEGRO_TIMER** timer, ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_FONT** font, ALLEGRO_BITMAP** bg, unsigned int* resolution_x, unsigned int* resolution_y, const float* FPS)
{
	al_draw_bitmap(*bg, 0, 0, 0);
	al_flip_display();
	listener(timer, display, queue, bg, resolution_x, resolution_y, FPS);
	
}