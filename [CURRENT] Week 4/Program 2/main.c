#include "tools.h"
#include "tools.c"


//=============================================================================
void getInfo(void);
int ioFile(void);
int check(int x, cstream inputFile, cstream outputFile);
//=============================================================================

//=============================================================================
#define MAXREAD
char INPUT[256];
char OUTPUT[256];
char KEYWORD[256];
char REPLACE[256];
char HOLD[256];
int count = 0;
//=============================================================================

int main(void)
{
    banner();
    getInfo();
    ioFile();
    printf("%s", KEYWORD);
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
 =============================================================================*/
int ioFile(void)
{
    int x;
    
    cstream inputFile = fopen(INPUT, "r");
    cstream outputFile = fopen(OUTPUT, "w");
    if(!inputFile) fatal("Cannot open file at %s", INPUT);
    else if(!outputFile) fatal("Cannot open file at %s", OUTPUT);
    else for(;;)
    {
        //If the user types the wrong file name, the program doesn't know what
        //to do when it gets to x = fgetc(inputfile) so the program crashes because
        //inputfile does not really exist.
        
        //However, I changed this for(;;) loop so it is a part of an if..else statement.
        //Now, this for(;;) loop only executes if the files exist.
        
        //However, you can play around as there are multiple ways to deal with
        //bad user input.
        
        x = fgetc(inputFile);
        if(x == EOF) break;
        //Below, what is (x==0) checking for?
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
    return 0;
}

/*=============================================================================
 Checks the word matches the keyword. If so, word is replaces.
 =============================================================================*/
int check(int x, cstream inputFile, cstream outputFile)
{
    //MATCH isn't the best title for this local array.
    //This local array should store the letters from the input stream as you get them.
    //Then, once you have stored the right number of letters, you can compare
    //this array to the keyword. If they are the same, print out the replacement word.
    //If the keyword and the stored letters are not the same, print out this local array.
    HOLD[0] = x;
    for(int k = 1; k < strlen(KEYWORD); k++)
    {
        x = fgetc(inputFile);
        
        //below, nothing happens if x equals the keyword.
        //MATCH[k] doesn't do anything - you aren't assigning anything to MATCH[k]
        if(x == KEYWORD[k]) HOLD[k];
        else
        {
            fprintf(outputFile, "%s", HOLD);
            return 0;
        }
    }
    fprintf(outputFile, "%s", REPLACE);
    count++;
    return 0;
    
}
