#include <iostream>
using namespace std;

template <typename T>
class CDoublyLinkedList
{
private:
    struct NODE
    {
        T m_data;
        struct NODE* m_pNext;
        struct NODE* m_pPrev;

        NODE(T data, NODE* next = nullptr, NODE* prev = nullptr)
            : m_data(data), m_pNext(next), m_pPrev(prev) {}
    };

    NODE* m_pRoot;
    NODE* m_pTail;

public:
    CDoublyLinkedList() : m_pRoot(nullptr), m_pTail(nullptr) {}

    ~CDoublyLinkedList() {
        while (m_pRoot != nullptr) {
            NODE* temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
        }
    }

    void Insert(T data)
    {
        NODE* newNode = new NODE(data);
        if (m_pRoot == nullptr)
        {
            m_pRoot = newNode;
            m_pTail = newNode;
        }
        else
        {
            m_pTail->m_pNext = newNode;
            newNode->m_pPrev = m_pTail;
            m_pTail = newNode;
        }
    }

    void Print() const
    {
        NODE* current = m_pRoot;
        while (current != nullptr)
        {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }

    void Delete(T data)
    {
        if (m_pRoot == nullptr)
            return;

        if (m_pRoot->m_data == data)
        {
            NODE* temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            if (m_pRoot != nullptr)
                m_pRoot->m_pPrev = nullptr;
            else
                m_pTail = nullptr;
            delete temp;
            return;
        }

        NODE* current = m_pRoot;
        while (current != nullptr && current->m_data != data)
        {
            current = current->m_pNext;
        }

        if (current != nullptr)
        {
            if (current->m_pNext != nullptr)
                current->m_pNext->m_pPrev = current->m_pPrev;
            else
                m_pTail = current->m_pPrev;

            if (current->m_pPrev != nullptr)
                current->m_pPrev->m_pNext = current->m_pNext;

            delete current;
        }
        else
        {
            cout << "Value " << data << " not found in the list!" << endl;
        }
    }
};

int main(int argc, char* argv[])
{
    CDoublyLinkedList<int> list;

    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(5);

    list.Print();

    cout << "Deleting 20 from the list." << endl;
    list.Delete(20);
    list.Print();

    return 0;
}
