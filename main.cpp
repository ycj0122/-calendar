#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<ctime>
#include<algorithm>
#include"Sum.h"
using namespace std;
Sum card("花色",10);
string*  Card(string cardArray[]) {		//建立牌組並洗牌
	string* r = new string[52];
	string colorArray[4]={"黑桃","紅心","方塊","梅花"};
	string mathArray[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	int n = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			string color = colorArray[i];
			string math = mathArray[j];
			string cards ;
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

int draw(string cardArray[], int total) {	//抽牌並帶入加總物件
	int x = 0;
	srand(time(0));
	while (x!=-1) {
		int number= rand() % 52;
		stringstream ss(cardArray[number]);
		string word[2];
		int i = 0, math;
		while (!ss.eof()) {
			ss >> word[i];
			i++;
		}
		if (word[1] == "J" || word[1] == "Q" || word[1] == "K")
			math = 10;
		else if (word[1] == "A") 
			math = 1;
		else
			math = stoi(word[1]);
		if (math != 0) {
			card.setColor(word[0]);
			card.setMath(math);
			total += math;
			card.setSum(total);
			cout << card.getColor() << " " << card.getMath()<< endl
			<< "目前點數:" << card.getSum()<< endl;
			x = -1;
		}
		else if (card.getSum() > 21) {
			x = -1;
		}
	}
	return card.getSum();
}

int main() {
	cout << "Game Start" << endl;
	string cardArray[52];
	Card(cardArray);
	int total = 0,x = 1;
	while (x != 0) {
		total=draw(cardArray,total); 
		if (total > 21) {
			cout  <<"Game Over\n";
			x = 0;
		}
		else {
			cout << "是否加牌?\n是請輸入1\n否請輸入0" << endl;		
			cin >> x;
		}
	}
	cout << "總點數:" <<total<< endl;
	return 0;
}
