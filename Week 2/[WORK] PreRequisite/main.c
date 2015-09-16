// CS 610 Lecture 1  January 3, 2011                                      main.c
// Program to make change.
//
#include "tools.h"
#define taxRate .06

float legalInput( float minimum );
float roundUpToPenny( float amount );
void  makeChange ( const float denoms[], int n, float tend, float cost );

int main ( void ) {
    const float denoms[] = {20, 10, 5, 1, .25, .10, .05, .01};
    const int nDenoms = 8;
    
    float price;        // Amount on price tag
    float tendered;     // Money from customer
    float total;        // price + tax
    
    banner();
    printf ("Making Change\n"
            "Please enter price and amount tendered, when prompted.\n" );
    price = legalInput( 0.01 );
    total = roundUpToPenny( price * (1 + taxRate));  

    tendered = legalInput( total );
    printf( "\nPrice = %.2f + tax = %.2f\n", price, total );
    printf( "Amount tendered = %.2f\n", tendered );

    makeChange ( denoms, nDenoms, total, tendered );
    bye();
    return 0;
}

// -----------------------------------------------------------------------------
// Round an amount up to the nearest penny.
float 
roundUpToPenny( float amount ){
    return ceil( amount*100 ) / 100;
}

// -----------------------------------------------------------------------------
// Prompt user to input a dollar amount greater than or equal to the minimum.
float 
legalInput( float minimum ) {
    float input;
    // puts("legalInput called.");
    for (;;) {
        printf ("Enter value >= %.2f: ", minimum );
        scanf ("%f", &input );
        if (input >= minimum) break;
        printf ("Try again; enter a number >%f: ", minimum );    
    }
    return input;
}


// -----------------------------------------------------------------------------
// Given a price and an amount tendered, 
// output a list of coins and bills needed to make change.
void 
makeChange ( const float denoms[], int n, float cost, float tend )
{
    //puts("\n makeChange called.");
    float change;        // Money returned to customer
    float remaining;    // Amount of change not yet printed
    int k = 0;
    remaining = change = tend - cost;
    if (change < 0) {
        printf( "Please give me $%.2f more.\n", -change );
    }
    else printf( "Total change = %.2f\n", change );
    while (remaining > 0 && k<8) {
        if (remaining >= denoms[k]-.001) {
            //if (diff > .001) {
            remaining -= denoms[k];
            printf("\t%5.2f\n", denoms[k] );
        }
        else ++k;
    }
}

/* ---- Output -----------------------------------------------------------------
 Alice E. Fischer 
 CS 610 
 Thu Jan  6 2011  09:49:43
 -------------------------------------------------------
 Making Change
 Please enter price and amount tendered, when prompted.
 Enter value >= 0.01: 0
 Try again; amount is too small
 Enter value >= 0.01: 23.58
 Enter value >= 25.00: 25
 
 Price = 23.58 + tax = 25.00
 Amount tendered = 25.00
 Total change = 0.00
 
 Normal termination.
 
 -------------------------------------------------------
 Making Change
 Please enter price and amount tendered, when prompted.
 Enter value >= 0.01: 20
 Enter value >= 21.20: 50
 
 Price = 20.00 + tax = 21.20
 Amount tendered = 50.00
 Total change = 28.80
 20.00
 5.00
 1.00
 1.00
 1.00
 0.25
 0.25
 0.25
 0.05
 
 Normal termination.
 ----------------------------------------------------------------------------- */

