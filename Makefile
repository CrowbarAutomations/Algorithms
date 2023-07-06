# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Directories
ROOT_DIR = Algorithms
BUILD_DIR = $(ROOT_DIR)/.build
CONFIG_DIR = $(ROOT_DIR)/.config
GITHUB_DIR = $(ROOT_DIR)/.github
BIN_DIR = $(ROOT_DIR)/bin
DOC_DIR = $(ROOT_DIR)/doc
SRC_DIR = $(ROOT_DIR)/src
INC_DIR = $(SRC_DIR)/inc
TEST_DIR = $(ROOT_DIR)/test
TOOLS_DIR = $(ROOT_DIR)/tools

# Target executable
TARGET = $(BIN_DIR)/main.exe

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)  # Create the bin directory if it doesn't exist
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile each individual source file into an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)  # Create the build directory if it doesn't exist
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Target for running tests
test:
	@echo "Running tests..."

# Target for running tools
tools:
	@echo "Running tools..."

# Target for running configuration
config:
	@echo "Running configuration..."

# Target for generating documentation
docs:
	@echo "Generating documentation..."
	# Add commands to generate documentation in the doc folder