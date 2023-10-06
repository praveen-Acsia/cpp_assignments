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
    std::cout << "\nCLoan constructor\n";
}
    
void CLoan::displayLoanDetails(){
    std::cout << "\n Type: " << type << " | Principle Amount: " << m_dPrinciple << " | Yearly Rate: " << m_dYearlyRate << " | "
        << " | Time: " << m_nLengthInYears << " | Monthly payment: " << m_dMontlyPayment << std::endl;
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



void CSimpleLoan::compute(){
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


class CBudget
{   
    std::string lType;
    protected:
        double m_dGrossIncome;
        CLoan* m_pLoan;
        CSimpleLoan *simple;
        CCompoundLoan *compound;
        double m_dNetIncome;
    public:
        CBudget(double, double, double, int, std::string);
        
        void display() { m_pLoan->displayLoanDetails(); }
        
        void doCompute();
        
        double getIncome() const { return m_dNetIncome; }
        
        /* ~CBudget(){
            delete m_pLoan;
        } */
        
};

CBudget::CBudget(double grossIncome, double principle, double rate, int years, std::string type)
{
    m_dGrossIncome = grossIncome;
    lType = type;
    if(type == "simple"){
        simple = new CSimpleLoan(principle, rate, years);
        m_pLoan = simple;
        std::cout << "\nSimple Created\n";
    }
    else{
        compound = new CCompoundLoan(principle, rate, years);
        m_pLoan = compound;
    }
    m_pLoan->compute();
    m_dNetIncome = m_dGrossIncome - m_pLoan->getPayment();
}

void CBudget::doCompute()
{
    
}


class CFinance
{
    double m_dIncome;
    CBudget* m_pBudget;
    //All function declarations
    public:
        CFinance(){}
        //~CFinance() { delete m_pBudget; }
        
        void getDetails();
        void viewDetails();
};

void CFinance::getDetails()
{
    std::string type;
    double principle, rate, grossIncome;
    int year;
    
    std::cout << "\nGross Income: ";
    std::cin >> grossIncome;
    std::cout << "\nType of loan?: ";
    std::cin >> type;
    std::cout << "\nPrinciple rate: ";
    std::cin >> principle;
    std::cout << "\nRate: ";
    std::cin >> rate;
    std::cout << "\nYear: ";
    std::cin >> year;

    m_pBudget = new CBudget(grossIncome, principle, rate, year, type);
    //m_pBudget->doCompute();
    std::cout << "\nCompute Done\n";
    m_dIncome = m_pBudget->getIncome();
}

void CFinance::viewDetails(){
    m_pBudget->display();
    std::cout << "\nIncome: " << m_dIncome << std::endl;
}

int main()
{
    CFinance* fin = new CFinance;
    fin->getDetails();
    fin->viewDetails();
}
