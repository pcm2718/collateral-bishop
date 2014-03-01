export OMPI_CC=clang
export OMPI_CXX=clang++

CC=mpicc
CFLAGS=-g -std=c99 -Wall -Wextra -Werror -I src
LFLAGS=-g -std=c99 -L obj

all: obj/main.o
	$(CC) $(LFLAGS) obj/main.o -o bin/collateral-bishop

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

clean:
	rm -rf obj/*.o
	rm bin/collateral-bishop
