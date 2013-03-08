CC=gcc
FLAGS= -lallegro -lallegro_main -lallegro_image
INCLUDE_DIR = headers/
BUILD_DIR = build

OUT= game
OBJS = $(BUILD_DIR)/game.o $(BUILD_DIR)/xxh_engine.o $(BUILD_DIR)/xxh_resource_manager.o \
	$(BUILD_DIR)/xxh_error.o $(BUILD_DIR)/xxh_renderer.o
all:game

game: $(OBJS)
	$(CC) -o $(OUT) build/*.o $(FLAGS)

$(BUILD_DIR):
	mkdir -p $@

build/game.o: src/game.c
	$(CC) -c -o $@ $< -I$(INCLUDE_DIR) -I. $(FLAGS)
build/xxh_engine.o: src/xxh_engine.c headers/xxh_engine.h
	$(CC) -c -o $@ $< -I$(INCLUDE_DIR) -I. $(FLAGS)
build/xxh_resource_manager.o: src/xxh_resource_manager.c headers/xxh_resource_manager.h
	$(CC) -c -o $@ $< -I$(INCLUDE_DIR) -I. $(FLAGS)
build/xxh_error.o: src/xxh_error.c headers/xxh_error.h
	$(CC) -c -o $@ $< -I$(INCLUDE_DIR) -I. $(FLAGS)
build/xxh_renderer.o: src/xxh_renderer.c headers/xxh_renderer.h
	$(CC) -c -o $@ $< -I$(INCLUDE_DIR) -I. $(FLAGS)

.PHONY: clean
clean:
	-rm $(BUILD_DIR)/*.o