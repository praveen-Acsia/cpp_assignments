#include <iostream>
#include <string>


using namespace std;

enum Boolean{
    False,
    True
};

class In_out{

private:
    char buffer[80];

public:
    Boolean read(){

        if (fgets(buffer, sizeof(buffer), stdin) == nullptr){

        return True;
        }

        return False;
    }

    void convert(){

        for (int i = 0; buffer[i] != '\0'; i++){

            if (islower(buffer[i])){

                buffer[i] = toupper(buffer[i]);
            }
            else if (isupper(buffer[i])){

                buffer[i] = tolower(buffer[i]);
            }
        }
    }

    void print(){

        cout << buffer;
    }
};

int main()
{

    In_out io;
    cout << endl << "Enter some data: ";

    while (!io.read()){

        io.convert();
        io.print();

        cout << endl << "Next data: ";
    }
    return 0;
}