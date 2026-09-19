#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
};

bool compare(Edge a, Edge b) {
    return a.wt < b.wt;
}

// DSU
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionSet(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return;
        }

        if (size[u] < size[v]) {
            swap(u, v);
        }

        parent[v] = u;
        size[u] += size[v];
    }
};

// Kruskal using DSU
// TC: O(E log E) SC: O(V)
int kruskalDSU(int V, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), compare);

    DisjointSet ds(V);
    int total = 0, count = 0;

    for (auto edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            total += edge.wt;
            count++;
            ds.unionSet(edge.u, edge.v);
        }
    }

    return (count == V - 1) ? total : -1;
}

// Kruskal without DSU - component labeling
// TC: O(E log E + E * V)   SC: O(V)
int kruskalComp(int V, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> component(V);

    for (int i = 0; i < V; i++) {
        component[i] = i;
    }

    int total = 0, count = 0;

    for (auto edge : edges) {
        if (component[edge.u] != component[edge.v]) {
            total += edge.wt;
            count++;

            int oldComponent = component[edge.v];

            for (int i = 0; i < V; i++) {
                if (component[i] == oldComponent) {
                    component[i] = component[edge.u];
                }
            }
        }
    }

    return (count == V - 1) ? total : -1;
}
// maintain component arr to know which connected component each vertex currently belongs to, so we can avoid adding edges that create cycles

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    cout << "MST using DSU: " << kruskalDSU(V, edges) << endl;
    cout << "MST without DSU: " << kruskalComp(V, edges) << endl;

    return 0;
}