#include <iostream>


using namespace std;
 

int nFactorial(int number){

    int factorial=1;

    for(int i=1;i<=number;i++){

        factorial=factorial*i;

    }

    return factorial;

}

int main(){

   int number;
   
   cout<<"enter the number: "<<endl;
   cin>>number;

   int sum=0;

   for(int j=1;j<=number;j++)
     {

       sum= sum + nFactorial(j);

     }

     cout<<"Sum of factorials of first " <<number<<" numbers are: "<<sum;

   return 0;

}
