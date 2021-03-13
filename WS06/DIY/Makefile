CC=g++
CFLAGS=-I. -Wall -Werror -std=c++0x -ggdb
OBJ=Stats.o cstring.o w6p2_tester.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ws.out: $(OBJ)
	$(CC) $(OBJ) -o ws.out

.PHONY: clean

clean:
	rm *.o ws.out

