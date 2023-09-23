#include <iostream> 

using namespace std;

struct date_time {
    int nDay;
    int nMonth;
    int nYear;
    struct time {
        int nHours;
        int nMinutes;
        int nSeconds;
    }dtNow;
};

void incSecond(struct date_time& dtToday){
    
    dtToday.dtNow.nSeconds++;
    if (dtToday.dtNow.nSeconds>=60){
        dtToday.dtNow.nSeconds=0;
        dtToday.dtNow.nMinutes+=1;
    }
    if (dtToday.dtNow.nMinutes>=60){
        dtToday.dtNow.nMinutes=0;
        dtToday.dtNow.nHours+=1;
    }
}


int main(){
    
    struct date_time dtToday;

    cout << "enter day: " << endl;
    cin >> dtToday.nDay;
    cout << "enter month: " << endl;
    cin >> dtToday.nMonth;
    cout << "enter year: " << endl;
    cin >> dtToday.nYear;
    cout << "enter hours: " << endl;
    cin >> dtToday.dtNow.nHours;
    cout << "enter minutes: " << endl;
    cin >> dtToday.dtNow.nMinutes;
    cout << "enter second: " << endl;
    cin >> dtToday.dtNow.nSeconds;
    
    cout << "how many times do you want to increase second?: " << endl;
    int nTimes;
    cin >> nTimes;
    
    for(int i = 0; i < nTimes; i++)
        incSecond(dtToday);
        
    cout << "day: " << dtToday.nDay << endl;
    cout << "month: " << dtToday.nMonth << endl;
    cout << "year: " << dtToday.nYear << endl;
    cout << "hours: " << dtToday.dtNow.nHours << endl;
    cout << "minutes: " << dtToday.dtNow.nMinutes << endl;
    cout << "second: " << dtToday.dtNow.nSeconds << endl;
    
    
    
    
}