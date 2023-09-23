#include <iostream>
#include <string.h>

using namespace std;
class CCoin 
{
    
	int m_nDenom; //1 or 5 or 10 or 25 
	long m_nCount;   //Count of occurances of coin type 
	const char* m_pSingle; //Text for 1 occurance Eg: penny if m_nDenom is 1 
	const char* m_pMultiple; //Text for multiple occuarnaces Eg: pennies if m_nDenom is 1 

	public: 

	CCoin(const int& m_nDemon);

	void change(double& dAmount);

	void print();
 
};


int main() 
{

	CCoin* pCoin[4]; 
	double dAmount;  
	
	pCoin[0] = new CCoin(25);// 25 is the value with which denomination needs  
	//to be set. In this case m_pSingle will be 
	//quarter and m_pMultiple will be quarters 
	
	pCoin[1] = new CCoin(10);// 10 is the value with which denomination needs  
	//to be set. In this case m_pSingle will be dime 
	//and m_pMultiple will be dimes 
	
	pCoin[2] = new CCoin(5); // 5 is the value with which denomination needs  
	//to be set. In this case m_pSingle will be 
	// nickel and m_pMultiple will be nickels 
	
	pCoin[3] = new CCoin(1); // 1 is the value with which denomination needs  
	//to be set. In this case m_pSingle will be 
	//penny and m_pMultiple will be pennies 
	
	cout << endl << "Enter amount "; 
	cin >> dAmount; 

	for (int i = 0; i < 4; i++) 
	{ 
	    pCoin[i]->change(dAmount); 

	// Calculate how many quarters exists in  
	//first coin object. If so calulate the 
	//no: of quarters and that amount taken 
	//fro next iteration must be the remaining 
	//amount. 
 
 	} 
//Print all coin objects and if count is more than 1 print message 
//properly as mentioned in the question. If denomination is 0 no need to 
//print that coin. 
}

CCoin::CCoin(const int& m_nDenom)
{
	this-> m_nDenom = m_nDenom;
	m_nCount = 0;
	if(m_nDenom == 1)
	{
		m_pSingle = "penny";
		m_pMultiple = "pennies";
	}
	else if(m_nDenom == 5)
	{
		m_pSingle = "nickel";
		m_pMultiple = "nickels";
	}
	else if(m_nDenom == 10)
	{
		m_pSingle = "dime";
		m_pMultiple = "dimes";
	}
	else if(m_nDenom == 25)
	{
		m_pSingle = "quarter";
		m_pMultiple = "quarters";
	}

}

void CCoin::print()
{
	const char* chCoin;
    chCoin = m_pSingle;
	if(m_nCount > 1)
	{
	   chCoin = m_pMultiple;
	}
	cout << m_nCount << " " << chCoin<< endl;
}

void CCoin::change(double& Amount)
{
    if(Amount){
        Amount *= 100.00;
        m_nCount = Amount/m_nDenom;
        Amount =Amount - m_nDenom * m_nCount;
        Amount /= 100.00;
    }
    print();
}
