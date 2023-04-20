#include<string>
#include<iostream>
#include<iomanip>
#include"Card.h"
using namespace std;
int main() {
	Card card("black", 12);
	string color;
	int math, x = -1, total = 0;
	while (x != 0) {
		cin >> color >> math;
		card.setColor(color);
		card.setMath(math);
		total += card.getMath();
		card.setSum(total);
		card.print();
		if (total <= 21) {
			cin >> x;
		}
		else {
			x = 0;
		}
	}
	return 0;
}
