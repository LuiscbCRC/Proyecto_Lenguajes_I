#include"pokergame.h"

//Aqui van todos los tipos de jugadas que se pueden hacer
enum {HIGHCARD,PAIR,TWOPAIR,THREEK,STRAIGHT,FLUSH,FULLHOUSE,FOURK,SFLUSH} classes;

int hand_init(Hand * aHandPtr){
  int i=0;
  if((aHandPtr->cards = (Card **)malloc(sizeof(Card*)*HAND_SIZE))==NULL)
    return -1;
  for(i=0;i<HAND_SIZE;i++){
    if((aHandPtr->cards[i]=(Card*)malloc(sizeof(Card)))==NULL)
      return -1;
  }
  aHandPtr->cardsHeld=0;
  aHandPtr->value=0;
  aHandPtr->class = (char*)malloc(sizeof(char)*20);
  strcpy(aHandPtr->class,"123456789012345678");
  return 0;
}

int add_card(Hand * aHandPtr, Card * card){
  if(aHandPtr->cardsHeld==HAND_SIZE)
    return -1;
  aHandPtr->cards[aHandPtr->cardsHeld]=card;
  aHandPtr->cardsHeld++;
  return 0;
}

//toString
int hand_toString_ordered(Hand * aHandPtr){
  int i;
  if(aHandPtr==NULL)
    return -1;
  for(i=0;i<aHandPtr->cardsHeld;i++){
    printf("[%d] ",i+1);
    card_toString(aHandPtr->cards[i]);
  }
  return 0;
}

void hand_destroy(Hand * aHandPtr){
  free(aHandPtr->cards);
  free(aHandPtr);
}

//Cual es la jugada que se creó?
int hand_value(Hand * aHandPtr){
  int i=0;
  int suits[5] = {0};
  int ranks[15] = {0};
  int orderedcards=0;
  int straight=0;
  int flush=0;
  int threekind=0;
  int pair=0;

  int threek_highcard=0;
  int pair_highcard=0;
  int highcard=0;

  for(i=0;i<HAND_SIZE;i++){
    suits[aHandPtr->cards[i]->suit] +=1;
    ranks[aHandPtr->cards[i]->rank] +=1;
  }
  // Encuentra la carta mas alta
  for(i=2;i<15;i++){
    if(ranks[i]>0 && i>highcard)
      highcard=i;
  }
  // Esto es para verificar si encuentra color
  for(i=1;i<5;i++){
    if(suits[i]==5)
      flush=1;
  }
  // Esto es para verificar si encuentra una escalera (no necesariamente real)
  for(i=2;i<14;i++){
    if(ranks[i]==1 && ranks[i+1]==1)
      orderedcards +=1;
    if(orderedcards==4){
      straight =1;
      break;
    }
  }
  
  // Si cumple ambas condiciones es una escalera de color
  // Aqui es donde se deberia agregar la funcionalidad de la escalera real
  if(flush==1 && straight==1){
    strcpy(aHandPtr->class,"Escalera de color");
    aHandPtr->value = 13*SFLUSH+highcard-1;
    return aHandPtr->value;
  }

  //Busca el resto de las jugadas
  for(i=2;i<15;i++){
    if(ranks[i]==4){
      strcpy(aHandPtr->class,"Poker");
      aHandPtr->value = 13*FOURK+i-1;
      return aHandPtr->value;
    }   
    if(ranks[i]==3){
      threekind +=1;
      threek_highcard = i;
    }
    if(ranks[i]==2){
      pair +=1;
      if(i>pair_highcard)
	pair_highcard=i;
    }
  }

  if(threekind == 1 && pair == 1){
    strcpy(aHandPtr->class,"Full House");
    aHandPtr->value = 13*FULLHOUSE+threek_highcard-1;
    return aHandPtr->value;
  }
  else if(flush==1){
    strcpy(aHandPtr->class,"Color");
    aHandPtr->value = 13*FLUSH+highcard-1;
    return aHandPtr->value;
  }
  else if(straight==1){
    strcpy(aHandPtr->class,"Escalera");
    aHandPtr->value = 13*STRAIGHT+highcard-1;
    return aHandPtr->value;
  }
  else if(threekind==1){
    strcpy(aHandPtr->class,"Trio");
    aHandPtr->value = 13*THREEK+threek_highcard-1;
    return aHandPtr->value;
  }
  else if(pair==2){
    strcpy(aHandPtr->class,"Doble par");
    aHandPtr->value =  13*TWOPAIR+pair_highcard-1;
    return aHandPtr->value;
  }
  else if(pair==1){
    strcpy(aHandPtr->class,"Par");
    aHandPtr->value = 13*PAIR+pair_highcard-1;
    return aHandPtr->value;
  }
  strcpy(aHandPtr->class,"Carta alta");
  aHandPtr->value = 13*HIGHCARD+highcard-1;
  return aHandPtr->value;
}
