#include "Player.h"

Player::Player() {
    name = "Player";
}

Player::Player(const string& name) {
    this->name = name;
}

void Player::setName(const string& name) {
    this->name = name;
}

string Player::getName() const {
    return name;
}

void Player::addCard(const string& card) {
    Sum newCard(card);
    cards.push_back(newCard);
}

void Player::clearCards() {
    cards.clear();
}

int Player::getTotalSum() const {
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
