#include <iostream>
#include <string.h>

using namespace std;

class CEmployee
{
    private:
        int m_nId;
        char* m_pchName;
    public:
        CEmployee(int nId, char* pchName);
        ~CEmployee();
        void displayPerson();


        bool operator<(CEmployee obj){
            if(m_pchName[0] < obj.m_pchName[0])
                return true;
            else
                return false;
        }
};

CEmployee::CEmployee(int nId, char* pchName) : m_nId(nId){
    m_pchName = new char[10];
    strcpy(m_pchName, pchName);
}

CEmployee::~CEmployee(){
    delete[] m_pchName;
}

void CEmployee::displayPerson(){
    std::cout << "\nName: " << m_pchName << "\tID: " << m_nId;
}


class Company
{
    CEmployee* m_emp[100];
    int nCount;
    
    public:
        Company(int);
        ~Company(){};
        void swapName(Company, Company);
        void sort();
        void displayEmployees();
};

Company::Company(int n){
    nCount = n;

    char name[10];
    int Id;

    

    for(int i = 0; i < nCount; i++){
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "\nId: ";
        std::cin >> Id;

        m_emp[i] = new CEmployee(Id, name);
    }

}



void Company::sort(){
    CEmployee* temp = new CEmployee(0, "xxx");
    for (size_t i = 0; i < nCount; i++)
    {
        for (size_t j = i + 1; j < nCount; j++)
        {
            if(m_emp[i] < m_emp[j]){
                temp = m_emp[i];
                m_emp[i] = m_emp[j];
                m_emp[j] = temp;
            }
        }
        
    }
}

void Company::displayEmployees(){
    for (size_t i = 0; i < nCount; i++)
    {
        m_emp[i]->displayPerson();
    }
    
}


int main()
{
    int nCount;
    std::cin >> nCount;

    Company* pCompany = new Company(nCount);
    pCompany->sort();
    pCompany->displayEmployees();
}
