#include<iostream>
#include<iomanip>

using namespace std;

class CComplex{
    
    float m_real, m_imag; 
    
    public:
    
    CComplex(float real=0.0, float imag =0.0);
    
    CComplex(const CComplex&);
    
    float get_Real() const;
    
    float get_Imag() const;
    
    // void increment();
    
    void accumulate(const CComplex&);
    
    void print();
};

CComplex add(CComplex comp1, CComplex comp2){
    
    float real= comp1.get_Real() + comp2.get_Real();
    float imag= comp1.get_Imag() + comp2.get_Imag();
    
    CComplex result(real, imag);
    return result;
}

CComplex multiply(CComplex comp1, CComplex comp2){
    
    float real= (comp1.get_Real() * comp2.get_Real()) - (comp1.get_Imag() * comp2.get_Imag());
    float imag= (comp1.get_Real() * comp2.get_Imag()) + (comp1.get_Imag() * comp2.get_Real());
    CComplex result(real, imag);
    
    return result;
}


int main(){
    
    CComplex c1, c2(1.1), c3(2.2, 3.3);
    c1 = add(c2, c3);
    
    // c1.increment();
    CComplex c4(c1);
    CComplex c5 = add(c4, c3);
    c5.accumulate(c1);
    CComplex c6 = multiply(c4, c5);
    
    c1.print();
    c2.print();
    c3.print();
    c4.print();
    c5.print();
    c6.print();
}


CComplex::CComplex(float real, float imag){
    m_real= real;
    m_imag= imag;
}

CComplex::CComplex(const CComplex& comp){
    
    m_real= comp.get_Real();
    m_imag= comp.get_Imag();
}

float CComplex::get_Imag() const { 
    return m_imag; 
    
}

float CComplex::get_Real() const { 
    return m_real; 
    
}

void CComplex::accumulate(const CComplex& comp){
    
    m_real+= comp.get_Real();
    m_imag+= comp.get_Imag();
}

void CComplex::print(){
    char sign = '+';
    if(m_imag < 0.0){
        sign=' ';
    }
    cout << m_real << sign << m_imag << "i" << endl;
}






