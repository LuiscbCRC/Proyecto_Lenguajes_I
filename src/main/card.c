#include "pokergame.h"

void card_init(Card * aCardPtr, int suit, int rank){
  aCardPtr->suit = suit;
  aCardPtr->rank = rank;
}

int card_toString(Card * aCardPtr){
  if(aCardPtr==NULL)
    return -1;
  switch(aCardPtr->rank){
  case 11:
    printf("J");
    break;
  case 12:
    printf("Q");
    break;
  case 13:
    printf("K");
    break;
  case 14:
    printf("A");
    break;
  default:
    printf("%d",aCardPtr->rank);
    break;
  }
  
  printf(" de ");

  switch(aCardPtr->suit){
  case 1:
    printf("Pica");
    break;
  case 2:
    printf("Corazones");
    break;
  case 3:
    printf("Diamante");
    break;
  case 4:
    printf("Trebol");
    break;
  default:
    printf("%d",aCardPtr->suit);
    break;
  }
  
  putchar('\n');
  return 0;
}

void card_destroy(Card * aCardPtr){
  free(aCardPtr);
}

