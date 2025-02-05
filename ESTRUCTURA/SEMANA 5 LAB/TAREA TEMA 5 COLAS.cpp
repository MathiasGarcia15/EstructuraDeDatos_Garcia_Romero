#include <iostream>
using namespace std;

struct NODE
{
    int m_data;
    NODE* m_pNext;
};

class Queue
{
private:
    NODE* m_pFront;
    NODE* m_pRear;

public:
    Queue() : m_pFront(nullptr), m_pRear(nullptr) {}

    void Enqueue(int data)
    {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = nullptr;

        if (m_pRear == nullptr)
        {
            m_pFront = newNode;
            m_pRear  = newNode;
        }
        else
        {

            m_pRear->m_pNext = newNode;
            m_pRear = newNode;
        }
    }

    void Dequeue()
    {
        if (m_pFront == nullptr)
        {
            cout << "La cola está vacía, no se puede hacer dequeue." << endl;
            return;
        }

        NODE* temp = m_pFront;
        m_pFront = m_pFront->m_pNext;
        delete temp;

        if (m_pFront == nullptr)
        {
            m_pRear = nullptr;
        }
    }

    int Front() const {
        if (m_pFront == nullptr) {
            cout << "La cola está vacía." << endl;
            return -1;
        }
        return m_pFront->m_data;
    }

    bool IsEmpty() const {
        return m_pFront == nullptr;
    }

    void Print() const
    {
        if (m_pFront == nullptr) {
            cout << "La cola está vacía." << endl;
            return;
        }

        NODE* current = m_pFront;
        while (current != nullptr) {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Queue queue;

    queue.Enqueue(30);
    queue.Enqueue(20);
    queue.Enqueue(60);
    queue.Enqueue(10);

    cout << "Contenido de la cola: ";
    queue.Print();

    cout << "Valor del frente de la cola: " << queue.Front() << endl;

    cout << "Haciendo dequeue de la cola." << endl;
    queue.Dequeue();
    queue.Print();

    cout << "Valor del frente de la cola después de hacer dequeue: " << queue.Front() << endl;

    if (queue.IsEmpty())
    {
        cout << "La cola esta vacia." << endl;
    }
    else
    {
        cout << "La cola no esta vacia." << endl;
    }

    return 0;
}
