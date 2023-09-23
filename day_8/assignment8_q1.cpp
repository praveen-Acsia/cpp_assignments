#include <iostream>
#include <string.h>
using namespace std;

class CDriver{
    
    char* m_pName;
    int m_nAge;
    
public:
    
    CDriver(char[] , int);
    CDriver(const CDriver& );
    void print();
    ~CDriver();
};



class CAutomobile{

    CDriver driver;
    char* m_pMake;
    int m_nYear;

public:
    CAutomobile(char[], int, char[], int);
    void print();
    ~CAutomobile();

};



CDriver::CDriver(char name[]=NULL, int age= 0) : m_pName(new char[10]), m_nAge(age) {
    strcpy(m_pName, name);
}

CDriver::CDriver(const CDriver& driver) 
{    
    CDriver result;
    result.m_pName = driver.m_pName;
    result.m_nAge = driver.m_nAge;
}

void CDriver::print()
{
    cout << "Driver name: " << m_pName << "\nDriver age: " << m_nAge << endl;
}

CDriver::~CDriver()
{
    
    delete[] m_pName;
}



CAutomobile::CAutomobile(char make[]= NULL , int year= 0, char name[]=NULL, int age= 0)
    : m_pMake(new char[10]), m_nYear(year), driver(name, age){

        strcpy(m_pMake, make);
    }

void CAutomobile::print(){

    driver.print();
    cout << "Make : " << m_pMake << "\nYear : " << m_nYear << endl;
}

CAutomobile::~CAutomobile(){
    delete[] m_pMake;
}


int main()
{
    char name[10], make[10];
    int age, year; 
    
    cout << "\nEnter driver name : ";
    cin >> name;
    cout << "\nEnter driver age : ";
    cin >> age;
    cout << "\nEnter make of the automobile : ";
    cin >> make;
    cout << "\nEnter year of manufacture : ";
    cin >> year; 

    CDriver cdDriver(name , age);
    CAutomobile caAutomobile(make, year, name, age);

    caAutomobile.print();
    return 0;
}

