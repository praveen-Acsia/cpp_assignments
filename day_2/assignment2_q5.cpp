#include <iostream>


using namespace std;

void decrement(int& nNum){
    nNum--;
}

int main(){

    static int nNumber;
    int nFactorial;

    cout << "enter a number: " << endl;
    cin>>nNumber;

    nFactorial = nNumber;

    for(int i =1 ; i <=nNumber ; i++){

        decrement(nNumber);
        nFactorial *= nNumber;
    }
    cout << "factorial is: 5" << nFactorial;
}