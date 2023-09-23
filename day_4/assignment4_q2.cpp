#include<iostream>

using namespace std;


int main(){
    
    int nString;
    cout<< "enter no of string: "<< endl;
    cin >>nString;
    
    char* chArr[nString];
    for(int i=0; i<nString; i++){
        chArr[i]=new char(20);
    }
    
    for(int i =0; i<nString; i++){
        cout<< "enter name."<<endl;
        cin >> chArr[i];
    }
    cout<< "strings" <<"           "<< "counts"<<endl;
    
    for( int i=0; i< nString;i++){
        int nvovel=0;
        for(int j=0; chArr[i][j]!='\0';j++){
            
            if(chArr[i][j]=='a'||chArr[i][j]=='A'
            ||chArr[i][j]=='e'||chArr[i][j]=='E'
            ||chArr[i][j]=='i'||chArr[i][j]=='I'
            ||chArr[i][j]=='o'||chArr[i][j]=='O'
            ||chArr[i][j]=='u'||chArr[i][j]=='U'){
                nvovel+=1;
            }
        }
        cout<< chArr[i] << "           "<< nvovel<< endl;
    }
    
    
}