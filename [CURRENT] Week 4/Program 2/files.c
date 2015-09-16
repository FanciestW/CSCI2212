#include "tools.h"
#include "tools.c"

//=============================================================================
int getInfo(void);
int input(void);
int check(int x, cstream inputFile, cstream outputFile);
//=============================================================================

char INPUT[256];
char OUTPUT[256];
char KEYWORD[256];
char REPLACE[256];
char MATCH[256];

int main(void)
{
	banner();
	getInfo();
	input();
}

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

int input(void)
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
	fclose(inputFile);
	fclose(outputFile);
	bye();
}

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
			printf("%s\n",MATCH);
			return 0;
		}
	}
	fprintf(outputFile, "%s", REPLACE);
	return 0;
}