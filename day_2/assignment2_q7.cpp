#include <iostream>
#include <math.h>

#define BITSIZE  8

using namespace std;

void toBinary(int nNum , int* nArr){

    int index=0;
    while(nNum>0){
        int nReminder=nNum%2;
        nNum/=2;
        nArr[BITSIZE-1-index]= nReminder;
        index++;
    }
}


void resetBit(const int& nPos , int* nArr){

    nArr[BITSIZE-1-nPos]=0;
}


int toDecimal(int nNum , int* nArr ){
    int nDecimal=0;
    for(int i=0 ; i < BITSIZE ; i++){
        nDecimal+=nArr[BITSIZE-1-i] * pow(2 , i);
    }
    return nDecimal;
}

void display(int* nArr){
    for (int i =0 ;i < BITSIZE ; i++){
        cout<< nArr[i] ;
    }
    cout<< endl;
}


int main(){

    int nNumber;
    int nPos;
    int nArr[BITSIZE]={0};

    cout<<"enter the a number: "<< endl;
    cin >> nNumber ;
    cout << "enter the nth bit you want to reset: " << endl;
    cin >> nPos;

    toBinary(nNumber , nArr);
    cout<< "before resetting the bit: ";
    display(nArr);

    resetBit(nPos , nArr);

    cout << "after resetting the "<<nPos<<"th bit: ";
    display(nArr);

    int nDecimal = toDecimal(nNumber , nArr);
    cout<< "decimal value after resetting "<< nPos << "th bit: ";
    cout << nDecimal ;
}