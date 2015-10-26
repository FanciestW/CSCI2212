#include "tools.hpp"
#include "tools.cpp"

class CardT{
	private:
		int suitT, rankT;
	public:
		CardT(){}
		CardT(int suit, int rank){
			suitT = suit;
			rankT = rank;
		}
		void printCard(ostream& out);
		void printSerial(ostream& out);
};

class DeckT{
	private:
		ostream *output;
		int amtCard;
        CardT cards[52];
	public:
		DeckT(){}
		DeckT(ostream *out){
			output = out;
		}
		void createDeck();
        void printDeck(ostream *out);
        void printSerialDeck(ostream *out);
};
