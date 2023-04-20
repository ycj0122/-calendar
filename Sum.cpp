#include"Sum.h"
Sum::Sum(int color, int math) {
	this->color = color;
	this->math = math;
}
void Sum::setColor(int c) {
	if (c == 0) color = "黑桃";
	else if (c == 1) color = "紅心";
	else if (c == 2) color = "方塊";
	else color = "梅花";
}
string Sum::getColor() {
	return color;
}
void Sum::setMath(int math) {
	this->math = math;
}
int Sum::getMath() {
	if (math == 11 || math == 12 || math == 13)
		math = 10;
	return math;
}
void Sum::setSum(int sum) {
	this->sum = sum;
}
int Sum::getSum() {
	return sum;
}
