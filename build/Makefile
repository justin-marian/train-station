# Compiler and flags
CC := gcc
CFLAGS := -Wall -Werror -std=c11
LDFLAGS :=

# Directories
SRCDIR := ../src
OBJDIR := ../result/bin/obj
EXEDIR := ../result/bin

# ANSI color codes
GREEN := '\033[0;32m'
NC := '\033[0m' # No Color

# List of source files in each directory
FIND_TRAIN_SOURCES := $(wildcard $(SRCDIR)/find_train/*.c)
STATION_SOURCES := $(wildcard $(SRCDIR)/station/*.c)
TRAIN_SOURCES := $(wildcard $(SRCDIR)/train/*.c)
TRAIN_CAR_SOURCES := $(wildcard $(SRCDIR)/train_car/*.c)

# Object files for each source file
FIND_TRAIN_OBJECTS := $(patsubst $(SRCDIR)/find_train/%.c, $(OBJDIR)/%.o, $(FIND_TRAIN_SOURCES))
STATION_OBJECTS := $(patsubst $(SRCDIR)/station/%.c, $(OBJDIR)/%.o, $(STATION_SOURCES))
TRAIN_OBJECTS := $(patsubst $(SRCDIR)/train/%.c, $(OBJDIR)/%.o, $(TRAIN_SOURCES))
TRAIN_CAR_OBJECTS := $(patsubst $(SRCDIR)/train_car/%.c, $(OBJDIR)/%.o, $(TRAIN_CAR_SOURCES))

# Executable name
TARGET := $(EXEDIR)/hogsemade

.PHONY: all clean

# Default target
all: $(TARGET)

# Create the obj directory if it doesn't exist
$(shell mkdir -p $(OBJDIR))

# FILE STRUCTURE OF THE PROJECT DIRECTORY (src)
# FIND_TRAIN | STATION | TRAIN | TRAIN_CAR | HOGSEMADE

# Compile find_train/*.c to object files
$(OBJDIR)/%.o: $(SRCDIR)/find_train/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Compile station/*.c to object files
$(OBJDIR)/%.o: $(SRCDIR)/station/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Compile train/*.c to object files
$(OBJDIR)/%.o: $(SRCDIR)/train/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Compile train_car/*.c to object files
$(OBJDIR)/%.o: $(SRCDIR)/train_car/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Compile hogsemade.c to an object file
$(OBJDIR)/hogsemade.o: $(SRCDIR)/hogsemade.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link all object files to create the final executable
$(TARGET): $(OBJDIR)/hogsemade.o $(FIND_TRAIN_OBJECTS) $(STATION_OBJECTS) $(TRAIN_OBJECTS) $(TRAIN_CAR_OBJECTS)
	@echo "Linking object files..."
	@$(CC) $(CFLAGS) $^ -o $@
	@echo $(GREEN)"Linking complete!"$(NC)

# Clean the build directory
clean:
	rm -rf $(EXEDIR)
