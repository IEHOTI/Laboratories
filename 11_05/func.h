#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
class Point {
    double x, y;
public:
    Point() {
        x = rand() % 101 + 1;
        y = rand() % 101 + 1;
    }
    double GetX() { return x; }
    double GetY() { return y; }
};
class Edge { 
    int u, v;
    double weight;
public:
    Edge() { 
        u = 0; 
        v = 0; 
        weight = 0; 
    }
    Edge(int a, int b,double w) {
        u = a;
        v = b;
        weight = w;
    }
    int GetU() { return u; }
    int GetV() { return v; }
    double GetW() { return weight; }
};
double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p1.GetX() - p2.GetX(), 2) + pow(p1.GetY() - p2.GetY(), 2)); //sqrt((x1-x2)^2+(y1-y2)^2)
}
bool comp(Edge& a, Edge& b) {
    return (a.GetW() < b.GetW());
}
int find(vector<int>& parent, int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent, parent[u]);
}
void unite(vector<int>& parent, vector<int>& size, int u, int v) {
    u = find(parent, u);
    v = find(parent, v);
    if (u != v) {
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
}
void printClusterInfo(vector<Point>& points, vector<vector<int>>& clusters) {
    for (int i = 0; i < clusters.size(); i++) {
        int size = clusters[i].size();
        if (size != 0) {
            int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN, node;
            double sum_x = 0, sum_y = 0;
            for (int j = 0; j < clusters[i].size(); j++) {
                node = clusters[i][j];
                min_x = min(min_x, static_cast<int>(points[node].GetX()));
                max_x = max(max_x, static_cast<int>(points[node].GetX()));
                min_y = min(min_y, static_cast<int>(points[node].GetY()));
                max_y = max(max_y, static_cast<int>(points[node].GetY()));
                sum_x += points[node].GetX();
                sum_y += points[node].GetY();
            }
            double centroid_x = sum_x / size;
            double centroid_y = sum_y / size;
            cout << "Кластер " << i + 1 << ". Размер:" << size << ", Минимальный Х:" << min_x << ", Максимальный X:" << max_x << ", Минимальный Y:" << min_y << ", Максимальный Y:" << max_y;
            printf(", Центроид:[%.2f;%.2f]\n", centroid_x, centroid_y);
        }
    }
}