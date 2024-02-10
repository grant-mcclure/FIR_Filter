# Makefile

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Linker flags
LFLAGS = -lm

# Build target
TARGET = main

# Object files
OBJS = main.o datahandling.o filtering.o

# Rule to link the program
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# Rule to compile main.c
main.o: main.c datahandling.h filtering.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile datahandling.c
datahandling.o: datahandling.c datahandling.h
	$(CC) $(CFLAGS) -c datahandling.c

# Rule to compile filtering.c
filtering.o: filtering.c filtering.h
	$(CC) $(CFLAGS) -c filtering.c

numerical_calculus.o: numerical_calculus.c numerical_calculus.h
	$(CC) $(CFLAGS) -c numerical_calculus.c

# Clean up
clean:
	rm -f $(TARGET) $(OBJS) output_data.csv three_point_mov_avg.csv five_point_mov_avg.csv seven_point_mov_avg.csv three_point_binomial.csv five_point_binomial.csv seven_point_binomial.csv
