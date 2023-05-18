#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<ctime>
#include<algorithm>
#include"Sum.h"
using namespace std;

string* Card(string cardArray[]) {		//建立牌組並洗牌
	string* r = new string[52];
	string colorArray[4] = { "黑桃","紅心","方塊","梅花" };
	string mathArray[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	int n = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			string color = colorArray[i];
			string math = mathArray[j];
			string cards;
			cards.append(color).append(" ").append(math);
			r[n] = cards;
			n++;
		}
	}
	random_shuffle(r, r + 52);
	for (int i = 0; i < 52; i++) {
		cardArray[i] = r[i];
	}
	delete[] r;
	return cardArray;
}

int main() {
	cout << "Game Start" << endl;
	Sum card;
	string cardArray[52];
	int total = 0, x = 1;
	Card(cardArray);
	srand(time(0));
	while (x != 0) {		//抽牌並帶入加總物件
		if (total > 21) {
			cout << "Game Over\n";
			x = 0;
		}
		else {
			int number = rand() % 52;
			card.setCard(cardArray[number]);
			total += card.getMath();
			card.setSum(total);
			card.print();
			if (total < 21) {
				cout << "是否加牌?\n是請輸入1\n否請輸入0" << endl;
				cin >> x;	
			}
		}	
	}
	cout << "總點數:" << total << endl;
	return 0;
}
