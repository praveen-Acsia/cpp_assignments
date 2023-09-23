#include<iostream>
#include<iomanip>

using namespace std;

class A_clock {
  
  int m_Hour;
  int m_Minute;
  int m_Second;
  
  public:
  
    void set(int nHour, int nMinute, int nSecond){
        m_Hour = nHour;
        m_Minute = nMinute;
        m_Second = nSecond;
    }
    
    void increment(){
        m_Second++;
        if(m_Second>59){
            m_Minute++;
            m_Second = 0;
        }
        if(m_Minute > 59){
            m_Hour++;
            m_Minute= 0;
        }
        if(m_Hour > 23){
            m_Hour= 0;
            
        }
    }
    
    void display(int nFormat =0){
        int nHour =m_Hour;
        int nMinute = m_Minute;
        int nSecond = m_Second;
        string sAnno = "";
        
        if(nFormat != 0 ){
            if(m_Hour==0){
                nHour=12;
            }
            if(m_Hour>12){
                nHour -= 12;
            }
            if(m_Hour > 11){
                sAnno = " PM";
            }
            else{
                sAnno = " AM";
            }
            
            
        }
        
        cout << setw(2) << nHour << setfill('0') << ":";
        cout << setw(2) << nMinute << setfill('0') << ":";
        cout << setw(2) << nSecond << setfill('0') << sAnno << endl;
    }
};


int main()
{
A_clock BigBen;
BigBen.set(23, 59, 00);
for(int I =0; I < 100; I++)
{
BigBen.increment();
BigBen.display();
BigBen.display(1);
}
return 0;
}