#include <stdio.h>
#include "xxh_renderer.h"
#include "xxh_error.h"

static ALLEGRO_DISPLAY *display = NULL;
static int fps = 0;
int xxhInitRenderer(){
	
	/*
	 * First set up some flags 
	 */
	//al_set_new_display_flags(ALLEGRO_NOFRAME);
	
	/* create the actual window */
	display = al_create_display(XXH_WINDOW_WIDTH,XXH_WINDOW_HEIGHT);
	if( !display )
		return XXH_FAIL;
	
	return XXH_SUCCESS;
}

void xxhDestroyRenderer(){

	if( display != NULL )
		al_destroy_display(display);
}

/*
 * Before swapping front and back buffer,
 * we count how many times al_flip_display() is called
 * in one second.
 *
 * That way we count fps.
 */
void xxhFlushFrame(){
	static int frames_counted = 0;
	static double last_time_frame_counted = 0.0;
	
	frames_counted++;
	
	if( al_get_time() - last_time_frame_counted  > 1.0 ){
		fps = frames_counted;
		frames_counted = 0;
	}
	al_flip_display();
	last_time_frame_counted = al_get_time();
}

/*
 * Returns how many frames were drawn
 * during the last second
 */
int xxhGetFramesPerSecond(){
	return fps;
}