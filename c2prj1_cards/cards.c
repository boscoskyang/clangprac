#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {
  assert( SPADES <= c.suit && c.suit < NUM_SUITS);
  assert(2 <= c.value&& c.value < 15); 
}

const char * ranking_to_string(hand_ranking_t r) {
    switch(r){
    case STRAIGHT_FLUSH :
      return "Straight Flush";
      break;
    case FOUR_OF_A_KIND :
      return "Four of a kind";
      break;
    case FULL_HOUSE :
      return "FUll House";
      break;
    case FLUSH:
      return "Flush";
      break;
    case STRAIGHT :
      return "Straight";
      break;
    case THREE_OF_A_KIND:
      return "Three of a kind";
      break;
    case TWO_PAIR:
      return "Two Pair";
      break;
    case PAIR:
      return "Pair";
      break;
    case NOTHING :
      return "Nothing";
      break;
    default: 
  return "";
    }
}

char value_letter(card_t c) {

  if (2 <= c.value && c.value < 10){
    return c.value + '0';}
  switch (c.value){
  case 10:
    return '0';
      break;
  case VALUE_JACK:
    return 'J';
    break;
  case VALUE_QUEEN:
    return 'Q';
    break;
  case VALUE_KING:
    return 'K';
    break;
  case VALUE_ACE:
    return 'A';
    break;
  default:
  return 'x';

  }
}


char suit_letter(card_t c) {
  switch (c.suit){
  case SPADES:
    return 's';
    break;
  case DIAMONDS:
    return 's';
    break;
  case HEARTS:
    return 'h';
    break;
  case CLUBS:
    return 'c';
    break;
  default:
  return 'x';
  } 
}

void print_card(card_t c) { 
  printf("%c%c",value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  assert((value_let>= '2' && value_let <= '9') || value_let == '0' || value_let == 'K' ||value_let == 'Q' || value_let == 'J' ||value_let == 'A' );
  assert( suit_let == 's' || suit_let == 'd' || suit_let == 'c' ||
	  suit_let == 'h');
  if ('2' <= value_let && value_let <= '9') {
    temp.value = value_let - '0';
  }
  switch (value_let){
  case '0':
    temp.value = 10;
    break;
  case 'A':
    temp.value = VALUE_ACE;
    break;
  case 'K':
    temp.value = VALUE_KING;
    break;
  case 'Q':
    temp.value = VALUE_QUEEN;
    break;
  case 'J':
    temp.value = VALUE_JACK;
    break;
  }
  
  switch (suit_let){
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 's':
    temp.suit = SPADES;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert( c < 52);
  temp.suit = c % 4 ;
  temp.value = c %13 + 2;
  return temp;
}
