#include <iostream>
#include <string.h>
#include <math.h>

class CLoan
{
    protected:
        double m_dPrinciple;
        double m_dYearlyRate;
        int m_nLengthInYears;
        double m_dMontlyPayment; 
        char* type;

    public:
        CLoan(double, double, int, const char*);
        virtual ~CLoan();
        virtual void compute() = 0;
        double getPayment() const { return m_dMontlyPayment; }
        void displayLoanDetails();
};

CLoan::CLoan(double principle = 0, double yearlyRate = 0, int lenYears = 0, const char* ty = "xxx"){
    type = new char[20];
    strcpy(type, ty);

    m_dPrinciple = principle;
    m_dYearlyRate = yearlyRate;
    m_nLengthInYears = lenYears;
}

void CLoan::displayLoanDetails(){
    std::cout << "\n Type: " << type << " \n Principle Amount: " << m_dPrinciple << "  Yearly Rate: " << m_dYearlyRate << "  "
        << "  Time: " << m_nLengthInYears << "  Monthly payment: " << m_dMontlyPayment << std::endl;
}

CLoan::~CLoan(){
    delete[] type;
}

class CSimpleLoan : public CLoan
{   
    public:
        CSimpleLoan(double, double, int);
        ~CSimpleLoan(){};
        void compute(); 
};

CSimpleLoan::CSimpleLoan(double principle, double rate, int years)
{
    type = new char[20];
    strcpy(type, "Simple Interest");

    m_dPrinciple = principle; 
    m_dYearlyRate = rate;
    m_nLengthInYears = years;
}



void CSimpleLoan::compute()
{
    m_dMontlyPayment = (m_dPrinciple * (m_dYearlyRate * m_nLengthInYears + 1)) / (m_nLengthInYears * 12);
}


class CCompoundLoan : public CLoan
{
    public:
        CCompoundLoan(double, double, int);
        ~CCompoundLoan(){};
        void compute();
};


CCompoundLoan::CCompoundLoan(double principle, double rate, int years) 
{
    type = new char[20];
    strcpy(type, "Compound Interest");

    m_dPrinciple = principle; 
    m_dYearlyRate = rate;
    m_nLengthInYears = years;
}


void CCompoundLoan::compute()
{
    m_dMontlyPayment = (m_dPrinciple * m_dYearlyRate * pow((1 + m_dYearlyRate), m_nLengthInYears)) / (pow((1 + m_dYearlyRate), m_nLengthInYears) - 1);
}

int main()
{
    CLoan* loan;
    CSimpleLoan sloan(500000, 2, 3);

    loan = &sloan;
    loan->compute();
    loan->displayLoanDetails();

    CCompoundLoan cloan(100000, 2.5, 4);

    loan = &cloan;
    loan->compute();
    loan->displayLoanDetails();
    
}
