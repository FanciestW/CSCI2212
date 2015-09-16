#include "tools.h"
#include "tools.c"

int input(char output[]);
int check(char x, char str[]);
void dance(char type, char str[]);

int TYPE;
char STR[80];

int main(void)
{	
	/*
	banner and bye are used to display program information
	and termination status.
	*/
	banner();
	
	input("Input Your Dance: "); //Calls the input function with a string parameter.
	if(check(TYPE, STR)) dance(TYPE, STR);

	bye();
}

/*
This function calls for a string input and the parameter 
prompts the user as to what they need to enter.
the output parameter is used to display to the user what they will be entering.
*/
int input(char output[])
{
	printf("%s", output); //Prompts the user for their input.
	scanf("%c %s", &TYPE, &STR); //Gets the users input with to input formats, the type of dance and string.
	return 0;
}


int check(char x, char str[])
{
	if(x == '2' || x == '3' || x == '4') //Checks the value of x. 2, 3, and 4
	{	
		return 1;
	}
	else if(x == '#') //'#' ends program
	{
		printf("Good Bye");
	}
	else printf("Invalid Input\n"); 
	return 0;
}


void dance(char type, char str[])
{	
	printf("\n%s\n\n", str); //Echo prints the users inputted string.
	int c = 0; //Initializes a counter for dances 3 and 4.
	switch(type) 
	{
		case '2':
			for(int k = 0; k <= strlen(str); k++) 
			{			
				if(k % 2) //when k is odd
				{	
					str[k] = tolower(str[k]);
				}
				else str[k] = toupper(str[k]); //when k is even
			}
			printf("%s\n", str); //The output after the dance is applied.
		break;

		case '3': 
			for(int k = 0; k <= strlen(str); k++)
			{
				if(c == 0) //c must count to 2
				{	
					str[k] = toupper(str[k]);
				}
				else
				{
					str[k] = tolower(str[k]); 
				}
				c++; //increment c to start counting c, the placeholder.
				if(c == 3) c = 0; //allows for the pattern of -__-__-__-...
			}
			printf("%s\n", str);
		break;

		case '4':
			for(int k = 0; k <= strlen(str); k++)
			{
				if(c == 0)
				{	
					str[k] = toupper(str[k]);
				}
				else
				{
					str[k] = tolower(str[k]);
				}
				c++;
				if(c == 4) c = 0; // allows for the pattern of -___-___-___-...
			}
			printf("%s\n", str);
		break;

		default:
			puts("Error Please Report To William Lin"); 
		break;			
	}
}

//-----------------------------------------------------------------------------
/*

-------------------------------------------------------
        William Lin
        CSCI 2212
        Tue Sep 08 2015  13:31:44
-------------------------------------------------------
Input Your Dance: 2 HelloWorld

HelloWorld

HeLlOwOrLd

Normal termination.
*/
//-----------------------------------------------------------------------------
/*

-------------------------------------------------------
        William Lin
        CSCI 2212
        Tue Sep 08 2015  13:35:24
-------------------------------------------------------
Input Your Dance: 3 WilliamLin

WilliamLin

WilLiaMliN

Normal termination.
*/
//-----------------------------------------------------------------------------
/*

-------------------------------------------------------
        William Lin
        CSCI 2212
        Tue Sep 08 2015  13:36:13
-------------------------------------------------------
Input Your Dance: 4 TestingTesting

TestingTesting

TestIngtEstiNg

Normal termination.
*/
//-----------------------------------------------------------------------------
/*

-------------------------------------------------------
        William Lin
        CSCI 2212
        Tue Sep 08 2015  13:38:59
-------------------------------------------------------
Input Your Dance: # Bye
Good Bye
Normal termination.
*/
