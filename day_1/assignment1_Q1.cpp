#include <iostream>
#include <math.h>


using namespace std;


int main(){


    
    cout<<"size of short: "<<sizeof(short)<<endl;
    cout<<"size of int: "<<sizeof(int)<<endl;
    cout<<"size of long: "<<sizeof(long)<<endl;
    cout<<"size of float: "<<sizeof(float)<<endl;
    cout<<"size of double: "<<sizeof(double)<<endl;
    cout<<"size of char: "<<sizeof(char)<<endl;
    cout<<"size of long long: "<<sizeof(long long)<<endl;
    cout<<"size of int*: "<<sizeof(int*)<<endl;
    cout<<"size of char*: "<<sizeof(char*)<<endl;
    cout<<"size of void*: "<<sizeof(void*)<<endl;
    cout<<"size of bool: "<<sizeof(bool)<<endl;

    short maxValue=pow(2,sizeof(short)*8-1)-1;
    cout<<"maximum value can be stored to short: "<<maxValue<<endl;

    short highValue=maxValue+1;
    cout<<"when greater than maximum value(32768) is stored to short: "<<highValue<<endl;




    return 0;
}
