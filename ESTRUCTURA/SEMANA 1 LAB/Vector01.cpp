#include <iostream>
using namespace std;

int gVect[100]; 
int gnCount=0; 

void Insert(int elem)
{
	if( gnCount < 100 ) 
		gVect[gnCount++] = elem; 
}

void Display()
{
	cout << "Elementos en el arreglo: ";
	for (int i = 0; i < gnCount; i++) 
	{
		cout << gVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << gnCount <<endl;
}

int Search(int elem)
{
    for (int i = 0; i < gnCount; i++)
    {
        if (gVect[i] == elem)
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
            gVect[i] = gVect[i + 1];
        }
        gnCount--;
    }
}

int main(int argc, char *argv[]) 
{
	Insert(10);  
	Insert(20);  
	Insert(30);  
	
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
