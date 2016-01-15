#include "tools.hpp"
#include "pgm.hpp"

int main(){
    banner();
    string fileName;
    string outFile;
    cout << "Please enter the .pgm file: ";
    cin >> fileName;
    cout << "Please enter an output file: ";
    cin  >> outFile;
    ofstream out(outFile);
    Pgm pgm = Pgm(fileName.c_str());
    pgm.extract(out);
    bye();
}