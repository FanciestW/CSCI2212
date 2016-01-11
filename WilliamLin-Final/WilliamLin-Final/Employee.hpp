//
//  Employee.hpp
//  EmployeeStats
//

#ifndef Employee_hpp
#define Employee_hpp
#include "tools.hpp"

class Employee {
  private:
    string name1, name2;
    char gender;
    float salary;
  public:
    Employee( float sal, char gen, string n1, string n2 );
    ~Employee(){}
    float getSalary(){ return salary; }
    char getGender(){ return gender; }
    ostream& print( ostream& out );
    bool operator< (const Employee& b) const{ return salary < b.salary; }
};
inline ostream& operator <<( ostream& out, Employee& emp ){
    return emp.print( out );
}
#endif /* Employee_hpp */
