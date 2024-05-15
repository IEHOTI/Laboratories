#include "G:\Coding\Lib C\LibFun\Lib.h"
#include "func.h"

int main() {
    STL;
    STN;
    int N = rand()%6 + 5; 
    int K = rand()%3 + 1;
    //алгоритм краскала
    vector<Point> points(N);
    vector<Edge> edges;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            Edge E(i, j, calculateDistance(points[i], points[j]));
            edges.push_back(E);
        }
    }
    sort(edges.begin(), edges.end(), comp);

    vector<vector<int>> matrix(N, vector<int>(N, 0));
    for (int i = 0; i < N - K; i++) {
        int u = edges[i].GetU();
        int v = edges[i].GetV();
        int weight = edges[i].GetW();
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // алгоритм гамильтоновых путей
    vector<int> parent(N), size(N, 1);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < N - K+1; i++) {
        unite(parent, size, edges[i].GetU(), edges[i].GetV());
    }
    vector<vector<int>> clusters(N);
    for (int i = 0,j=-1; i < N; i++) {
        j = find(parent, i);
        clusters[j].push_back(i);
    }
    printClusterInfo(points, clusters);
    return 0;
}