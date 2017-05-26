all: index

index: index.o utils.o wordHandler.o
	gcc -ansi -Wall -pedantic -lm -o index index.o utils.o wordHandler.o

wordHandler.o: wordHandler.c wordHandler.h
	gcc -ansi -Wall -pedantic -c wordHandler.c

utils.o: utils.c utils.h
	gcc -ansi -Wall -pedantic -c utils.c

index.o: index.c utils.c wordHandler.c wordHandler.h utils.h
	gcc -ansi -Wall -pedantic -c index.c utils.c wordHandler.c
clean:
	rm *.o *~index
