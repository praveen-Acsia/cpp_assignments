#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int nMaxNumber=500;
    
    for(int i=1 ; i<=nMaxNumber ; i++){
        
        int nSumOfCube=0;
        int nNumber=i;

        while(nNumber>0){
            int nDigit=nNumber%10;
            nNumber/=10;
            nSumOfCube+=pow(nDigit,3);
        }
        if (nSumOfCube==i)
            cout<<i<<endl;
    }
}
