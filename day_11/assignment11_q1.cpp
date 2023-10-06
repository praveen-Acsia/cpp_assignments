#include <iostream>

template <typename T>
class CMyArray
{
    T* m_pArray = NULL;
    int m_nLength;
    void swap(T&, T&);
    
    public:
      
        CMyArray(int);
        ~CMyArray();
        void add(CMyArray<T>);
        void sortArray();
        void printArray();
};

template <typename T> CMyArray<T>::CMyArray(int value){
    m_nLength = value;

    m_pArray = new T[m_nLength];

    std::cout << "\nEnter elements: ";
    for (size_t i = 0; i < m_nLength; i++)
    {
        std::cin >> m_pArray[i];
    }
    

}

template <typename T> CMyArray<T>::~CMyArray(){
    delete[] m_pArray;
    m_pArray = NULL;
}

template <typename T> void CMyArray<T>::add(CMyArray<T> parameter){
    
    for (size_t i = 0; i < m_nLength; i++)
    {
        m_pArray[i] += parameter.m_pArray[i];
        std::cout << "\nAdd\n";
    }
    
}

template <typename T> void CMyArray<T>::swap(T& parameter1, T& parameter2){
    T temp;
    temp = parameter1;
    parameter1 = parameter2;
    parameter2 = temp;
}

template <typename T> void CMyArray<T>::sortArray(){
    
    for (size_t i = 0; i < m_nLength; i++)
    {
        for (size_t j = i + 1; j < m_nLength; j++)
        {
            if(m_pArray[i] > m_pArray[j])
                swap(m_pArray[i], m_pArray[j]);
        }
        
    }
    
}

template <typename T> void CMyArray<T>::printArray(){
    for (size_t i = 0; i < m_nLength; i++)
    {
        std::cout << m_pArray[i] << std::endl;
    }
    
}


class Student {
    int nRoll;
    double dTotalMarks;
    char m_chName[25];
    public:
   
    Student();
    void showStudent();
    friend std::ostream& operator << (std::ostream&, const Student& );
    friend std::istream& operator >> (std::istream&, Student& );
    bool operator>(Student);
    
};

Student::Student(){
    
}

bool Student::operator>(Student object){
    if(nRoll > object.nRoll)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& os, const Student& object){
    os << "\nName: " << object.m_chName;
    os << "\nRoll Number: " << object.nRoll;
    os << "\nTotal Marks: " << object.dTotalMarks << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Student& object){
    std::cout << "\nName: ";
    is >> object.m_chName;
    std::cout << "\nRoll Number: ";
    is >> object.nRoll;
    std::cout << "\nTotal Marks: ";
    is >> object.dTotalMarks;
    std::cout << std::endl;
    return is;
}


int main()
{
    CMyArray<int> intArrayObj(10);          
                                           
    CMyArray<double> doubleArrayObj(10);    
                                            
    CMyArray<Student> studArrayObj(5);      
                                            
    std::cout << "\nPrinting\n";
    intArrayObj.printArray();
    doubleArrayObj.printArray();
    studArrayObj.printArray();
    CMyArray<int> intArrayObj2(10);
    CMyArray<double> doubleArrayObj2(10);
    intArrayObj.add(intArrayObj2);
    doubleArrayObj.add(doubleArrayObj2);
    std::cout << "\nSorted\n";
    intArrayObj.sortArray();
    doubleArrayObj.sortArray();
    studArrayObj.sortArray();
    intArrayObj.printArray();
    doubleArrayObj.printArray();
    studArrayObj.printArray();
}
