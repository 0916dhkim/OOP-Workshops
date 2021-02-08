CC=g++
CFLAGS=-I. -Wall -Werror
OBJ=Canister.o cstring.o canisterMain.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ws.out: $(OBJ)
	$(CC) $(OBJ) -o ws.out

.PHONY: clean

clean:
	rm *.o ws.out

