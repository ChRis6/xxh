#include <stdio.h>
#include <allegro5/allegro.h>
#include "xxh_engine.h"


int main ( int argc,char *argv[]){
	
	int res;
	
	/* init*/
	res = xxhInit();
	if( res != XXH_SUCCESS){
		printf("xxh failed to init..\n");
		return -1;
	}
	
	xxhFlushFrame();
	al_rest(5);
	
	/* free memory and return */
	xxhDestroy();

	return 0;
}

