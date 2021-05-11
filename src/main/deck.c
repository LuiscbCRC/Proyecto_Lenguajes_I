#include"pokergame.h"

#define cards aDeckPtr->cards

int deck_init(Deck * aDeckPtr){
  int card=FIRSTCARD;
  if((cards =(Card **)malloc(sizeof(Card*)*DECK_SIZE))==NULL)
    return -1;  
  //Asignar memoria
  for(card=FIRSTCARD;card<DECK_SIZE;card++){
    if((cards[card]=(Card*)malloc(sizeof(Card)))==NULL)
	return -1;
  }

  //set el orden del deck
  aDeckPtr->topcardindex = FIRSTCARD;
  return 0;
}

//Darle valor a las cartas
void deck_fill(Deck * aDeckPtr){
  int rank;
  int suit;
  int card=FIRSTCARD;
  for(rank=2;rank<15;rank++){
    for(suit=1;suit<5;suit++){
      card_init(cards[card],suit,rank);
      card += 1;
    }
  }
}

void deck_toString(Deck * aDeckPtr){
  int i;
  for(i=aDeckPtr->topcardindex;i<DECK_SIZE;i++)
    card_toString(cards[i]);
}

//Toma una carta del deck
int dequeue_card(Deck * aDeckPtr, Card ** data){
  if(aDeckPtr->topcardindex==DECK_SIZE)
    return -1;  //No hay mas cartas por sacar
  *data = cards[aDeckPtr->topcardindex];
  aDeckPtr->topcardindex++;
  return 0;
}

//Busca una carta, sirve para validaciones de que si se estan tomando las cartas
int find_card(Deck * aDeckPtr, int suit, int rank){
  int i=0;
  for(i=aDeckPtr->topcardindex;i<DECK_SIZE;i++){
    if(cards[i]->rank == rank && cards[i]->suit == suit)
      return i;
  }
  return -1;
}

//Sirve para cambiar dos cartas de lugar (para el shuffle)
int swap_card(Deck * aDeckPtr, int s, int t){
  Card ** tmp=(Card **)malloc(sizeof(Card*));
  if(tmp==NULL)
    return -1;
  *tmp = cards[t];
  cards[t] = cards[s];
  cards[s]=*tmp;
  free(tmp);
  return 0;
}

//Devuelve todas las cartas al deck
void enqueue_deck(Deck * aDeckPtr){
  aDeckPtr->topcardindex = FIRSTCARD;
}

//Barajar las cartas
void shuffle(Deck * aDeckPtr, int shuffles){
  int a;
  int b;
  int i;
  a =rand()%DECK_SIZE;
  b =rand()%DECK_SIZE;
  for(i=0;i<shuffles;i++){
    swap_card(aDeckPtr,a,b);
    a=rand()%DECK_SIZE;
    b=rand()%DECK_SIZE;
  }
}

//liberar la memoria
void deck_destroy(Deck * aDeckPtr){
  int card;
  for(card=FIRSTCARD;card<DECK_SIZE;card++){
    card_destroy(cards[card]);
  }
  free(cards);
  free(aDeckPtr);
}
