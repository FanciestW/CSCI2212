#include "tools.hpp"
#include "tools.cpp"

string suits[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
string ranks[4] = {"Diamonds", "Hearts", "Clubs", "Spades"}; 

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

		void printCard(){
			std::cout << suits[suit] << " of ";
			std::cout << ranks[rank] << endl;
		}

		std::vector<Cards> buildDeck(){
			std::vector<Cards> deck(52);
			int index = 0;
			for(int suit = 0; suit < 13; suit++){
				for(int rank = 0; rank < 4; rank++){
					deck[index] = Cards();
					deck[index].setCard(suit, rank);
					deck[index].printCard();
					index++;
				}
			}
			return deck;
		}

		void printDeck(std::vector<Cards> deck){
		
		}
};

int main(){
	Cards card;
	std::vector<Cards> deck = card.buildDeck();
}