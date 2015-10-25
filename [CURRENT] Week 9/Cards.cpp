#include "tools.hpp"
#include "tools.cpp"

const int point[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
const string ranks[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const string suits[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
enum SuitT {SPADES, HEARTS, DIAMONDS, CLUBS}; 

class CardT{
	private:
		int suitT, rankT;
	public:
		CardT(){

		}
		
		CardT(int suit, int rank){
			suitT = suit;
			rankT = rank;
		}

		void setCard(int x, int y){
			suitT = x;
			rankT = y;
		}

		void printCard(ostream& out){
			out << ranks[rankT] << " of ";
			out << suits[suitT] << " Points: ";
			out << point[rankT] << endl;
		}
};

class DeckT{
	private:
		std::ostream *output;
		int amtCard;
	public:
		DeckT(){

		}

		DeckT(std::ostream *out){
			output = out;
		}
};

int main(){
	banner();
	CardT cards[52];
	for(int rank = 0; rank < 13; rank++){
		for(int suit = 0; suit < 4; suit++){
			cards[rank * suit] = CardT(suit, rank);
		}
	}
	DeckT deck = DeckT(&cout);
	bye();
}