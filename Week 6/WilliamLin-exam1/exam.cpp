#include "tools.hpp"
#include "tools.cpp"

using namespace std;

//=============================================================================
#define INPUT "exam1.txt"
#define OUTPUT "output1.txt"
char HOLD[4];
//=============================================================================

//=============================================================================
int getKey(void);
int ioFile(void);
int check(ifstream& inputFile, ofstream& outputFile);
//=============================================================================

int main(void)
{
	ioFile();
}

/*=============================================================================
Finds all 4 letter words and prints then to an output file
=============================================================================*/
int ioFile(void)
{
	char x;

	ifstream inputFile;
	inputFile.open(INPUT);
	if(!inputFile) fatal("Cannot open input file");

	ofstream outputFile;
	outputFile.open(OUTPUT);
	if(!outputFile) fatal("Cannot open output file");
	else for(;;)
	{
		string str;
		getline(inputFile, str, ' ');
		str = str.substr(0, str.find(','));
		str = str.substr(0, str.find('.'));
		str = str.substr(0, str.find('\''));
		str = str.substr(0, str.find('?'));
		str = str.substr(0, str.find('!'));
		cout << str << endl;		
		if(str.length() == 4) outputFile << str << endl;
		if(inputFile.eof()) break;
	}

	inputFile.close();
	outputFile.close();
	return 0;
}