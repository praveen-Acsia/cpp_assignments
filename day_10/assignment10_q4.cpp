#include <iostream>
using namespace std;

struct student {
    
    char name[20];
    int mark;
    bool operator==(int value) {
        if(mark == value)
            return true;
        else
            return false;
    }
};

struct person {

    char name[20];
    int age;
    bool operator==(int value) {
        if(age == value)
            return true;
        else
            return false;
    }
};

template <typename T>
int count(T* data[], int size, int value) {
    int c = 0;
    for(int i = 0; i < size; i++){
        if(*(*data + i) == value)
            c++;
    }
    return c;
}


int main() {

    int* array;
    student* stud;
    person* per;

    int n, value;

    cin >> n;
    array = new int[n];

    cout << "\nIntergers: ";
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << "\nEnter a value: ";
    cin >> value;

    cout << "\nCount is: " << count(&array, n, value) << std::endl;

    cin >> n;
    stud = new student[n];

    cout << "\nStudents: ";
    for(int i = 0; i < n; i++){
        cin >> stud[i].name;
        cin >> stud[i].mark;
    }
    cout << "\nEnter a value: ";
    cin >> value;

    cout << "\nCount is: " << count(&stud, n, value) << endl;

    cin >> n;
    per = new person[n];

    cout << "\nStudents: ";
    for(int i = 0; i < n; i++){
        cin >> per[i].name;
        cin >> per[i].age;
    }
    cout << "\nEnter a value: ";
    cin >> value;

    cout << "\nCount is: " << count(&per, n, value) << endl;

    return 0;
}
