#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52

struct bitCard {
  unsigned int face : 4;
  unsigned int suit : 2;
  unsigned int color : 1;
};

typedef struct bitCard Card;

void fillDeck(Card * const wDeck);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(void)
{

  srand(time(NULL));
  
  Card deck[CARDS];

  fillDeck(deck);

  puts("Card values 0-12 correspond to Ace through King");
  puts("Suit values 0-3 correspond Hearts, Diamonds, Clubs, Spades");
  puts("Color values 0-1 correspond to red and black\n");
  shuffle(deck);
  deal(deck);
}

void fillDeck(Card * const wDeck)
{
  for (size_t i = 0; i < CARDS; ++i) {
    wDeck[i].face = i % (CARDS / 4);
    wDeck[i].suit = i / (CARDS / 4);
    wDeck[i].color = i / (CARDS / 2);    
    
  }
}

void shuffle(Card * const wDeck)
{
  for (size_t i = 0; i < CARDS; ++i) {
    size_t j = rand() % CARDS;
    Card temp = wDeck[i];
    wDeck[i] = wDeck[j];
    wDeck[j] = temp;
  }
}

void deal(const Card * const wDeck)
{
  printf("%-8s\t%-9s%-8s\t%-8s\t%-9s%-8s\n\n",
	 "Color", " Card", "Suit", "Color", " Card", "Suit");

  char *Face[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six",
		   "Seven", "Eight", "Nine", "Ten",
		   "Jack", "Queen", "King" };
  char *Suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
  char *Color[] = { "(Red)", "(Black)" };

  for (size_t i = 0; i < CARDS; ++i) {
    printf("%-8s\t%5s%s%-8s%c", Color[wDeck[i].color], Face[wDeck[i].face], " of ",
	   Suit[wDeck[i].suit], (i % 2 == 0) ? '\t' : '\n');
  }
}
