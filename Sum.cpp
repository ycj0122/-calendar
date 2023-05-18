#include"Sum.h"
Sum::Sum() {
	card = "黑桃 A";
}
Sum::Sum(string card) {
	this->card = card;
}
void Sum::setCard(string card) {
	this->card = card;
	stringstream ss(card);
	int i = 0;
	while (!ss.eof()) {
		ss >> word[i];
		i++;
	}
	if (word[1] == "J" || word[1] == "Q" || word[1] == "K")
		math = 10;
	else if (word[1] == "A") {
		cout << "A為1 or 11?" << endl;
		int a;
		cin >> a;
		math = a;
	}
	else
		math = stoi(word[1]);
}
string Sum::getColor() {
	return word[0];
}
int Sum::getMath() {
	return math;
}
void Sum::setSum(int sum) {
	this->sum = sum;
}
int Sum::getSum() {
	return sum;
}
void Sum::print() {
	cout << card << endl << "目前點數:" << getSum() << endl;
}
