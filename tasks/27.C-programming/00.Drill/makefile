# Config

SRC_DIR=./src
OBJ_DIR=./objs

CC=gcc
CCFLAGS=-ggdb -O0
LDFLAGS=

SOURCES=$(notdir $(shell find $(SRC_DIR) -name '*.c'))
OBJECT_FILES=$(SOURCES:%.c=$(OBJ_DIR)/%.o)
TARGET_FILE=drill.exe

vpath %.c $(SRC_DIR)

# Rules
all: clean target

target: $(SOURCES) $(TARGET_FILE)

$(TARGET_FILE): $(OBJ_DIR) $(OBJECT_FILES)
	$(CC) $(LDFLAGS) $(OBJECT_FILES) -o $@

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	-rm -rf $(OBJ_DIR) $(TARGET_FILE)

