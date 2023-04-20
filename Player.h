#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

class Player {
public:
Player(); // 初始化
void hit(Card &card); // 玩家補牌
void printCards(); // 列印所有牌
int getSum(); // 取得牌點數總和
bool isBust(); // 是否爆牌
void reset(); // 重置牌局
private:
vector<Card> cards; // 玩家的牌
};

#endif
