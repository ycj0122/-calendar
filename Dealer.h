#ifndef DEALER_H
#define DEALER_H
#include "Sum.h"
#include <vector>
using namespace std;
class Dealer {
public:
	Dealer();
	void printCards();
	int getSum();
	int getNumCards();
	bool isBust();
	void reset();
private:
	vector<Sum> cards;
};
#endif
