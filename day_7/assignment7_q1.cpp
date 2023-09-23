#include <iostream>


using namespace std;


class CUserDate
{
    int m_nMonth;
    int m_nDay;
    static int day_table[];// = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
    CUserDate(int day, int month);
    
    bool validate(int day , int month);

    int AbsDay();
};


int CUserDate::day_table[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(){
    
    // int nMonth;
    // int nDay;
    
    // cout << "enter the month: " << endl;
    // cin >> nMonth;
    // cout << "enter the day: " << endl;
    // cin >> nDay;
    
    int count;
    
    CUserDate udDate_1(25, 1);
    count=udDate_1.AbsDay();
    cout << count << " days." << endl;
    
    CUserDate udDate_2(5, 8);
    count=udDate_2.AbsDay();
    cout << count << " days." << endl;
    
    CUserDate udDate_3(32, 8);
    // count=udDate_3.AbsDay();
    // cout << count << " days." << endl;
    
    CUserDate udDate_4(5, 14);
    // count=udDate_4.AbsDay();
    // cout << count << " days." << endl;
    
    CUserDate udDate_5(1, 1);
    count=udDate_5.AbsDay();
    cout << count << " days." << endl;
    
    
    
    
    
}

CUserDate::CUserDate( int day, int month){
    if(validate(day, month)){
        m_nMonth= month;
        m_nDay = day;
    }
    else {
        cout << "object creation failed." << endl;
    }
}
bool CUserDate::validate(int day, int month){
    
    if(month <= 12 && month >=1 && day >=1 && day < day_table[month-1]){
        return true;
    }
    return false;
}
int CUserDate::AbsDay(){
    
    int TtlDays=0;
    
    if(m_nMonth<=1){
        TtlDays += m_nDay;
        
        return TtlDays;
    }
    
    for(int i =0; i < m_nMonth-1; i++){
        TtlDays += day_table[i];
    }
    TtlDays += m_nDay;
    
    return TtlDays;
}