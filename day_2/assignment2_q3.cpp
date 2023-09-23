
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

int main()
{
    int nTerms;
    cout << "how many terms of fibinocci series you want to print? : " <<endl;
    cin>>nTerms;
    
    int nPrevious=0;
    int nCurrent=1;
    
    if(nTerms==1){
        cout << 0 << endl;
    }
    else if(nTerms==2){
        cout << 0 << endl;
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
        cout << 1 << endl;
        for(int i =0 ; i<nTerms-2 ; i++){
            
            int nTemp = nPrevious;
            nPrevious = nCurrent;
            nCurrent += nTemp;
            cout<< nCurrent << endl;
        }
    }
}