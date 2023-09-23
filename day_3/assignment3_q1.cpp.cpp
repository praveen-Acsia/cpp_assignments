#include<iostream>

using namespace std;

struct EMPLOYEE {
char chName[40];
int nEmpId;
char chGender;
double dBasicSalary;
};

void sortEmployee(struct EMPLOYEE E[],const int& size){
    for(int j =0; j < size; j++){
        for(int i = j; i < size-1; i++){
            if (E[i].nEmpId > E[i+1].nEmpId){
                struct EMPLOYEE temp;
                temp = E[i];
                E[i] = E[i+1];
                E[i+1]=temp;
            }
        }
    }
    cout << "sorted." << endl;
}

void displayEmpList(struct EMPLOYEE E[], const int& size, int nEmpid = -1){
    if (nEmpid>=0){
        cout << "employee name: "<< E[nEmpid].chName << endl;
        cout << "employee id: " << E[nEmpid].nEmpId << endl;
        cout << "employee gender: " << E[nEmpid].chGender << endl;
        cout << "employee basic salary" << E[nEmpid].dBasicSalary << endl;
        cout << endl << endl;
    }else{
        for(int i =0; i < size; i++){
            cout << "employee name: "<< E[i].chName << endl;
            cout << "employee id: " << E[i].nEmpId << endl;
            cout << "employee gender: " << E[i].chGender << endl;
            cout << "employee basic salary" << E[i].dBasicSalary << endl;
            cout << endl << endl;
        }
    }
}

void searchEmployee(struct EMPLOYEE E[],const int& size, const int& nSearchId ){
    int nFound=0;
    for (int i = 0; i < size; i++){
        if ( E[i].nEmpId == nSearchId){
            displayEmpList(E , size, i);
            nFound = 1;
            break;
        }
    }
    if( !nFound){
        cout << "Employee with such an id does not exist." << endl;
    }
}

int main()
{
    cout << "how many employee details you want to store? : " << endl;
    int nNoOfEmployee;
    cin >> nNoOfEmployee;
    struct EMPLOYEE E[nNoOfEmployee];
    
   
    
    for(int i = 0; i < nNoOfEmployee; i++){
        
        cout << "enter name of the employee: " << endl;
        cin >> E[i].chName;
        cout << "enter employee id: " << endl;
        cin >> E[i].nEmpId;
        cout << "enter employee gender: " << endl;
	    cin >> E[i].chGender;
    	cout << "enter employee basic salary: " << endl;
    	cin >> E[i].dBasicSalary;
    }
    
    while(true){
    
        int nOperation;
        cout << "enter 0, 1, 2, 3 to exit, sort,print list, search: "<< endl;
        cin >> nOperation;
        
        if (nOperation == 0)
            break;
        
        switch(nOperation){
            
            case 1: 
                sortEmployee(E, nNoOfEmployee);
                break;
                
            case 2:
                displayEmpList(E, nNoOfEmployee);
                break;
            
            case 3:
                cout << "enter employee id to search: " << endl;
                int nEmpSearchId;
                cin >> nEmpSearchId;
                searchEmployee(E, nNoOfEmployee, nEmpSearchId);
                break;
          
        }
    }

}
