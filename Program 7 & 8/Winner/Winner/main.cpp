#include "tools.hpp"

//==============================================================================
void getPrizes(string file);
void getNums(string file);
void check(int prizesLeft);
bool search(int stuID);
void rewardPrize(int prizesLeft);
//==============================================================================


//=============================================================================
string prizes[10];
int nums[50];
//=============================================================================

int main(){
    banner();
    getPrizes("prizes.txt");
    getNums("hello.txt");
    check(10);
    bye();
}

/*=============================================================================
Gets a list of 10 prizes from a file
=============================================================================*/
void getPrizes(string file){
    ifstream input(file);
    if(input.is_open()){
        for(int n = 0; n < 10; n++){
            input >> prizes[n];
        }
    }
    else cout << "Cannot Open File" << endl;
    
}

/*=============================================================================
Gets the 50 lucky numbers from the lotto program
=============================================================================*/
void getNums(string file){
    ifstream input(file);
    if(input.is_open()){
        for(int n = 0; n < 50; n++){
            input >> nums[n];
        }
    }
    else cout << "Cannot Open File" << endl;
}

/*=============================================================================
Gets Student ID and checks if is a Winner
=============================================================================*/
void check(int prizesLeft){
    int stuID;
    cout << "Welcome to the UNH Lotto System!" << endl;
    cout << "There are " << prizesLeft << " Prizes Left" << endl;
    cout << "Please Enter Your Student ID Number: ";
    cin >> stuID;
    cout << string(60, '=') << endl;
    if(search(stuID)){
        rewardPrize(prizesLeft);
        prizesLeft--;
    }
    else{
        cout << "Sorry you are not a Winner this time" << endl;
        cout << "Please try again next week" << endl;
        cout << string(60, '=') << endl;
    }
    
    if(prizesLeft > 0){
        check(prizesLeft);
    }
    else{
        cout << "We are all out of prizes" << endl;
        cout << "Please check back next week for more" << endl;
    }
}

/*=============================================================================
Searchs for the given StuID and returns true if found and false if not found
=============================================================================*/
bool search(int studID){
    int low = 0;
    int high = 50;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == studID) return true;
        else if(nums[mid] < studID) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

/*=============================================================================
 Rewards a random prize from the prizes array
 ============================================================================*/
void rewardPrize(int prizesLeft){
    int pos = 10 - prizesLeft;
    int prizePos = rand() % (10 - pos);
    cout << "CONGRATULATIONS YOU ARE A WINNER!!!" << endl;
    cout << "You Have Won A " << prizes[prizePos] << endl;
    cout << string(60, '=') << endl;
    swap(prizes[pos], prizes[prizePos]);
}