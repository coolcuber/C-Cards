#ifndef CARDS_H
#include <cards.h>
#endif

void assigncard(int n, Card *card) {
	if (n<14) {
		card->suit = hearts;
	} else if (n<27) {
		card->suit = diamonds;
	} else if (n<40) {
		card->suit = clubs;
	} else {
		card->suit = spades;
	}
	switch (n % 13) {
		case (1):
			card->rank = ace;
			break;
		case (2):
			card->rank = two;
			break;
		case (3):
			card->rank = three;
			break;
		case (4):
			card->rank = four;
			break;
		case (5):
			card->rank = five;
			break;
		case (6):
			card->rank = six;
			break;
		case (7):
			card->rank = seven;
			break;
		case (8):
			card->rank = eight;
			break;
		case (9):
			card->rank = nine;
			break;
		case (10):
			card->rank = ten;
			break;
		case (11):
			card->rank = jack;
			break;
		case (12):
			card->rank = queen;
			break;
		case (0):
			card->rank = king;
			break;
	};
}

int compare(Card card1, Card card2) {
	return ((card1.suit==card2.suit)&(card1.rank==card2.rank));
}

void drawcard(Deck deck, Card ctbd, drawstate ds) {
	int r;
	srand(time(NULL));
	r = (rand() % deck.size);
	ctbd = deck.cards[r];
	if (ds) {
		removecard(deck, ctbd);
	}
}

void makedeck(Deck *deck, int csize) {
	deck->size = csize;
	deck->cards = malloc(csize * sizeof(Card));
	for (int i=0; i<csize; i++) {
		assigncard(i + 1, &(deck->cards[i]));
	}
}

void shuffle(Deck *deck) {
	int r;
	Card card;
	srand(time(NULL));
	for (int i=deck->size-1; i>=1; i--) {
		r = (rand() % (i + 1));
		card.suit = deck->cards[i].suit;
		card.rank = deck->cards[i].rank;
		deck->cards[i].suit = deck->cards[r].suit;
		deck->cards[i].rank = deck->cards[r].rank;
		deck->cards[r].suit = card.suit;
		deck->cards[r].rank = card.rank;
	}
}

void makestring(char *string, Card card) {
	char *s1, *s2;
	realloc(string, 20*sizeof(char));
	switch (card.suit) {
		case hearts:
			s2 = "Hearts";
			break;
		case diamonds:
			s2 = "Diamonds";
			break;
		case clubs:
			s2 = "Clubs";
			break;
		case spades:
			s2 = "Spades";
			break;
	};
	switch (card.rank) {
		case ace:
			s1 = "Ace";
			break;
		case two:
			s1 = "Two";
			break;
		case three:
			s1 = "Three";
			break;
		case four:
			s1 = "Four";
			break;
		case five:
			s1 = "Five";
			break;
		case six:
			s1 = "Six";
			break;
		case seven:
			s1 = "Seven";
			break;
		case eight:
			s1 = "Eight";
			break;
		case nine:
			s1 = "Nine";
			break;
		case ten:
			s1 = "Ten";
			break;
		case jack:
			s1 = "Jack";
			break;
		case queen:
			s1 = "Queen";
			break;
		case king:
			s1 = "King";
			break;
	};
	sprintf(string, "%s of %s", s1, s2);
}

void removecard(Deck deck, Card card) {
	for (int i=0; i<deck.size; i++) {
		if (compare(deck.cards[i], card)) {
			for (int r=deck.size; r>i; r++) {
				deck.cards[r-1] = deck.cards[r];
			}
			deck.size -= 1;
			deck.cards = realloc(deck.cards, deck.size * sizeof(Card));
		}
	}
}