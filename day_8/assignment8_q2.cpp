#include <iostream>
#include <cstring>

using namespace std;

class CEmployee
{
private:
    const int m_nId;
    char* m_pchName;
public:
    CEmployee(int , char[]) ;
    ~CEmployee();
    void displayPerson();
    char* getname();
};


class Company
{
    CEmployee m_emp;
    static int m_ncount;
public:
    Company(int , char[]) ;
    ~Company();
    void displayEmployees();
    void sortEmployees();
};


CEmployee::CEmployee(int id=0, char name[]=NULL) : m_nId(id), m_pchName(new char[10]){
    strcpy(m_pchName, name);
}
void CEmployee::displayPerson(){
    cout <<"\nId : " << m_nId << "\nName : " << m_pchName << endl;
}
CEmployee::~CEmployee(){
    delete[] m_pchName;
}
char* CEmployee::getname(){
    return m_pchName;
}



Company::Company(int id=0, char name[]= NULL): m_emp(id, name){
}
void Company::displayEmployees(){
    m_emp.displayPerson();
}
Company::~Company(){
    cout << "company destructor.\n";
}
void Company::sortEmployee(){

    for(int i = 0; i < m_nCount; i++){
        for(int j =0 ; j < i; j++){
            if(m_emp.getname()[i] > m_emp.getname())
        }
    }
}


int Company::m_nCount;


int main()
{
    int id;
    char name[10];
    //Read nCount no: of employees
    cout << "\nEnter no of employees : ";
    cin >> m_nCount;

    //Create company which has nCount of employees.
    Company* pCompany[m_nCount];


    //Read details of employees in Company
    for(int i =0; i < nCount; i++){
        cout << "\nEnter employee id : ";
        cin >> id;
        cout << "\nEnter employee name : ";
        cin >> name;
        pCompany[i]=new Company(id, name);
    }
    //Sort employees in Company
    // pCompany.sortEmployee();

    //Print employees in Company
    for(int i =0; i < m_nCount; i++){
        pCompany[i]->displayEmployees();
    }
}