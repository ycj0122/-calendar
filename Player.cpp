#include "Player.h"

Player::Player() {
}

void Player::addCard(const string& card) {
    Sum newCard(card);
    cards.push_back(newCard);
}

bool Player::getTotalSum() const {
    int totalSum = 0;
    int numOfAces = 0;

    for (const auto& card : cards) {
        int math = card.getMath();
        totalSum += math;

        if (math == 1)
            numOfAces++;
    }

    while (numOfAces > 0 && totalSum + 10 <= 21) {
        totalSum += 10;
        numOfAces--;
    }

    return totalSum;
}

void Player::printCards() const {
    cout << "=== " << name << "的牌 ===" << endl;
    for (const auto& card : cards) {
        card.print();
    }
    cout << "總點數: " << getTotalSum() << endl;
}
