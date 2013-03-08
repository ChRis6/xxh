#include "xxh_engine.h"

/* global variables declared at xxh_engine.h */
int xxh_key[XXH_NUM_KEYS];


/* 
 * Here is the implementation of the functions
 * declared at the header file xxh_engine.h
 *
 * Private/static methods used by the file xxh_engine.c must be
 * defined at the end.
 */


/*
 * Must be called before any other xxh*() functions.
 */ 
int xxhInit(){
	int flag;
	int i;
	
	/* init allegro */
	if(!al_init()){
		
		return XXH_FAIL;
	}
	
	/*
	 * init resource manager
	 */
	flag = xxhInitResourceManager();
	if( flag != XXH_SUCCESS ){
		xxh_error = XXH_RESOURCE_MANAGER_INIT_FAIL;
		return XXH_FAIL;
	}
	
	/*
	 * Renderer
	 */
	flag = xxhInitRenderer();
	if( flag != XXH_SUCCESS ){
		xxh_error = XXH_RENDERER_INIT_FAIL;
		return XXH_FAIL;
	}
	al_install_keyboard();
	al_init_image_addon();
	
	
	/* 
	 * Initialise keys.All keys are set to 
	 * false.No key is assumed to be pressed
	 * when xxhInit() returns.
	 */
	 for( i = 0; i < XXH_NUM_KEYS; i++)
	 	xxh_key[i] = 0; 
	
	
	return XXH_SUCCESS;
}

/*
 * makes a clean up.
 *
 */
void  xxhDestroy(){

	/* Destroy resource manager */
	xxhDestroyResourceManager();
	
	/*destroy renderer */
	xxhDestroyRenderer();
	
	/* destroy allegro */
	return;
}






/*
 * Private/static methods of the file xxh_engine.c
 */
 
 
  