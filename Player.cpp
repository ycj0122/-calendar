#include"Player.h"
Player::Player() {

}
Player::Player(string card) {
    setCard(card);
}
void Player::setCard(string card) {		//抽到的牌
    this->card = card;
}
string Player::getCard()const {
    return card;
}
void Player::setNowpoint(int point) {    //目前點數
    this->point = point;
}
int Player::getNowpont() {
    return point;
}
void Player::setTotalpoint(int totalpoint) {        //總點數
    this->totalpoint = totalpoint;
}
int Player::getTotalpoint() {
    return totalpoint;
}
