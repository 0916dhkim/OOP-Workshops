CC=g++
CFLAGS=-I. -Wall -Werror
OBJ=Population.o File.o popReport.o cstring.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ws: $(OBJ)
	$(CC) $(OBJ) -o ws $(CFLAGS)

.PHONY: clean

clean:
	rm *.o ws

