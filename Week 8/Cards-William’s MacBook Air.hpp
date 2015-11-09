#include "tools.hpp"
#include "tools.cpp"

class CardT{
    private:
		int suitT, rankT, point;
	public:
		CardT(){}
    
		CardT(int suit, int rank){
			suitT = suit;
			rankT = rank;
            point = rank;
		}
		void printCard(ostream& out);
};
