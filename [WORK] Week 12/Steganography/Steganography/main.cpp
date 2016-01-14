#include "tools.hpp"
#include "pgm.hpp"

int main(){
    banner();
    string fileName;
    cout << "Please enter the name of the .pgm file: ";
    cin >> fileName;
    Pgm pgm = Pgm(fileName.c_str());
    
    bye();
}