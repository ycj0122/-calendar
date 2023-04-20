#ifndef S_H
#define S_H
#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
class Sum {
public:
	Sum(int, int);
	void setColor(int);
	string getColor();
	void setMath(int);
	int getMath();
	void setSum(int);
	int getSum();
private:
	string color;
	int math, sum;
	int cardArray[4][13];
};
#endif
