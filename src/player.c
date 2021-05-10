#include "pokergame.h"

int player_init(Player * aPlayer){
  if((aPlayer->hand = (Hand *)malloc(sizeof(Hand)))==NULL)
     return -1;
  hand_init(aPlayer->hand);
  return 0;
}

int player_reset_hand(Player * aPlayer){
  free(aPlayer->hand);
  if((aPlayer->hand = (Hand *)malloc(sizeof(Hand)))==NULL)
     return -1;
  hand_init(aPlayer->hand);
  return 0;
}
void player_destroy(Player * aPlayer){
  free(aPlayer->hand);
  free(aPlayer);
}
