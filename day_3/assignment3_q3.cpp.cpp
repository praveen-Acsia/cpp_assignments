#include<iostream>

using namespace std;

void sortArray(int* nPtr , const int& size){
    
    for(int i = 0; i <size; i++){
        for(int j = size-1; j >0; j--){
            if(nPtr[j] > nPtr[j-1]){
                int temp;
                temp = nPtr[j];
                nPtr[j] = nPtr[j-1];
                nPtr[j-1] = temp;
                
            }
        }
    }
}

int main(){
    
    
    int* nPtr;
    int n;
    cout << "enter length of array." << endl;
    cin >> n;
    
    nPtr = new int(n);
    
    for(int i =0; i < n; i++){
        cout << "enter element."<< endl;
        int element;
        cin >> element;
        
        nPtr[i]=element;
    }
    
    sortArray( nPtr , n);
    
    for(int i =0 ; i<n;i++)
        cout << nPtr[i] << endl;
    
    delete[] nPtr;
    nPtr = NULL;
    
}