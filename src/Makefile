pokergame: pokergame.o card.o deck.o hand.o player.o probability.o pokergame.h
	gcc -o pokergame pokergame.o probability.o card.o deck.o hand.o player.o

# Aqui iria la compilacion del gui

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
	\rm -f *.o *# *~ pokergame