//Question3

#include <iostream>
#include <string.h>

class CEmployee{
    protected:
    char* m_nName;
    long m_nSecurityNumber;

    public:

        CEmployee(){};
        CEmployee(char[], long);
        ~CEmployee();

        long getSec() { return m_nSecurityNumber; }        

        virtual void print() = 0;
};

CEmployee::CEmployee(char name[], long secNumber){
    m_nName = new char[20];
    strcpy(m_nName, name);
    m_nSecurityNumber = secNumber;
}

CEmployee::~CEmployee(){
    delete[] m_nName;
}

void CEmployee::print(){
    std::cout << "\nName: " << m_nName << " | Social Security Number: " << m_nSecurityNumber;
}

class Hourly_Employee : virtual public CEmployee{
    float m_fRate;
    int m_nhours;

    public:
        Hourly_Employee(char[], long, float, int);
        void print(){
            std::cout << "\nName: " << m_nName << " | Social Security Number: " << m_nSecurityNumber;
            std::cout << "\nRate: " << m_fRate << " | Hours: " << m_nhours << std::endl;    
        }
};

Hourly_Employee::Hourly_Employee(char name[20], long secNumber, float r, int h) : CEmployee(name, secNumber){
    m_fRate = r;
    m_nhours = h;
}

class Salaried_Employee : virtual public CEmployee{
    float m_fSalary;

    public:
        Salaried_Employee(char[], long, float);
        void print(){
            std::cout << "\nName: " << m_nName << " | Social Security Number: " << m_nSecurityNumber;
            std::cout << "\nSalary: " << m_fSalary << std::endl;    
        }
};

Salaried_Employee::Salaried_Employee(char name[], long secNumber, float salary) : CEmployee(name, secNumber){
    m_fSalary = salary;
}

class CRoaster{
    CEmployee* emp;
    Salaried_Employee* sEmp;
    Hourly_Employee* hEmp;

    public:
        CRoaster(){};

        long getSec() { return emp->getSec(); }

        CRoaster(std::string type){
            char name[20]; 
            long sec; 
            float salary;
            int hour; float rate; 

            std::cout << "\nName: ";
            std::cin >> name;
            std::cout << "\nSecurity Number: ";
            std::cin >> sec;

            if(type == "salaried"){
                std::cout << "\nSalary: ";
                std::cin >> salary;

                sEmp = new Salaried_Employee(name, sec, salary);
                emp = sEmp;
            }
            else{
                std::cout << "\nRate: ";
                std::cin >> rate;
                std::cout << "\nHour: ";
                std::cin >> hour;

                hEmp = new Hourly_Employee(name, sec, rate, hour);
                emp = hEmp;
            }
        }

        void display(){
            emp->print();
        }
};

CRoaster** delEmployee(CRoaster** emp, int& size, long sec){
    std::string type;
    
    CRoaster** temp;
    temp = new CRoaster*[size - 1];


    int j = 0;

    for(int i = 0; i < size; i++){
        if(emp[i]->getSec() == sec)
            continue;
        temp[j++] = emp[i];
    }
    
    size = size - 1;

    return temp;
}

CRoaster** addEmployee(CRoaster** emp, int& size){
    std::string type;
    
    
    
    CRoaster** temp;
    temp = new CRoaster*[size + 1];

    std::cout << "\nType: ";
    std::cin >> type;

    for(int i = 0; i < size; i++){
        temp[i] = emp[i];
    }
    temp[size] = new CRoaster(type);
    size = size + 1;

    return temp;
}

int main(){

    CRoaster** emp;

    int n;
    std::string type;

    std::cin >> n;

    emp = new CRoaster*[n];

    for (size_t i = 0; i < n; i++)
    {   
        std::cout << "\nType: ";
        std::cin >> type;

        emp[i] = new CRoaster(type);
    }

    std::cout << "\nAdd employee: ";
    emp = addEmployee(emp, n);

    std::cout << "\nEmployee Added " << std::endl;

    for (size_t i = 0; i < n; i++)
    {
        emp[i]->display();
    }
    
    int sec;
    std::cout << "\nDel employee: ";
    std::cin >> sec;
    emp = delEmployee(emp, n, sec);

    std::cout << "\nEmployee Deleted " << std::endl;

    for (size_t i = 0; i < n; i++)
    {
        emp[i]->display();
    }

    return 0;
}
