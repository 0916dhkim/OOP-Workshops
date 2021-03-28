CC=g++
CFLAGS=-I. -Wall -Werror -std=c++0x -ggdb
OBJ=Car.o Employee.o main.o ReadWrite.o Student.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ws.out: $(OBJ)
	$(CC) $(OBJ) -o ws.out

.PHONY: clean

clean:
	rm *.o ws.out

