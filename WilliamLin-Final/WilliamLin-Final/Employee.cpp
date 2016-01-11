//
//  Employee.cpp
//  Employees
//
#include "Employee.hpp"

//----------------------------------------------
Employee::Employee( float sal, char gen, string n1, string n2 ){
    salary = sal;
    gender =  gen;
    name1 = n1;
    name2 = n2;
}

//---------------------------------------------
ostream& Employee::print( ostream& out ) {
    out << fixed << setprecision(2) << setw(10)
    << salary << "   " << gender << "   " << name1<< " "<< name2;
    return out;
}
