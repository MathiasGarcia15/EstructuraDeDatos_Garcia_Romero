#include <iostream>
using namespace std;

// Definición de la clase CVector
class CVector {
private:
    int* m_pVect; // Puntero al arreglo
    int m_nCount; // Número de elementos en uso
    int m_nMax;   // Capacidad máxima del arreglo
    int m_nDelta; // Incremento para redimensionar

    void Init(int delta) {
        m_nCount = 0;
        m_nMax = delta;
        m_nDelta = delta;
        m_pVect = new int[m_nMax];
    }

    void Resize() {
        m_nMax += m_nDelta;
        int* temp = new int[m_nMax];
        for (int i = 0; i < m_nCount; i++) {
            temp[i] = m_pVect[i];
        }
        delete[] m_pVect;
        m_pVect = temp;
    }

    int Partition(int low, int high) {
        int pivot = m_pVect[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (m_pVect[j] < pivot) {
                i++;
                swap(m_pVect[i], m_pVect[j]);
            }
        }
        swap(m_pVect[i + 1], m_pVect[high]);
        return i + 1;
    }

public:
    CVector(int delta = 10) {
        Init(delta);
    }

    void Insert(int elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    void Display() {
        for (int i = 0; i < m_nCount; i++) {
            cout << m_pVect[i] << " ";
        }
        cout << endl;
    }

    void SelectionSort() {
        for (int i = 0; i < m_nCount - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < m_nCount; j++) {
                if (m_pVect[j] < m_pVect[minIndex]) {
                    minIndex = j;
                }
            }
            swap(m_pVect[i], m_pVect[minIndex]);
        }
    }

    void QuickSort(int low, int high) {
        if (low < high) {
            int pi = Partition(low, high);
            QuickSort(low, pi - 1);
            QuickSort(pi + 1, high);
        }
    }

    void InsertionSort() {
        for (int i = 1; i < m_nCount; i++) {
            int key = m_pVect[i];
            int j = i - 1;
            while (j >= 0 && m_pVect[j] > key) {
                m_pVect[j + 1] = m_pVect[j];
                j--;
            }
            m_pVect[j + 1] = key;
        }
    }

    int GetCount() const {
        return m_nCount;
    }

    ~CVector() {
        delete[] m_pVect;
    }
};

int main() {
    CVector gVect;
    gVect.Insert(10);
    gVect.Insert(20);
    gVect.Insert(30);
    gVect.Insert(5);
    gVect.Insert(50);
    gVect.Insert(15);

    cout << "Antes de ordenar: ";
    gVect.Display();

    // Descomentar el algoritmo de ordenamiento que se desee probar
    // gVect.SelectionSort();
    // gVect.QuickSort(0, gVect.GetCount() - 1);
    // gVect.InsertionSort();

    cout << "Despues de ordenar: ";
    gVect.Display();

    return 0;
}

