#include "tools.h"
#include "tools.c"

//=============================================================================
int getInfo(void);
int ioFile(void);
int check(int x, cstream inputFile, cstream outputFile);
//=============================================================================

//=============================================================================
char INPUT[256];
char OUTPUT[256];
char KEYWORD[256];
char REPLACE[256];
char MATCH[256];
int count = 0;
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
int getInfo(void)
{
	printf("Input File: ");
	scanf("%255s", INPUT);
	printf("Output File: ");
	scanf("%255s", OUTPUT);
	printf("Keyword: ");
	scanf("%255s", KEYWORD);
	printf("Replace: ");
	scanf("%255s", REPLACE);
}

/*=============================================================================
Reads input file and writes to output file, replacing keyword with replacement
=============================================================================*/
int ioFile(void)
{
	cstream inputFile = fopen(INPUT, "r");
	cstream outputFile = fopen(OUTPUT, "w");
	if(!inputFile) fatal("Cannot open file at %s", INPUT);
	if(!outputFile) fatal("Cannot open file at %s", OUTPUT);

	int x;
	for(;;)
	{	
		x = fgetc(inputFile);
		if(x == EOF) break;
		if(x == 0)
		{
			fatal("File Read Error");
			return 0;
		}
		if(x == KEYWORD[0]) check(x, inputFile, outputFile);
		else fprintf(outputFile, "%c", x);
	}
	printf("\n%i Matches\n", count);
	fclose(inputFile);
	fclose(outputFile);
}

/*=============================================================================
Checks the word matches the keyword. If so, word is replaces.
=============================================================================*/ 
int check(int x, cstream inputFile, cstream outputFile)
{
	MATCH[0] = x;
	for(int k = 1; k < strlen(KEYWORD); k++)
	{
		x = fgetc(inputFile);
		if(x == KEYWORD[k]) MATCH[k];
		else
		{
			fprintf(outputFile, "%s", MATCH);
			return 0;
		}
	}
	fprintf(outputFile, "%s", REPLACE);
	count++;
	return 0;
}