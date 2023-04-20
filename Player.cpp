#include "Player.h"

Player::Player() {}

void Player::hit(Card &card) {
// 玩家補牌
cards.push_back(card);
}

void Player::printCards() {
// 列印所有牌
cout << "Player: " << endl;
for (int i = 0; i < cards.size(); i++) {
cards[i].print();
}
}

int Player::getSum() {
// 取得牌點數總和
int sum = 0;
int aceCount = 0;
for (int i = 0; i < cards.size(); i++) {
sum += cards[i].getMath();
if (cards[i].getMath() == 1) {
aceCount++;
}
}
while (aceCount > 0 && sum + 10 <= 21) {
sum += 10;
aceCount--;
}
return sum;
}

bool Player::isBust() {
// 是否爆牌
return getSum() > 21;
}

void Player::reset() {
// 重置牌局
cards.clear();
}
