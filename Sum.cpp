#include"Sum.h"
Sum::Sum(string color, int math) {
	this->color = color;
	this->math = math;
}
void Sum::setColor(string color) {
	this->color = color;
}
string Sum::getColor() {
	return color;
}
void Sum::setMath(int math) {
	this->math = math;
}
int Sum::getMath() {
	int a;
	if (math == 11 || math == 12 || math == 13)
		math = 10;
	else if (math == 1) {
		cout << "A為1 or 11?" << endl;
		cin >> a;
		if (a == 1)
			math = 1;
		else
			math = 11;
	}
	return math;
}
void Sum::setSum(int sum) {
	this->sum = sum;
}
int Sum::getSum() {
	return sum;
}
