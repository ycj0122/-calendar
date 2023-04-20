#include"Card.h"
Card::Card(string color, int math) {
	this->color = color;
	this->math = math;
}
void Card::setColor(string color) {
	this->color = color;
}
string Card::getColor() {
	return color;
}
void Card::setMath(int math) {
	this->math = math;
}
int Card::getMath() {
	return math;
}
void Card::setSum(int sum) {
	this->sum = sum;
}
int Card::getSum() {
	return sum ;
}
void Card::print() {
	cout << "目前點數:" << getSum() << endl;
}
