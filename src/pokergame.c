#include "pokergame.h"

int main(int argc, char **argv){
  int i=0;
  int setloop=1;

  Card ** tmpCard = (Card **)malloc(sizeof(Card *));
  Deck * playingDeck = (Deck *)malloc(sizeof(Deck));
  Player * player = (Player *)malloc(sizeof(Player));
  player_init(player);

  srand(time(NULL));
  printf("\n\n\n\n========[Poker Simulacion]========\n\n");
  
  deck_init(playingDeck);
  deck_fill(playingDeck);
  shuffle(playingDeck,2000);

  while(setloop!=0){

    for(i=0;i<HAND_SIZE;i++){
	    dequeue_card(playingDeck,tmpCard);
	    add_card(player->hand,*tmpCard);
	  }

    printf("Mano actual:\n");
	  hand_toString_ordered(player->hand);
    hand_value(player->hand);
	  printf("\n%s\n", player->hand->class);

    //if(strcmp( player->hand->class, "Full House") == 0) break;

    // Esta es la parte que se ocupa editar para barajar por parametro
    // Actualmente lo hace en todas las corridas
    enqueue_deck(playingDeck);
    shuffle(playingDeck,1500);
    player_reset_hand(player);

    printf("\nNueva mano\n");
    sleep(1);
    setloop++; //Esta variable es la que va a funcionar para determinar la cantidad de repeticiones de la simulación

  }// end while
    
  // Liberar toda la memoria ocupada
  deck_destroy(playingDeck);
  player_destroy(player);

  return 0;
}
