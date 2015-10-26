#include "Cards.hpp"

const int point[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
const string ranks[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const string suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
enum SuitT {SPADES, HEARTS, DIAMONDS, CLUBS};

void CardT::print(ostream& out){
    out.width(10);
    out << left << ranks[rankT];
    out.width(10);
    out << suits[suitT];
    out.width(10);
    out << right << "Point: " << point[rankT] << endl;
}

void CardT::serialize(ostream& out){
    out.width(5);
    out << left << rankT;
    out.width(5);
    out << suitT;
    out.width(5);
    out << right  << point[rankT] << endl;
}

void DeckT::createDeck(){
    int index = 0;
    for(int rank = 0; rank < 13; rank++){
        for(int suit = 0; suit < 4; suit++){
            cards[index] = CardT(suit, rank);
            index++;
        }
    }
}

void DeckT::printDeck(ostream& out){
    for(int n = 0; n < 52; n++){
        cards[n].print(out);
    }
}

void DeckT::printSerialDeck(ostream& out){
    for(int n = 0; n < 52; n++){
        cards[n].serialize(out);
    }
}

int main(){
	banner();
	srand((unsigned) time(NULL));
	DeckT deck = DeckT(&cout);
	deck.print();
	deck.serialize(cout);
	bye();
}
