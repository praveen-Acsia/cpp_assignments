#include<iostream>

using namespace std;


int main(){
    
    char chA[10]="cpp";
    char chB[10]=" is fun";
    
    char* chR=new char[20];
    
    int index=0;
    for( int i =0; chA[i]!='\0'; i++){
        chR[i] = chA[i];
        index++;
    }
    for(int i =0 ; chB[i]!='\0'; i++){
        chR[index]=chB[i];
        index++;
    }
    
    cout<< chR;
    
    delete[] chR;
    chR=NULL;


    
    
}