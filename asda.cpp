#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

class Graph {
private:
    int V; // Número de vértices
    vector<vector<int>> adjMatrix; // Matriz de adyacencia ponderada

public:
    Graph() {
        srand(time(0)); // Inicializar la semilla aleatoria
        V = rand() % 16 + 15; // Número aleatorio entre 15 y 30
        adjMatrix.resize(V, vector<int>(V, 0)); // Inicializar matriz con ceros
    }

    // Agregar una arista ponderada de u a v con peso w
    void addArista(int u, int v, int w) {
        if (u >= 0 && u < V && v >= 0 && v < V && w > 0) {
            adjMatrix[u][v] = w; // Asignar peso a la conexión de u -> v
        }
    }

    // Obtener el número de vértices
    int numVertices(){
        return V;
    }

    // Mostrar la matriz de adyacencia ponderada con etiquetas
    void display() {
        cout << "\nGrafo Ponderado con " << V << " vértices\n" << endl;
        cout << "    "; // Espacio para la esquina superior izquierda
        for (int i = 0; i < V; i++) {
            cout << setw(3) << i;
        }
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << setw(3) << i << " "; // Etiqueta de fila
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == 0)
                    cout << setw(3) << "-"; // Mostrar '-' si no hay conexión
                else
                    cout << setw(3) << adjMatrix[i][j]; // Mostrar peso
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g; 
    int startVertice, endVertice;

    // Generar conexiones aleatorias con mínimo 2 y máximo V/3 aristas por vértice
    for (int u = 0; u < g.numVertices(); u++) {

        int numAristas = rand() % (g.numVertices() / 3 - 2 + 1) + 2; // Entre 2 y V/3 aristas

        for (int i = 0; i < numAristas; i++) {
            int v = rand() % g.numVertices();
            int w = rand() % 20 + 1; // Peso entre 1 y 20
            if (u != v) {
                g.addArista(u, v, w);
            }
        }
    }

    cout << "Indique el vértice de inicio: ";
    cin >> startVertice;

    cout << "\nIndique el vértice de final: ";
    cin >> endVertice;


    g.display(); 

    return 0;
}
