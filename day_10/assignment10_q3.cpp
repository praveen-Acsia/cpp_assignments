#include <iostream>
#include <string.h>

class CEmployee{
    char* m_nName;
    long m_nSecurityNumber;

    public:

        CEmployee(){};
        void getData(char[], long);
        bool operator>(CEmployee);
        
        void print();
        
        friend std::ostream& operator<<(std::ostream& os, CEmployee& obj){
            obj.print();

            return os;
        }
};

void CEmployee::getData(char name[], long secNumber){
    m_nName = new char[20];
    strcpy(m_nName, name);
    m_nSecurityNumber = secNumber;
}



bool CEmployee::operator>(CEmployee obj){
    if(m_nName[0] < obj.m_nName[0])
        return true;
    else
        return false;
}

void CEmployee::print(){
    std::cout << "\nName: " << m_nName << " | Social Security Number: " << m_nSecurityNumber;
}


template <typename T> 
void swap(T& parameter1, T& parameter2){
    T temp;
    temp = parameter1;
    parameter1 = parameter2;
    parameter2 = temp;
}


template <typename T>
void sortData(T data[], int size){
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if(data[i] > data[j])
                swap(data[i], data[j]);
        }
        
    }
    std::cout << "\nSorted\n";
}

template <typename T>
void displayData(T* data, int size){
    for(int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

int main(){
    int* value;
    CEmployee* emp;

    int n, e;
    
    std::cout << "\nIntegers: ";
    std::cin >> n;

    value = new int[n];
    std::cout << "\nEnter values: " << std::endl;
    
    for(int i = 0; i < n; i++)
        std::cin >> value[i];
    
    std::cout << "\nAfter sorting: ";
    sortData(value, n);
    displayData(value, n);

    std::cout << "\nEmployees: ";
    std::cin >> e;

    emp = new CEmployee[e];

    std::cout << "\nEnter employees: " << std::endl;
    
    char name[20];
    int number;
    
    for(int i = 0; i < e; i++){
        std::cout << "\nName: ";
        std::cin >> name;
        std::cout << "\nNumber: ";
        std::cin >> number;
        emp[i].getData(name, number);
    }

    std::cout << "\nAfter sorting: ";
    sortData(emp, e);
    displayData(emp, e);

    delete[] emp;
    delete[] value;

    return 0;
}
