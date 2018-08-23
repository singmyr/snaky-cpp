CC := c++
SRC_DIR := src
BUILD_DIR := build
TARGET := bin/snaky

SRC_EXT := cpp
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -std=c++11 -pedantic-errors -Wall
LIB := -L/usr/local/lib -lSDL2_image -lSDL2
INC := -I./include -I/usr/local/include/SDL2

$(TARGET): $(OBJECTS)
	@echo "Linking... $(OBJECTS)"
	@echo "$(CC) $^ -o $(TARGET) $(INC) $(LIB)"; $(CC) $^ -o $(TARGET) $(INC) $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(BUILD_DIR)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<
