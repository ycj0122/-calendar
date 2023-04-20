#ifndef C_H
#define C_H
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
class Card {
public:
	Card(string,int);
	void setColor(string);
	string getColor();
	void setMath(int);
	int getMath();
	void setSum(int);
	int getSum();
	void print();
private:
	string color;
	int math,sum;
};
#endif
