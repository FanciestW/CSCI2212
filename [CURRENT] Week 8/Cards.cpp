#include "tools.hpp"
#include "tools.cpp"

class Cards{
	private:
		int suit, rank;
	public:
		Cards(){
		}

		void setCard(int x, int y){
			suit = x;
			rank = y;
		}
		void buildDeck(){
			Cards deck[52];
			int index = 0;
			for(int suit = 0; suit < 4; suit++){
				for(int rank = 1; rank < 14; rank++){
					deck[index] = Cards();
					deck[index].setCard(suit, rank);
					index++;
				}
			}
		}
};

int main(){
}