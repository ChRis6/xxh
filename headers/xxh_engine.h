/* XXH  is a 2D tile based engine.
 *
 * - Engine functions have the prefix -xxh-
 * - Separate words in functions with uppercase letters
 *   instead of underscore ( '_')
 *
 * - Use '_' for variable names
 * - User uppercase letters for struct names and constant variables
 */
 
#ifndef XXH_ENGINE_H
#define XXH_ENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>


#include "xxh_renderer.h"
#include "xxh_resource_manager.h"
#include "xxh_error.h"


enum {
	XXH_KEY_UP = 0,
	XXH_KEY_DOWN,
	XXH_KEY_RIGHT,
	XXH_KEY_LEFT,
	XXH_KEY_SPACE,
	XXH_KEY_ESC,
	
	/* Write more keys before this entry*/
	XXH_NUM_KEYS
};


extern int xxh_key[XXH_NUM_KEYS];
/*
 * Initialiases the engine.Returns XXH_FAIL on failure
 */
int xxhInit();

/*
 * Clean up engine.
 */
void xxhDestroy();
#endif