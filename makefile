SRC_DIR  := src
INC_DIR  := include
BIN_DIR  := bin
DIST_DIR := dist

CC := gcc
CFLAGS := -Wall -Wextra -I$(INC_DIR)

SRC := $(wildcard $(SRC_DIR)/*.c)
TARGET := ptex

.PHONY: all debug release clean run

all: release


# --------------------------------------------------
# Development
# --------------------------------------------------

DEBUG_BIN := $(BIN_DIR)/debug
DEBUG_DIST := $(DIST_DIR)/debug
DEBUG_OBJ := $(patsubst $(SRC_DIR)/%.c, $(DEBUG_BIN)/%.o, $(SRC))
DEBUG_CFLAGS := $(CFLAGS) -g -O0

debug: $(DEBUG_DIST)/$(TARGET)

$(DEBUG_DIST)/$(TARGET): $(DEBUG_OBJ)
	@echo "Linking debug build..."
	@mkdir -p $(DEBUG_DIST)
	@$(CC) $(DEBUG_OBJ) -o $@ $(CFLAGS)
	@cp -r data $(DEBUG_DIST)/
	@cp -r assets $(DEBUG_DIST)/
	@echo "Debug build complete."

$(DEBUG_BIN)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	@$(CC) $(DEBUG_CFLAGS) -c $< -o $@


# --------------------------------------------------
# Release
# --------------------------------------------------

RELEASE_BIN := $(BIN_DIR)/release
RELEASE_DIST := $(DIST_DIR)/release
RELEASE_OBJ := $(patsubst $(SRC_DIR)/%.c, $(RELEASE_BIN)/%.o, $(SRC))
RELEASE_CFLAGS := $(CFLAGS) -O2 -DNDEBUG

release: $(RELEASE_DIST)/$(TARGET)

$(RELEASE_DIST)/$(TARGET): $(RELEASE_OBJ)
	@echo "Linking release build..."
	@mkdir -p $(RELEASE_DIST)
	@$(CC) $(RELEASE_OBJ) -o $@ $(CFLAGS)
	@cp -r assets $(RELEASE_DIST)/
	@echo "Release build complete."

$(RELEASE_BIN)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	@$(CC) $(RELEASE_CFLAGS) -c $< -o $@


# --------------------------------------------------
# Utility
# --------------------------------------------------

clean:
	@echo "Cleaning project..."
	@rm -rf $(BIN_DIR) $(DIST_DIR)
	@echo "Project cleaned."

run: debug
	@./$(DEBUG_DIST)/$(TARGET)
