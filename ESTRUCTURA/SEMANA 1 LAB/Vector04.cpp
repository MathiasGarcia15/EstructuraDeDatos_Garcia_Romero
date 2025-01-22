#include <iostream>
using namespace std;


class CVector
{
private:
    int* m_pVect;  
    int m_nCount;  
    int m_nMax;   
    int m_nDelta;  

    void Init(int delta); 
    void Resize();        

public:
    CVector(int delta = 10); 
    void Insert(int elem);   
    void Print();            
};

CVector::CVector(int delta)
{
    Init(delta); 
}

void CVector::Init(int delta)
{
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = delta;
    m_pVect = new int[m_nMax]; 
}

void CVector::Resize()
{
    int* pNewVect = new int[m_nMax + m_nDelta]; 

    for (int i = 0; i < m_nCount; ++i) 
        pNewVect[i] = m_pVect[i];

    delete[] m_pVect; 
    m_pVect = pNewVect; 
    m_nMax += m_nDelta; 
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) 
        Resize(); 

    m_pVect[m_nCount++] = elem; 
}

void CVector::Print()
{
    for (int i = 0; i < m_nCount; ++i)
        cout << m_pVect[i] << " "; 
    cout << endl;
}

int main()
{
    CVector vec;

    
    vec.Insert(10);
    vec.Insert(20);
    vec.Insert(30);

    
    vec.Print(); 

    return 0;
}

/****************
Tarea 1 es insertar

gVect : 10, 20, 30


*****************/

