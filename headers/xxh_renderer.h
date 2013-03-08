#ifndef XXH_RENDERER_H
#define XXH_RENDERER_H

#include <allegro5/allegro.h>

#define XXH_WINDOW_WIDTH  640
#define XXH_WINDOW_HEIGHT 480

int xxhInitRenderer();
void xxhDestroyRenderer();
void xxhFlushFrame();
int xxhGetFramesPerSecond();

#endif