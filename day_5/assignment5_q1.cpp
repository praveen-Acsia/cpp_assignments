#include <iostream>

using namespace std;

class A_clock{
    
    int m_Hour = 0;
    int m_Minute = 0;
    int m_Second = 0;
    
    public:
    
    void set(int nHour, int nMinute, int nSecond){
        
        m_Hour = nHour;
        m_Minute = nMinute;
        m_Second = nSecond;
    }
    void display(){
        
        cout << "time : "<< m_Hour<< " : "<< m_Minute<< " : "<< m_Second << endl;
        
    }
    
    void increment(){
    m_Second++;
    if (m_Second>=60){
        m_Second=0;
        m_Minute+=1;
    }
    if (m_Minute>=60){
        m_Minute=0;
        m_Hour+=1;
    }
    if(m_Hour >= 24 ){
        m_Hour=0;
        m_Minute = 0;
        m_Second = 0;
        
    }
    }
};

int main()
{
    A_clock BigBen;
    
    BigBen.set(23, 59, 00);
    
    for(int I =0; I < 100; I++){
        
    BigBen.increment();
    BigBen.display();
    }
    
    return 0;
}
