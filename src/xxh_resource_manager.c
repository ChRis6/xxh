#include <stdlib.h>
#include <string.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

#include "xxh_resource_manager.h"
#include "xxh_error.h"


typedef struct RESOURCE_NODE{

	int type;
	char *filename;
	int refereces;
	void *data;
	struct RESOURCE_NODE* next;
	
}RESOURCE_NODE;


/* globals */
static RESOURCE_NODE* head;


/* function prototypes */
RESOURCE_NODE* insertResource(char *filename,int type );



/* Init */
int xxhInitResourceManager(){

	head = NULL;
	return XXH_SUCCESS;
}

/* free all resources */
void xxhDestroyResourceManager(){
	
	RESOURCE_NODE* tmp;

	while( head != NULL ){
		
		switch(head->type){
			case XXH_BITMAP:
				al_destroy_bitmap( (ALLEGRO_BITMAP*)head->data );
				break;
		}
		tmp = head->next;
		free(head);
		head = tmp;
	}
}


/*
 * Return a pointer to the requested resource.if
 * the resource is not in memory,load it and
 * return a pointer.
 * 
 * This function MUST always return a valid reference
 * to a resource,if the resource exists.
 *
 * Returns NULL when file isn't found.
 */
void* getResource(char *filename, int type){
	
	if( !filename ){
		xxh_error = XXH_INVALID_FILENAME;
		return NULL;
	}
	
	/* check if the file is in memory */
	RESOURCE_NODE *curr;
	
	for( curr = head ; curr != NULL; curr = curr->next){
	
		if( type == curr->type && ( !strcmp(filename,curr->filename)) ){
			curr->refereces++;
			return curr->data;
		}
	}
	/* resource is not in memory */	
	curr = insertResource(filename,type);
	if( curr != NULL )
		return curr->data;
		
	return NULL;
}


RESOURCE_NODE* insertResource(char *filename,int type){

	/* insert as the first element */
	RESOURCE_NODE *new = (RESOURCE_NODE*) malloc(sizeof(RESOURCE_NODE));
	if(!new){
		xxh_error = XXH_OUT_OF_MEMORY;
		return NULL;
	}
	new->filename = (char*) malloc(sizeof(char) * strlen(filename) + 1 );
	
	if( new->filename == NULL ){
		free(new);
		xxh_error = XXH_OUT_OF_MEMORY;
		return NULL;
	}	
	/* copy contents to the new node */
	strcpy(new->filename,filename);
	new->refereces = 1;
	new->type = type;
	
	
	/*
	 * load the resource.If the file is a bitmap,
	 * a display needs to be already created,so that the bitmap
	 * is hardware-accelerated.
	 */
	 
	 switch(type){
	 	case XXH_BITMAP:
	 		new->data = al_load_bitmap(filename);
	 		if(new->data == NULL ){
	 			xxh_error = XXH_INVALID_FILENAME;
	 			free(new);
	 			return NULL;
	 		}
	 		break;
	 	default:
	 		free(new);
	 		xxh_error = XXH_INVALID_FILENAME;
	 		return NULL;	 	
	 }
	
	/* link the new node */
	if( head == NULL){
		head = new;
		head->next = NULL;
	}
	else{
		new->next = head->next;
		head->next = new;
	}
	
	
	return new;
}



void xxhReleaseResource(char *filename,int type){
//TO DO
}