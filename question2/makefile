.PHONY: all clean
all: index

CC = gcc
CFLAGES = -Wall -ansi -pedantic
OBJECTS = index.o wordHandler.o utils.o BinaryTree.o

index: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o index -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm *.o *~index
