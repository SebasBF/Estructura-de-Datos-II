#include <iostream>
#include <vector>
#include <ctime>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <climits>

using namespace std;

void generateGraph(vector<vector<pair<int, int>>>& adj, int N) {
    set<pair<int, int>> edgesExist;
    int maxEdges = N / 3;
    int edges;

    for (int i = 0; i < N; i++) {
        edges = (rand() % maxEdges) + 2;

        while (adj[i].size() < edges) {
            int vecino = rand() % N;

            if (vecino == i) continue;

            if (edgesExist.count({i, vecino}) == 0) {
                int peso = rand() % N + 1;
                adj[i].push_back({vecino, peso});
                edgesExist.insert({i, vecino});
            }
        }
    }
}

void displayGraph(const vector<vector<pair<int, int>>>& graph) {
    cout << "\nLista de adyacencia:\n";

    for (int i = 0; i < graph.size(); i++) {
        cout << "Vertice " << i << ": ";
        for (auto& edge : graph[i]) {
            cout << "(" << edge.first << ", peso: " << edge.second << ") ";
        }
        cout << "\n";
    }
}

vector<int> bfs(const vector<vector<pair<int, int>>>& adj, int start, int end, int& sumpeso) {
    vector<int> distancia(adj.size(), 999999999);//limite de distancia
    vector<int> predecesor(adj.size(), -1);
    queue<int> q;

    q.push(start);
    distancia[start] = 0;
  
    while (!q.empty()) {
        int u = q.front();  
        q.pop(); 

        for (auto& edge : adj[u]) { 
            int v = edge.first;
            int weight = edge.second;

            if (distancia[v] > distancia[u] + weight) {
                distancia[v] = distancia[u] + weight;
                predecesor[v] = u;
                q.push(v);
            }
        }
    }

    vector<int> path;
    if (distancia[end] == 999999999) {
        return path; 
    }
    sumpeso = distancia[end];

    for (int v = end; v != -1; v = predecesor[v]) {
        path.insert(path.begin(), v); 
    }
    return path;
}

int main() {
    srand(time(nullptr));
    int n = rand() % 16 + 15;
    int sumpeso;

    cout << "Numero de vertices " << n << "\n";
    
    vector<vector<pair<int, int>>> graph(n);
    generateGraph(graph, n);
    displayGraph(graph);

    int start, end;
    cout << "Entre el vertice de inicio: ";
    cin >> start;
    cout << "Entre el vertice final: ";
    cin >> end;
    cout << endl;

    vector<int> path1 = bfs(graph, start, end, sumpeso);

    if (path1.empty()){
        cout << "No hay camino entre" << start << " y " << end << "\n";
    } 
    else{
        cout << "Camino 1: ";
        for (int v : path1) {
            cout << v << " ";
        }
        cout<< " ; Peso recorrido: "<< sumpeso;
        cout << "\n";
    }


    if (!path1.empty()) {
        for (int i = 1; i < path1.size(); ++i) {
            int u = path1[i - 1];
            int v = path1[i];
            for (auto j = graph[u].begin(); j != graph[u].end(); j++) {
                if (j->first == v) {
                    graph[u].erase(j);
                    break;
                }
            }
        }

        vector<int> path2 = bfs(graph, start, end, sumpeso);

        if (path2.empty()) {
            cout << "No se encontro segundo camino entre" << start << " y " << end << "\n";
        } 
        else {
            cout << "Camino 2: ";
            for (int v : path2) {
                cout << v << " ";
            }
            cout<< " ; Peso recorrido: "<< sumpeso;
            cout << "\n";
        }
    }

    return 0;
}