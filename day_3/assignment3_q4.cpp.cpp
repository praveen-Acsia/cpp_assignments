#include <iostream>

using namespace std;


int main(){
    
    int nArr[3][2];
    cout<< "enter elements.: "<< endl;
    
    for(int row =0; row < 3; row ++){
        for(int col =0; col < 2; col++ ){
            
            int ele;
            cout <<" ";
            cin >> ele;
            nArr[row][col] = ele;
        }
    }
    
    //print array
    
    for(int row= 0; row < 3; row++){
        cout << endl;
        for(int col = 0; col < 2; col++){
            cout << nArr[row][col] <<" ";
        }
    }
    
    //creating array
    int* transpose[2];
    for(int i=0;i<2;i++)
       transpose[i] = new int [3];
    
    
    //transpose of nArr
    for(int row= 0; row < 2; row++){
        for(int col =0; col < 3; col++){
            transpose[row][col] = nArr[col][row];
        }
    }
    
    //print transpose
    cout << endl;
    for(int row= 0; row < 2; row++){
        cout << endl;
        for(int col = 0; col < 3; col++){
            cout << transpose[row][col] <<" ";
        }
    }

    for(int i = 0; i < 3; i++){
        delete[] transpose[i];
        transpose[i]=NULL;
    }
}