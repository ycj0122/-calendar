#include"Dealer.h"
Dealer::Dealer() {

}
Dealer::Dealer(string card) {
    setCard(card);
}
void Dealer::setCard(string card) {		//抽到的牌
    this->card = card;
}
string Dealer::getCard()const {
    return card;
}
void Dealer::setNowpoint(int point) {    //目前點數
    this->point = point;
}
int Dealer::getNowpont() {
    return point;
}
void Dealer::setTotalpoint(int point) {        //總點數
    this->point = point;
}
int Dealer::getTotalpoint() {
    return point;
}
