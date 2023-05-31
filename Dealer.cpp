#include "Dealer.h"

Dealer::Dealer() {}

void Dealer::printCards() {
	cout << "Dealer's Cards: " << endl;
	for (const Sum& card : cards) {
		card.print();
	}
}

int Dealer::getSum() {
	int total = 0;
	for (const Sum& card : cards) {
		total += card.getMath();
	}
	return total;
}

int Dealer::getNumCards() {
	return cards.size();
}

bool Dealer::isBust() {
	return getSum() > 21;
}

void Dealer::reset() {
	cards.clear();
}
