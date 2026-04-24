# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Define the final executable name
TARGET = personality

# Default target
all: $(TARGET)

# Link the object files
$(TARGET): main.o personality.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o personality.o

# Compile source files into object files
main.o: main.c personality.h
	$(CC) $(CFLAGS) -c main.c

personality.o: personality.c personality.h
	$(CC) $(CFLAGS) -c personality.c

# The 'make test' command
# This loops through all files in 'inputs', runs them, 
# and compares the result to the 'expected' folder.
test: $(TARGET)
	@for i in 1 2 3 4 5 6 7 8; do \
		echo "Testing input_$$i.txt..."; \
		./$(TARGET) inputs/input_$$i.txt > actual_$$i.txt; \
		diff actual_$$i.txt expected/expected_$$i.txt && echo "  Pass!" || echo "  Fail: Check actual_$$i.txt"; \
	done

# Clean up
clean:
	rm -f *.o $(TARGET) actual_*.txt