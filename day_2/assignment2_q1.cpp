#include <iostream>


using namespace std;


int main(){



    // i)
    
    int nLines1 = 0;

    while(true){
        
        cout << "**********" << endl;
        nLines1++;

        if(nLines1 >=4)
            break;
    }
    cout<<endl<<endl;


    
    // ii)
    
    int nAsterisk = 5;
    int nLine2 = 1;
    bool bCondition=true;
    
    do{
        
        for(int i=0; i<nLine2 ;i++){
            cout << "*";
            if (i== nAsterisk-1){
                bCondition=false;
                break;
            }
        }
        nLine2++;
        cout << endl;
    }
    while(bCondition);
    cout<<endl<<endl;
    
    

     // iii)
     
     
    int nLines3=5 ;
    int nLastrow = 2*nLines3-1;
    int nSpace=nLastrow-nLines3;
    nAsterisk=1;
    
    for(int i =0 ;i<nLines3 ; i++){
        for(int j=nSpace ;j>0;j--){
            cout<<" ";
        }
        nSpace--;
        for(int k =0; k<nAsterisk;k++){
            cout<< "*";
        }
        nAsterisk+=2;
        cout<<endl;
    }
    
}


   
    
    