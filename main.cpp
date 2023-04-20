#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include"Sum.h"
using namespace std;
int main() {
	Sum card(0, 12);
	int math, x = -1, total = 0;
	int cardArray[4][13] = {};
	srand(time(0));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cardArray[i][j] = j+1;
		}
	}
	while (x != 0) {
		int c =rand() % 4, math=rand() % 13;
		if (cardArray[c][math] != 0) {
			card.setColor(c);
			card.setMath(math+1);
			cout << card.getColor() << " " << card.getMath() << endl;
			total += card.getMath();
			card.setSum(total);
			cout << "目前點數:" << card.getSum() << endl;
			cardArray[c][math] = 0;
			if (total <= 21) {
				cout<< "是否加牌?\n是請輸入1\n否請輸入0" << endl;
				cin >> x;
			}
			else {
				x = 0;
				cout << "Game Over" << endl;
			}
		}
	}
	return 0;
}
