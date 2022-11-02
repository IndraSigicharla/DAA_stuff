#include <iostream>
#include <vector>
#include <limits>
using namespace std;

#define V 9

void printer(auto& a) {
    cout << endl;
    cout << "The adjacency matrix is: " << endl;
    int i = 0;
    cout << "  ";
    for (int j = 0; j < a.size(); j++) {
        cout << "V" << j + 1 << " ";
    }
    cout << endl;
    for (const auto& v : a) {
        cout << "V" << ++i << " ";
        for (const auto& i : v) {
            cout << i << "  ";
        }
        cout << endl;
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = std::numeric_limits<int>::max(), sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != std::numeric_limits<int>::max()
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist, V);
}

int main() {
    int size;
    cout << "Enter the number of vertices in the map: ";
    cin >> size;
    int default_val = 0;
    vector<vector<int>> a(size, vector<int>(size, default_val));
    for (int i = 0; i < size; i++) {
        int connections;
        cout << "Enter the number of vertices the first vertex is connected to: ";
        cin >> connections;
        for (int j = 0; j < connections; j++) {
            int num, len;
            cout << j + 1 << ") Enter the number and distance of this connection: ";
            cin >> num >> len;
            a[i][num - 1] = len;
        }

    }
    printer(a);
    cout << "The vertices are: " << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << "V" << i + 1 << " ";
    }
}
