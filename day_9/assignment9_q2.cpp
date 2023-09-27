#include <iostream>
#include <cctype>
using namespace std;
class CLetter
{
    public:
        virtual void display(char) = 0;
};
class CUpper_Case : public CLetter
{
    public:
        void display(char ch)
        {
        cout << "\nUpper Case is " << char(toupper(ch)) << endl;
        }
};
class CLower_Case : public CLetter
{
    public:
        void display(char ch)
        {
        cout << "\nLower Case is " << char(tolower(ch)) <<endl;
}
};
class CError : public CLetter
{
    public:
        void display(char ch){
        cout << "\nError" << endl;
        }
};
class CGetChar{
    CLetter* letter;
    public:
        void get()
        {
            char ch;
            CUpper_Case ucase;
            CLower_Case lcase;
            CError      ecase;
            cout << "\nEnter character to convert ";
            cin >> ch;
            if(islower(ch)){
                letter = &ucase;
                letter->display(ch);
            }
            else if(isupper(ch)){
                letter = &lcase;
                letter->display(ch);
            }
            else{
                letter = &ecase;
                letter->display(ch);
            }
        }
};
int main()
{
    CGetChar getObj;
    getObj.get();
    return 0;
}