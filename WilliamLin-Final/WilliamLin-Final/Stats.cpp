//
//  Stats.cpp
//  WilliamLin-Final
//
//  Created by William Lin on 12/11/15.
//  Copyright © 2015 William Lin. All rights reserved.
//

#include "Stats.hpp"

void Stats::print(){
    cout << "File Location: " << infile << endl;
    cout << "Total Salary: " << totSalary << endl;
    cout << "Average Salary: " << avgSalary << endl;
    printVector();
}

void Stats::printVector(){
    for(int n = 0; n < employees.size(); n++){
        employees[n].print(cout);
        cout << endl;
    }
}

void Stats::run(){
    for(int n = 0; n < employees.size(); n++){
        
    }
}