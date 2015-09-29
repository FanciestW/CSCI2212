#include "tools.h"
#include "tools.c"

//=============================================================================
#define MAXREAD "255"
#define MAXSIZE 256
char INPUT[MAXSIZE];
char OUTPUT[MAXSIZE];
char KEYWORD[MAXSIZE];
char REPLACE[MAXSIZE];
char HOLD[MAXSIZE];
//=============================================================================

//=============================================================================
void getInfo(void);
int ioFile(void);
int check(int x, cstream inputFile, cstream outputFile);
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
    printf("Input File: ");
    scanf("%" MAXREAD "s", INPUT);
    printf("Output File: ");
    scanf("%" MAXREAD "s", OUTPUT);
    printf("Keyword: ");
    scanf("%" MAXREAD "s", KEYWORD);
    printf("Replace: ");
    scanf("%" MAXREAD "s", REPLACE);
}

/*=============================================================================
 Reads input file and writes to output file, replacing keyword with replacement
 ============================================================================*/
int ioFile(void)
{
    int x;
    
    cstream inputFile = fopen(INPUT, "r");
    cstream outputFile = fopen(OUTPUT, "w");
    if(!inputFile) fatal("Cannot open file at %s", INPUT);
    else if(!outputFile) fatal("Cannot open file at %s", OUTPUT);
    else for(;;)
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
    return 0;
}

/*=============================================================================
 Checks if the word matches the keyword. If so, word is replaces.
 =============================================================================*/
int check(int x, cstream inputFile, cstream outputFile)
{
    HOLD[0] = x;
    for(int k = 1; k < strlen(KEYWORD); k++)
    {
        char m = fgetc(inputFile);
        HOLD[k] = m;
    }
    if(!strcmp(KEYWORD, HOLD)) fprintf(outputFile, "%s", REPLACE);
    else fprintf(outputFile, "%s", HOLD);
    return 0;
}
