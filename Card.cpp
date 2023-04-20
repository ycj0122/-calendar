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
	return sum+math;
}
void Card::print() {
	cout << "current points:" << getSum() << endl;
}