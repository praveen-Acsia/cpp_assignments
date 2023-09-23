#include<iostream>
#include<cstring>

using namespace std;

class CIntArray 
{
  
    int *m_ptr;
    int m_nLength;
    
    void realloc (int nNewLen){
        
        int* temp = new int[nNewLen];
        for(int i =0;i < min(m_nLength, nNewLen); i++){
            temp[i]= m_ptr[i];
        }
        delete[] m_ptr;
        m_ptr=temp;
        
    }
    
    public: 
    
    void initiaize(int nLength){
        
        m_nLength = nLength;
        m_ptr=new int[m_nLength];
        memset(m_ptr, 0, sizeof(m_ptr));
        
    }
        
    int get_length(){ return m_nLength; }
    
    
    void print(){
        cout << "index" <<'\t' << "elements" << endl;
        for(int i =0; i < m_nLength; i++){
            cout << i << '\t' << m_ptr[i] << endl;
        }
        
    }
    
    void store(int nIdx, int nVal){
        m_ptr[nIdx]=nVal;
        
    }
    
    void increment(){
        for(int i= 0; i<m_nLength; i++){
            m_ptr[i]++;
        }
        
    }
    
    void append(int nVal){
        
        realloc(m_nLength+1);
        m_ptr[m_nLength]= nVal;
        m_nLength++;
        
    }
    
    void revers(){
        for(int i =0; i< m_nLength/2; i++){
            int temp= m_ptr[i];
            m_ptr[i]=m_ptr[m_nLength-1-i];
            m_ptr[m_nLength-1-i]= temp;
        }
    }
    
    void trunc(){
        
        realloc(m_nLength-1)  ; 
        m_nLength--;
    }
    
    void del(){
        
        delete[] m_ptr;
        m_ptr= NULL;
    }

};

int main () {
 
    const int dim = 5;
    CIntArray a;
    a.initiaize (dim);
    a.print ();
      
    for (int i = 0; i < a.get_length (); i++){
          
        a.store (i, i);
    } 
    
    a.print ();
    a.increment ();
    a.append (6);
    a.print ();
    a.revers ();
    a.print ();
    a.trunc ();
    a.print ();
    a.del();
      
    return 0;

}
