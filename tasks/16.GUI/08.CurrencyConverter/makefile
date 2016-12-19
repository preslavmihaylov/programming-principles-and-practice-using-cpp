# Config

SRC_DIR=./src
OBJ_DIR=./objs
LIB_DIR=./lib
INCLUDE_DIR=./include

CC=g++
CCINCLUDES=-I$(INCLUDE_DIR)
LD=g++
CCFLAGS=-g
FLTK_LIBS=-lfltk_images -lfltk_jpeg -lpng -lz -lfltk -ldl -lm -lXext -lX11
LDFLAGS=-L$(LIB_DIR) -lbookgui $(FLTK_LIBS)

SOURCES=$(notdir $(shell find $(SRC_DIR) -name '*.cpp'))
OBJECT_FILES=$(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
TARGET_FILE=currency-converter.exe

vpath %.cpp $(SRC_DIR)

# Rules
all: clean $(SOURCES) $(TARGET_FILE)

target: $(SOURCES) $(TARGET_FILE)

$(TARGET_FILE): $(OBJ_DIR) $(OBJECT_FILES)
	$(LD) -o $@ $(OBJECT_FILES) $(LDFLAGS) 

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CCFLAGS) $(CCINCLUDES) -c $< -o $@ 

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIB_DIR):
	mkdir $(LIB_DIR)

clean:
	-rm -rf $(OBJ_DIR) $(TARGET_FILE)

