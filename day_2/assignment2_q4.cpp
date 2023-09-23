
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>


using namespace std;

void concat(char String_1[],int LenString_1, char String_2[],int LenString_2){
    
    int nLenResult=LenString_2+LenString_1;
    int nIndex=0;
    
    for(int i=LenString_1 ; i<nLenResult; i++){
        String_1[i]=String_2[nIndex];
        nIndex++;
    }
}


int len(char cString[]){
    int a =0;
    for (int i =0 ;i< 20 ; i++){
        a++;
        if(cString[i]==NULL)
            break;
    }
    return a-1;
}


int main(){
    char cString_1[20] = "cpp is ";
    char cString_2[20] = "fun to learn.";
    int nLenString_1=len(cString_1);
    int nLenString_2= len(cString_2);
    
    concat(cString_1,nLenString_1,cString_2,nLenString_2);
    
    cout<<cString_1;

}

