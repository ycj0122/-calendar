#ifndef DEALER_H
#define DEALER_H
#include <string>
#include <iostream>
#include "Sum.h"
using namespace std;
class Dealer {
public:
    Dealer();
    Dealer(string);
    void setCard(string);//抽到的牌
    string getCard()const;
    void setNowpoint(int);//目前點數
    int getNowpont();
    void setTotalpoint(int);//總點數
    int getTotalpoint();
private:
    string card;
    string cardArray[5];
    int point;
};
#endif
