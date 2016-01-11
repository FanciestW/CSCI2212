//
//  Stats.hpp
//  WilliamLin-Final
//
//  Created by William Lin on 12/11/15.
//  Copyright © 2015 William Lin. All rights reserved.
//

#ifndef Stats_hpp
#define Stats_hpp

#include <stdio.h>
#include "tools.hpp"
#include "Employee.hpp"

class Stats{
private:
    ifstream *infile;
    vector<Employee> employees;
    float avgSalary;
    float totSalary;
public:
    Stats(){}
    
    Stats(ifstream &input){
        infile = &input;
        for(;;){
            if(input.eof())break;
            else{
                string firstName, lastName;
                float salary;
                char gender;
                input >> salary;
                input >> gender;
                input >> firstName;
                input >> lastName;
                Employee person(salary, gender, firstName, lastName);
                totSalary += salary;
                employees.push_back(person);
            }
        }
        avgSalary = totSalary/employees.size();
        input.close();
    }
    
    void print();
    void run();
    void printVector();
};

#endif /* Stats_hpp */
