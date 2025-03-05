#include <iostream>
#define INF 999999

using namespace std;

const int MAX = 100;

class MinHeap {
    public:
        int heap[MAX][2];
        int tamano;

        MinHeap() {
            tamano = 0;
        }

        void insertar(int dist, int nodo) {
            heap[tamano][0] = dist;
            heap[tamano][1] = nodo;
            int i = tamano;
            while (i > 0 && heap[(i - 1) / 2][0] > heap[i][0]) {
                swap(heap[i], heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            tamano++;
        }

        void heapificar(int i) {
            int menor = i;
            int izq = 2 * i + 1;
            int der = 2 * i + 2;

            if (izq < tamano && heap[izq][0] < heap[menor][0])
                menor = izq;
            if (der < tamano && heap[der][0] < heap[menor][0])
                menor = der;
            if (menor != i) {
                swap(heap[i], heap[menor]);
                heapificar(menor);
            }
        }

        int extraerMin() {
            int nodoMinimo = heap[0][1];
            heap[0][0] = heap[tamano - 1][0];
            heap[0][1] = heap[tamano - 1][1];
            tamano--;
            heapificar(0);
            return nodoMinimo;
        }

        bool estaVacio() {
            return tamano == 0;
        }

        void disminuirClave(int nodo, int nuevaDist) {
            for (int i = 0; i < tamano; i++) {
                if (heap[i][1] == nodo) {
                    heap[i][0] = nuevaDist;
                    while (i > 0 && heap[(i - 1) / 2][0] > heap[i][0]) {
                        swap(heap[i], heap[(i - 1) / 2]);
                        i = (i - 1) / 2;
                    }
                    break;
                }
            }
        }
};

class Grafo {
    int V;
    int adj[MAX][MAX];

public:
    Grafo(int V) {
        this->V = V;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void agregarArista(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    void caminoMasCorto(int origen) {
        int dist[MAX];
        bool finalizado[MAX];
        MinHeap heap;

        // Inicialización
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            finalizado[i] = false;
        }
        dist[origen] = 0;
        heap.insertar(0, origen);

        // Algoritmo de Dijkstra
        while (!heap.estaVacio()) {
            int u = heap.extraerMin();
            finalizado[u] = true;

            // Relajación
            for (int v = 0; v < V; v++) {
                if (adj[u][v] && !finalizado[v] && dist[v] > dist[u] + adj[u][v]) {
                    dist[v] = dist[u] + adj[u][v];
                    heap.insertar(dist[v], v);
                }
            }
        }

        // Para imprimir los resultados
        cout << "Nodo\tDistancia desde el origen\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << "\n";
        }
    }
};

// MAIN
int main() {
    int V = 9;
    Grafo g(V);


    g.agregarArista(0, 1, 3);
    g.agregarArista(0, 7, 10);
    g.agregarArista(1, 2, 6);
    g.agregarArista(1, 7, 15);
    g.agregarArista(2, 3, 5);
    g.agregarArista(2, 8, 3);
    g.agregarArista(2, 5, 8);
    g.agregarArista(3, 4, 12);
    g.agregarArista(3, 5, 18);
    g.agregarArista(4, 5, 11);
    g.agregarArista(5, 6, 4);
    g.agregarArista(6, 7, 2);
    g.agregarArista(6, 8, 9);
    g.agregarArista(7, 8, 6);

    g.caminoMasCorto(0);

    return 0;
}
