#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph() {
        srand(time(0));
        V = rand() % 16 + 15;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addArista(int u, int v, int w) {
        if (u >= 0 && u < V && v >= 0 && v < V && w > 0) {
            adjMatrix[u][v] = w;
        }
    }

    int numVertices() {
        return V;
    }

    void display() {
        cout << "\nGrafo Ponderado con " << V << " vértices\n" << endl;
        cout << "    ";
        for (int i = 0; i < V; i++) {
            cout << setw(3) << i;
        }
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << setw(3) << i << " ";
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == 0)
                    cout << setw(3) << "-";
                else
                    cout << setw(3) << adjMatrix[i][j];
            }
            cout << endl;
        }
    }

    // Implementación de Dijkstra
    vector<int> dijkstra(int start, int end, vector<vector<int>> &graph) {
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (int v = 0; v < V; v++) {
                if (graph[u][v] > 0) { // Hay conexión
                    int weight = graph[u][v];
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        parent[v] = u;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        // Reconstruir el camino
        vector<int> path;
        for (int at = end; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        return (path.size() > 1) ? path : vector<int>();
    }

    // Encontrar los 2 mejores caminos entre 'start' y 'end'
    void findBestTwoPaths(int start, int end) {
        vector<vector<int>> tempGraph = adjMatrix;

        vector<int> bestPath = dijkstra(start, end, tempGraph);
        if (bestPath.empty()) {
            cout << "No hay camino entre " << start << " y " << end << ".\n";
            return;
        }

        cout << "\nCamino 1 (más corto): ";
        for (int node : bestPath) cout << node << " ";
        cout << endl;

        // Penalizar la primera ruta eliminando sus aristas
        for (size_t i = 0; i < bestPath.size() - 1; i++) {
            int u = bestPath[i], v = bestPath[i + 1];
            tempGraph[u][v] = 0; // Eliminamos la arista
        }

        // Segunda ejecución de Dijkstra
        vector<int> secondBestPath = dijkstra(start, end, tempGraph);
        if (secondBestPath.empty()) {
            cout << "No hay un segundo mejor camino.\n";
            return;
        }

        cout << "Camino 2 (segundo mejor): ";
        for (int node : secondBestPath) cout << node << " ";
        cout << endl;
    }
};

int main() {
    Graph g;
    int startVertice, endVertice;

    for (int u = 0; u < g.numVertices(); u++) {
        int numAristas = rand() % (g.numVertices() / 3 - 2 + 1) + 2;

        for (int i = 0; i < numAristas; i++) {
            int v = rand() % g.numVertices();
            int w = rand() % 10 + 1;
            if (u != v) {
                g.addArista(u, v, w);
            }
        }
    }

    g.display();

    cout << "\nIndique el vértice de inicio: ";
    cin >> startVertice;
    cout << "Indique el vértice de final: ";
    cin >> endVertice;

    g.findBestTwoPaths(startVertice, endVertice);

    return 0;
}
