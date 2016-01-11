#include "tools.hpp"

using namespace std;

//=============================================================================
string INPUT;
string OUTPUT;
string KEYWORD;
string REPLACE;
char HOLD[256];
//=============================================================================

//=============================================================================
void getInfo(void);
int ioFile(void);
int check(char x, ifstream &inputFile, ofstream &outputFile);
//=============================================================================

int main(void)
{
	banner();
	getInfo();
	ioFile();
	bye();
}

/*=============================================================================
Gets a user inputted input file, output file, keyword, and replacement word
=============================================================================*/
void getInfo(void)
{
	cout << "Input File: ";
	cin >> INPUT;
	cout << "Output File: ";
	cin >> OUTPUT;
	cout << "Keyword: ";
	cin >> KEYWORD;
	cout << "Replace: ";
	cin >> REPLACE;
}

/*=============================================================================
Reads input file and writes to output file, replacing keyword wit replacement
=============================================================================*/
int ioFile(void)
{
	char x;

	ifstream inputFile(INPUT.c_str());
	if(!inputFile) fatal("Cannot open file");
	ofstream outputFile(OUTPUT.c_str());
	if(!outputFile) fatal("Cannot open file");
	else for(;;){
        inputFile.get(x);
        if(inputFile.eof()) break;
        if(x == 0){
            fatal("File Read Error");
            return 0;
        }
        if(x == KEYWORD.at(0)) check(x, inputFile, outputFile);
        else outputFile << x;
	}

	inputFile.close();
	outputFile.close();
	return 0;
}

/*=============================================================================
Checks if the word matches the keyword, If so, word is replaces
=============================================================================*/
int check(char x, ifstream &inputFile, ofstream &outputFile)
{
	HOLD[0] = x;
	for(int k = 1; k < KEYWORD.length(); k++)
	{
		char m;
		inputFile.get(m);
		HOLD[k] = m;
	}
	if(KEYWORD.compare(HOLD) == 0) outputFile << REPLACE;
	else outputFile << HOLD;
	return 0;
}