#include <iostream>
using namespace std;

int *gpVect = NULL; 
int gnCount = 0; 
int gnMax = 0; 

void Resize();

void Insert(int elem)
{
	if( gnCount == gnMax ) 
		Resize(); 
	gpVect[gnCount++] = elem; 
}

void Resize()
{
	const int delta = 5; 
	int *pTemp, i;
	pTemp = new int[gnMax + delta]; 
	for(i = 0 ; i < gnMax ; i++)
		pTemp[i] = gpVect[i]; 
	delete [ ] gpVect; 
	gpVect = pTemp; 
	gnMax += delta; 
}

void Display()
{
	cout << "Elementos en el arreglo: ";
	for (int i = 0; i < gnCount; i++) 
	{
		cout << gpVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << gnCount <<endl;
}

int Search(int elem)
{
    for (int i = 0; i < gnCount; i++)
    {
        if (gpVect[i] == elem)
            return i; 
    }
    return -1; 
}

void Delete(int elem)
{
    int index = Search(elem);
    if (index != -1) 
    {
        for (int i = index; i < gnCount - 1; i++)
        {
            gpVect[i] = gpVect[i + 1]; 
        }
        gnCount--; // 
    }
}


int main(int argc, char *argv[]) 
{
	Insert(10);  
	Insert(20);  
	Insert(30); 
	Insert(40); 
	Insert(50);  
	
	Display();  

	Insert(60);  
	
	Display();  
	
	Delete(20); 

    Display(); 
	
	return 0;
}

/****************
Tarea 1 es borrar

gVect : 10, 20, 30

Delete(20)
Se supone que primero deben buscar el elemento Search()

gVect : 10, 30

*****************/

