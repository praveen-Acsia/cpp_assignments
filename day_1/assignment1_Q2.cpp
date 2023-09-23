#include <iostream>
#include <cmath>
 

using namespace std;


int main()

{

int firstNumber;
char choice;
int secondNumber;

cout<<"enter first number: "<<endl;
cin>>firstNumber;
cout<<"enter the operator: "<<endl;
cin>>choice;
cout<<"enter second number: "<<endl;
cin>>secondNumber;

switch(choice)

{

case '+': cout<<firstNumber+secondNumber;

          break;

case '-': cout<<firstNumber-secondNumber;

          break;

case '*': cout<<firstNumber*secondNumber;

          break;

case '/': cout<<firstNumber/secondNumber;

          break;

case '%': cout<<firstNumber%secondNumber;

          break;

}

return 0;

}

