/*
 * Error codes
 */

#ifndef XXH_ERROR_H
#define XXH_ERROR_H


extern int xxh_error;

enum {
	XXH_FAIL = 0,
	XXH_SUCCESS,
	XXH_INVALID_FILENAME,
	XXH_OUT_OF_MEMORY,
	XXH_RENDERER_INIT_FAIL,
	XXH_RESOURCE_MANAGER_INIT_FAIL
};


int xxhGetError();
#endif