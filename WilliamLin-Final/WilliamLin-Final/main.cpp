//
//  main.cpp
//  Employee Stats
//  Created by Alice Fischer on 12/11/15.
//  Copyright © 2015 Alice Fischer for final exam
//

#include "tools.hpp"
#include "Stats.hpp"

int main( void ) {

    cout << "Beginning\n";
    ifstream infile( "employee.txt" );
    if( !infile ) fatal( "employee.txt cannot be opened for input" );
    cout << "employee.txt is open\n";
    Stats s( infile );
    s.print();
    return 0;
}
