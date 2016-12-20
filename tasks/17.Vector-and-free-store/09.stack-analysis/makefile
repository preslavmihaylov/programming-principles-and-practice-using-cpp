# Config

SRC_DIR=./src
OBJ_DIR=./objs

CC=g++
CCFLAGS=-ggdb
LDFLAGS=

SOURCES=$(notdir $(shell find $(SRC_DIR) -name '*.cpp'))
OBJECT_FILES=$(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
TARGET_FILE=stack-analysis.exe

vpath %.cpp $(SRC_DIR)

# Rules
all: clean target

target: $(SOURCES) $(TARGET_FILE)

$(TARGET_FILE): $(OBJ_DIR) $(OBJECT_FILES)
	$(CC) $(LDFLAGS) $(OBJECT_FILES) -o $@

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	-rm -rf $(OBJ_DIR) $(TARGET_FILE)

