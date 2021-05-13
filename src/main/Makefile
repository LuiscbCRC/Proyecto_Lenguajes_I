# change application name here (executable output name)
TARGET=poker_probabilistico

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB)

OBJS=    main.o card.o deck.o hand.o player.o probability.o pokergame.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o: main.c pokergame.c card.o deck.o hand.o player.o pokergame.h
	$(CC) -c $(CCFLAGS) main.c $(GTKLIB) -I.

pokergame.o: pokergame.c card.o deck.o hand.o player.o pokergame.h
	gcc -c pokergame.c -I.

player.o: player.c card.o deck.o hand.o pokergame.h
	gcc -c player.c -I.

hand.o: hand.c card.o deck.o pokergame.h
	gcc -c hand.c -I.

deck.o: deck.c card.o pokergame.h
	gcc -c deck.c -I.

probability.o: probability.c pokergame.h
	gcc -c probability.c -I.

card.o: card.c pokergame.h
	gcc -c card.c -I.
    
clean:
	rm -f *.o $(TARGET)
