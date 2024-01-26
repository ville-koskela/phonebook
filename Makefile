# Define compiler
CC=gcc

# Define compilation flags
CFLAGS=-c -Wall 
# Use these flags if you want to include debug code
#CFLAGS=-c -Wall -DDEBUG

# Define linking flags
LDFLAGS=

# Define linking flags for tests
TEST_LDFLAGS=-lcunit

# Define name for the app 
EXECUTABLE=book

# Define test executable
TEST_EXECUTABLE=test

# Define source, object and test directories
SRCDIR=src
OBJDIR=obj

# Define source files
SOURCES=$(wildcard $(SRCDIR)/*.c $(SRCDIR)/*/*.c)

# Define object files
OBJECTS=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

all: build

# Build
build: $(EXECUTABLE)
    
$(EXECUTABLE): $(filter-out $(OBJDIR)/%_test.o, $(OBJECTS))
	$(CC) $(LDFLAGS) $^ -o $(EXECUTABLE)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

# Tests
tests: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(filter-out $(OBJDIR)/main.o, $(OBJECTS))
	$(CC) $^ $(TEST_LDFLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

# Clean
clean:
	rm -rf $(OBJDIR)/* $(EXECUTABLE) $(TEST_EXECUTABLE)
