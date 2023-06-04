#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<ctime>
#include<algorithm>
#include"Sum.h"
#include"Player.h"
#include"Dealer.h"
using namespace std;
//建立牌組並洗牌
string* Card(string cardArray[]) {
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
//比大小
void Winner(int p, int pc, int d, int dc) {
	if ((p > d && p <= 21) || (pc == 5 && p <= 21)) {
		cout << "\nPlayer Win\n" << endl;
	}
	else if ((d > p && d <= 21) || (dc == 5 && d <= 21)) {
		cout << "\nDealer Win\n" << endl;
	}
	else
		cout << "\nNo Win\n" << endl;
	cout << "\nGame Over\n" << endl;
}
int main() {
	cout << "Game Start" << endl;
	Dealer dealer;
	Player player;
	Sum sum;
	string cardArray[52];
	string playercardArray[5];
	string dealercardArray[5];
	int ppoint = 0, dpoint = 0, i = 0, j = 0, x = 1, y = 1;
	Card(cardArray);
	srand(time(0));
	//玩家回合
	cout << "\nPlayer round\n" << endl;
	for (int p = 0; p < 2; p++) {
		int number = rand() % 52;
		if (cardArray[number] != "z") {
			player.setCard(cardArray[number]);
			playercardArray[p] = cardArray[number];
			sum.setCard(cardArray[number]);
			sum.setSum(ppoint);
			player.setNowpoint(sum.getSum());
			ppoint = player.getNowpont();
			cout << player.getCard() << " " << "目前點數:" << player.getNowpont() << endl;
			player.setTotalpoint(player.getNowpont());
			playercardArray[i] = cardArray[number];
			cardArray[number] = "z";
			i++;
		}
		else
			p--;
	}
	while (x != 0) {
		int number = rand() % 52;
		if (cardArray[number] != "z") {
			if (i == 5 || ppoint > 21)
				x = 0;
			else {
				cout << "是否加牌?\n是請輸入1\n否請輸入0" << endl;
				cin >> x;
				if (x == 1) {
					player.setCard(cardArray[number]);
					playercardArray[i] = cardArray[number];
					sum.setCard(cardArray[number]);
					sum.setSum(ppoint);
					player.setNowpoint(sum.getSum());
					ppoint = player.getNowpont();
					cout << player.getCard() << " " << "目前點數:" << player.getNowpont() << endl;
					player.setTotalpoint(player.getNowpont());
					playercardArray[i] = cardArray[number];
					cardArray[number] = "z";
				}
				i++;
			}
		}
	}
	cout << "手牌:";
	for (int i = 0; i < 5; i++) {
		cout << playercardArray[i] << " ";
	}
	cout << "\n總點數:" << player.getTotalpoint() << endl;
	//莊家回合
	cout << "\nDealer round\n" << endl;
	for (int d = 0; d < 2; d++) {
		int number = rand() % 52;
		if (cardArray[number] != "z") {
			dealer.setCard(cardArray[number]);
			dealercardArray[d] = cardArray[number];
			sum.setCard(cardArray[number]);
			sum.setSum(dpoint);
			dealer.setNowpoint(sum.getSum());
			dpoint = dealer.getNowpont();
			cout << dealer.getCard() << " " << "目前點數:" << dealer.getNowpont() << endl;
			dealer.setTotalpoint(dealer.getNowpont());
			dealercardArray[j] = cardArray[number];
			cardArray[number] = "z";
			j++;
		}
		else
			d--;
	}
	while (y != 0) {
		int number = rand() % 52;
		if (cardArray[number] != "z") {
			if (j == 5 || dpoint > 21)
				y = 0;
			else {
				if (j <= 5 && dpoint < 17) {
					dealer.setCard(cardArray[number]);
					dealercardArray[j] = cardArray[number];
					sum.setCard(cardArray[number]);
					sum.setSum(dpoint);
					dealer.setNowpoint(sum.getSum());
					dpoint = dealer.getNowpont();
					cout << dealer.getCard() << " " << "目前點數:" << dealer.getNowpont() << endl;
					dealer.setTotalpoint(dealer.getNowpont());
					dealercardArray[j] = cardArray[number];
					cardArray[number] = "z";
				}
				else {
					cout << "是否加牌?\n是請輸入1\n否請輸入0" << endl;
					cin >> y;
					if (y == 1) {
						dealer.setCard(cardArray[number]);
						dealercardArray[j] = cardArray[number];
						sum.setCard(cardArray[number]);
						sum.setSum(dpoint);
						dealer.setNowpoint(sum.getSum());
						dpoint = dealer.getNowpont();
						cout << dealer.getCard() << " " << "目前點數:" << dealer.getNowpont() << endl;
						dealer.setTotalpoint(dealer.getNowpont());
						dealercardArray[j] = cardArray[number];
						cardArray[number] = "z";
					}
				}
			}
			j++;
		}
	}
	cout << "手牌:";
	for (int i = 0; i < 5; i++) {
		cout << dealercardArray[i] << " ";
	}
	cout << "\n總點數:" << dealer.getTotalpoint() << endl;
	Winner(player.getTotalpoint(), i, dealer.getTotalpoint(), j);
	return 0;
}
