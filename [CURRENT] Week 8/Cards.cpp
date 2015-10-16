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
	banner();
	Cards card;
	std::vector<Cards> deck = card.buildDeck();
	bye();
}

/*
OUTPUT:

--------------------------------------------------------
        Alice Fischer
        CS 2212
        Fri Oct 16 2015 14:54:58
----------------------------------------------------------
1 of Diamonds
1 of Hearts
1 of Clubs
1 of Spades
2 of Diamonds
2 of Hearts
2 of Clubs
2 of Spades
3 of Diamonds
3 of Hearts
3 of Clubs
3 of Spades
4 of Diamonds
4 of Hearts
4 of Clubs
4 of Spades
5 of Diamonds
5 of Hearts
5 of Clubs
5 of Spades
6 of Diamonds
6 of Hearts
6 of Clubs
6 of Spades
7 of Diamonds
7 of Hearts
7 of Clubs
7 of Spades
8 of Diamonds
8 of Hearts
8 of Clubs
8 of Spades
9 of Diamonds
9 of Hearts
9 of Clubs
9 of Spades
10 of Diamonds
10 of Hearts
10 of Clubs
10 of Spades
Jack of Diamonds
Jack of Hearts
Jack of Clubs
Jack of Spades
Queen of Diamonds
Queen of Hearts
Queen of Clubs
Queen of Spades
King of Diamonds
King of Hearts
King of Clubs
King of Spades

Normal termination.
*/