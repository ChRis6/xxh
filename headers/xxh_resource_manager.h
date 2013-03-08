

#ifndef XXH_RESOURCE_MANAGER_H
#define XXH_RESOURCE_MANAGER_H

enum {
	XXH_BITMAP = 0,
	XXH_FONT	
};

int xxhInitResourceManager();
void xxhDestroyResourceManager();
void xxhReleaseResource(char *filename,int type);
void* getResource(char *filename, int type);
#endif