CC=g++
CFLAGS=-I. -Wall -Werror
OBJ=Employee.o File.o salReport.o cstring.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

ws: $(OBJ)
	$(CC) $(OBJ) -o ws

.PHONY: clean

clean:
	rm *.o ws

