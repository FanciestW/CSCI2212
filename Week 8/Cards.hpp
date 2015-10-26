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
};
