#include<string>
#include<iostream>
#include<iomanip>
#include"Card.h"
using namespace std;
int main() {
	Card card("black", 12);
	string color;
	int math,x=-1,total=0;
	while (x != 0) {
		cin >> color >> math;
		card.setColor(color);
		card.setMath(math);
		card.setSum(total);
		total += card.getSum();
		card.print();
		if (total <= 21) {
			cout << "�O�_�[�P?\n�O�п�J1\n�_�п�J0" << endl;
			cin >> x;
		}
		else {
			cout << "Game Over" << endl;
			x = 0;
		}
		
	}
	return 0;
}