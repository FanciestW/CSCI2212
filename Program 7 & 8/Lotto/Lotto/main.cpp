#include "tools.hpp"

//=============================================================================
void fileWrite(string file);
void randNum(int lim, int recur);
void seleSort();
int findMax(int arr[], int n);
int findMin(int arr[], int n);
//=============================================================================

//=============================================================================
int stuID[50];
//=============================================================================

int main(){
    banner();
    randNum(999, 50);
    seleSort();
    fileWrite("hello.txt");;
    bye(); 
}

/*=============================================================================
Writes array randID to a file
=============================================================================*/
void fileWrite(string file){
    ofstream outputFile(file);
    if(outputFile.is_open()){
        for(int n = 0; n < 50; n++){
            outputFile << stuID[n] << endl;
        }
        outputFile.close();
    }
    else cout << "Cannot open File" << endl;
    
    outputFile.close();
}

void randNum(int lim, int recur){
    for(int n = 0; n < recur; n++){
        stuID[n] = rand() % lim;
    }
}

void seleSort(){
    int pos, largest, largestPos;
    int n = sizeof(stuID)/sizeof(*stuID);
    for(pos = n - 1; pos > 0; --pos){
        largestPos = findMax(stuID, n);
        largest = stuID[largestPos];
        swap(stuID[pos], stuID[largestPos]);
        --n;
    }
}

int findMax(int arr[], int n){
    int maxPos = 0;
    int maxVal = arr[0];
    for(int m = 1; m < n; m++){
        if(arr[m] > maxVal){
            maxVal = arr[m];
            maxPos = m;
        }
    }
    
    return maxPos;
}

