#include "tools.hpp"
#include "tools.cpp"

const int point[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
const string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
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
			out.width(10);
			out << left << ranks[rankT];
			out.width(10);
			out << suits[suitT];
			out.width(10);
			out << right << "Point: " << point[rankT] << endl;
		}
};

int main(){
	banner();
	CardT deck[52];
	int index = 0;
	for(int rank = 0; rank < 13; rank++){
		for(int suit = 0; suit < 4; suit++){
			deck[index] = CardT(suit, rank);
			deck[index].printCard(cout);
		}
	}
	bye();
}

/*
OUTPUT:

--------------------------------------------------------
        Alice Fischer
        CS 2212
        Sun Oct 25 2015 15:05:54
----------------------------------------------------------
1 of Spades Points: 1
1 of Hearts Points: 1
1 of Diamonds Points: 1
1 of Clubs Points: 1
2 of Spades Points: 2
2 of Hearts Points: 2
2 of Diamonds Points: 2
2 of Clubs Points: 2
3 of Spades Points: 3
3 of Hearts Points: 3
3 of Diamonds Points: 3
3 of Clubs Points: 3
4 of Spades Points: 4
4 of Hearts Points: 4
4 of Diamonds Points: 4
4 of Clubs Points: 4
5 of Spades Points: 5
5 of Hearts Points: 5
5 of Diamonds Points: 5
5 of Clubs Points: 5
6 of Spades Points: 6
6 of Hearts Points: 6
6 of Diamonds Points: 6
6 of Clubs Points: 6
7 of Spades Points: 7
7 of Hearts Points: 7
7 of Diamonds Points: 7
7 of Clubs Points: 7
8 of Spades Points: 8
8 of Hearts Points: 8
8 of Diamonds Points: 8
8 of Clubs Points: 8
9 of Spades Points: 9
9 of Hearts Points: 9
9 of Diamonds Points: 9
9 of Clubs Points: 9
10 of Spades Points: 10
10 of Hearts Points: 10
10 of Diamonds Points: 10
10 of Clubs Points: 10
Jack of Spades Points: 10
Jack of Hearts Points: 10
Jack of Diamonds Points: 10
Jack of Clubs Points: 10
Queen of Spades Points: 10
Queen of Hearts Points: 10
Queen of Diamonds Points: 10
Queen of Clubs Points: 10
King of Spades Points: 10
King of Hearts Points: 10
King of Diamonds Points: 10
King of Clubs Points: 10

Normal termination.
*/
