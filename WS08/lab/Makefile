CC=g++
CFLAGS=-I. -Wall -Werror -std=c++0x -ggdb
OBJ=main.o Shape.o LblShape.o Rectangle.o Line.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ws.out: $(OBJ)
	$(CC) $(OBJ) -o ws.out

.PHONY: clean

clean:
	rm *.o ws.out

