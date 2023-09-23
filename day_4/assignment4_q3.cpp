#include<iostream>
#include<string>

using namespace std;

void swapfn(char* pFirst, char* pSecond){
    char *temp;
    temp = new char[10];
    strcpy(temp,pFirst);
    strcpy(pFirst,pSecond);
    strcpy(pSecond,temp);
    
    delete[] temp;
}

int main(){
    
    char* pFirst;
    pFirst=new char[10];
    cin>>pFirst;
    char* pSecond;
    pSecond=new char[10];
    cin>>pSecond;
    
    cout<< "before swaping : "<< endl;
    cout<<" pFirst = "<< pFirst<< endl;
    cout<< "pSecond = "<< pSecond<<endl;
    
    swapfn(pFirst,pSecond);
    
    cout<< "after swaping : "<< endl;
    cout<<" pFirst = "<< pFirst<< endl;
    cout<< "pSecond = "<< pSecond<<endl;
    
    delete[] pFirst;
    delete[] pSecond;
    
}