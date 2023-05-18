#ifndef S_H
#define S_H
#include<string>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<sstream>
#include<algorithm>
using namespace std;
class Sum {
public:
	Sum();
	Sum(string);
	void setCard(string);
	string getColor();
	int getMath();
	void setSum(int);
	int getSum();
	void print();
private:
	string color, card;
	int math, sum;
	string word[2];
};
#endif
