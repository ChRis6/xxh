CC=gcc
FLAGS= -lallegro -lallegro_main -lallegro_image
INCLUDE_DIR = headers/
BUILD_DIR = build

OUT= game
OBJS = $(BUILD_DIR)/game.o $(BUILD_DIR)/xxh_engine.o $(BUILD_DIR)/xxh_resource_manager.o \
	$(BUILD_DIR)/xxh_error.o $(BUILD_DIR)/xxh_renderer.o
all:game

game: $(OBJS)
	$(CC) -o $(OUT) -I/$(INCLUDE_DIR) $(FLAGS) $(OBJS)

$(BUILD_DIR):
	mkdir -p $@

	
$(BUILD_DIR)/game.o: src/game.c $(INCLUDE_DIR)xxh_engine.h | $(BUILD_DIR)
	gcc -c $< -o $@ -I$(INCLUDE_DIR) $(FLAGS) 
$(BUILD_DIR)/xxh_engine.o: src/xxh_engine.c | $(BUILD_DIR)
	gcc -c $< -o $@ -I$(INCLUDE_DIR) $(FLAGS) 
$(BUILD_DIR)/xxh_resource_manager.o: src/xxh_resource_manager.c  | $(BUILD_DIR)
	gcc -c $< -o $@ -I$(INCLUDE_DIR) $(FLAGS) 
$(BUILD_DIR)/xxh_error.o : src/xxh_error.c | $(BUILD_DIR)
	gcc -c $< -o $@ -I$(INCLUDE_DIR) $(FLAGS) 
$(BUILD_DIR)/xxh_renderer.o : src/xxh_renderer.c $(INCLUDE_DIR)xxh_renderer.h
	gcc -c $< -o $@ -I$(INCLUDE_DIR) $(FLAGS)
	
.PHONY: clean
clean:
	-rm $(BUILD_DIR)/*.o