#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<string.h>
#include<math.h>
#include<unistd.h>

#define HAND_SIZE 5       
#define DECK_SIZE 52      
#define FIRSTCARD 0       
#define CLASS 8           
#define RANKS 13

//Definir las probabilidades teoricas

typedef struct card{
  int suit;
  int rank;
}Card;

typedef struct hand{
  Card **cards;  
  int cardsHeld; 
  int value;     
  char *class;   
}Hand;

typedef struct deck{
  Card **cards;      
  Card *topcard;     
  int topcardindex;
}Deck;

typedef struct player{
  Hand *hand;
}Player;

// Prototipos para: Card
int card_toString(Card * aCardPtr);
void card_init(Card * aCardPtr, int suit, int rank);
void card_destroy(Card * aCardPtr);

// Prototipos para: Deck
void deck_toString(Deck * aDeckPtr);
int dequeue_card(Deck * aDeckPtr, Card ** data);
int swap_card(Deck * aDeckPtr, int s, int t);
int deck_init(Deck * aDeckPtr);
void deck_fill(Deck * aDeckPtr);
void shuffle(Deck * aDeckPtr, int shuffles);
void deck_destroy(Deck * aDeckPtr);
void enqueue_deck(Deck * aDeckPtr);
int find_card(Deck * aDeckPtr, int suit, int rank);

// Prototipos para: Hand
int hand_init(Hand * aHandPtr);
int add_card(Hand * aHandPtr, Card * card);
int hand_toString_ordered(Hand * aHandPtr);
void hand_destroy(Hand * aHandPtr);
int hand_value(Hand * aHandPtr);

// Prototipos para: Player
int player_init(Player * aPlayer);
int player_reset_hand(Player * aPlayer);
void player_destroy(Player * aPlayer);

// Prototipos para: Probability
double mediaEmpirica(double probabilidades[], int size);
double varianciaEmpirica(double probabilidades[], int size, double media);
double getProbability(int qty, int tries);

// Prototipo para: Pokergame
int * game(int N);



