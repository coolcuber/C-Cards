#ifndef MATH_H
#include <math.h>
#endif
#ifndef STDLIB_H
#include <stdlib.h>
#endif
#ifndef STDIO_H
#include <stdio.h>
#endif
#ifndef STRING_H
#include <string.h>
#endif
#ifndef TIME_H
#include <time.h>
#endif

typedef enum drawstate {
	KEEP = 0,
	REMOVE = 1
} drawstate;

typedef enum Rank {
	ace = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	jack = 11,
	queen = 12,
	king = 13
} Rank;

typedef enum Suit {
	hearts = 1,
	diamonds = 2,
	clubs = 3,
	spades = 4
} Suit;

typedef struct Card {
	Suit suit;
	Rank rank;
} Card;

typedef struct Deck {
	Card *cards;
	int size;
} Deck;

Card chooserandom(Deck deck);
void makedeck(Deck *deck, int size);
void shuffle(Deck *deck);
void makestring(char *string, Card card);
void removecard(Deck deck, Card card);