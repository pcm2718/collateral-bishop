export OMPI_CC=clang
export OMPI_CXX=clang++

CC=mpicc
CFLAGS=-g -std=c99 -Wall -Wextra -Werror -I src
LFLAGS=-g -std=c99 -L obj

all: obj/main.o obj/herd.o obj/histogram.o
	$(CC) $(LFLAGS) obj/main.o obj/herd.o obj/histogram.o -o bin/collateral-bishop

obj/main.o: src/main.c src/histogram.h src/herd.h
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

obj/herd.o: src/herd.c src/herd.h
	$(CC) $(CFLAGS) -c src/herd.c -o obj/herd.o

obj/histogram.o: src/histogram.c src/histogram.h
	$(CC) $(CFLAGS) -c src/histogram.c -o obj/histogram.o

clean:
	rm -rf obj/*.o
	rm bin/collateral-bishop
