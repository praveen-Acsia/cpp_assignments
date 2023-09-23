#include <iostream>
#include <iomanip>

using namespace std;

int days_Array[] = {31, 28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


class Date{
    int m_Day=0;
    int m_Month =0;
    int m_Year =0;
    
    public:
    
    void set(int day, int month, int year){
        m_Day= day;
        m_Month = month;
        m_Year = year; 
    }
    
    void display(){
        
        cout << setw(2)<<setfill('0')<<m_Day<<'/';
        cout<< setw(2)<<setfill('0')<<m_Month<< '/';
        cout<< setw(4)<<setfill('0')<<m_Year <<endl;
    }
    
    void incrment(){
        
        m_Day++;
        if(m_Day>days_Array[m_Month-1]){
            m_Month += 1;
            m_Day =1;
        }
        if(m_Month > sizeof(days_Array)/sizeof(days_Array[0])){
            m_Month=1;
            m_Day=1;
            m_Year+=1;
            
        }
    }
};

int main()
{
    Date today;
    today.set(01, 01,1993);
    for(int i = 0; i<400; i++){
        
        today.incrment();
        today.display();
    }
return 0;
}
