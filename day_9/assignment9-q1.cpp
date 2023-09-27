#include <iostream>
#include <cstring>
using namespace std;
class CEmployee {
protected:
char* name;
long ssn;

public:
CEmployee(const char* empName, long empSSN) {
name = new char[strlen(empName) + 1];
strcpy(name, empName);
ssn = empSSN;
}

virtual ~CEmployee() {
delete[] name;
}

void print() {
cout << "Name " << name << endl<<"SSN " << ssn << endl;
}
};

class CPerson : public CEmployee {
public:
CPerson(const char* empName, long empSSN) : CEmployee(empName, empSSN) {}
};

class HourlyEmployee : public CPerson {
private:
double rate;
int hours;

public:
HourlyEmployee(const char* empName, long empSSN, double empRate, int empHours)
: CPerson(empName, empSSN), rate(empRate), hours(empHours) {}

void print() {
CEmployee::print();
cout << "Rate in Rs" << rate <<endl<< "Hours " << hours << endl;
}
};

class SalariedEmployee : public CPerson {
private:
double salary;

public:
SalariedEmployee(const char* empName, long empSSN, double empSalary)
: CPerson(empName, empSSN), salary(empSalary) {}

void print() {
CEmployee::print();
cout << "Salary in Rs" << salary << endl;
}
};

int main() {
char name[100];
long ssn;
double rate, salary;
int hours;

cout << "Enter the name ";
cin.getline(name, 100);
cout << "Enter the SSN ";
cin >> ssn;

cout << "Enter hourly rate ";
cin >> rate;
cout << "Enter hours worked ";
cin >> hours;

HourlyEmployee hourly(name, ssn, rate, hours);

cout << "Enter yearly salary ";
cin >> salary;

SalariedEmployee salaried(name, ssn, salary);

cout << "Employee details :" << endl;
hourly.print();
salaried.print();

return 0;
}