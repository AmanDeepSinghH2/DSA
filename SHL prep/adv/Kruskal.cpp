#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a Disjoint Set (Union-Find)
struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find function with path compression
    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    // Union function by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(V);
    vector<Edge> result;
    int mstWeight = 0;

    for (const auto& edge : edges) {
        int x = dsu.find(edge.src);
        int y = dsu.find(edge.dest);

        if (x != y) {
            result.push_back(edge);
            mstWeight += edge.weight;
            dsu.unite(x, y);
        }
    }

    cout << "Edges in the constructed MST:" << endl;
    for (const auto& edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;
}

int main() {
    int V = 4; // Number of vertices in graph
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    cout << "Graph Edges (Source, Dest, Weight):" << endl;
    for(const auto& e : edges) cout << e.src << " -- " << e.dest << " == " << e.weight << endl;

    kruskalMST(V, edges);

    return 0;
}
