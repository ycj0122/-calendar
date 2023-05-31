#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Sum.h"

using namespace std; 

class Player {
public:
    Player();
    void addCard(const string& card); //增加牌
    bool getTotalSum() const; //拿到的點數
    void printCards() const;

private:
    string name;
    vector<Sum> cards;
};

#endif
