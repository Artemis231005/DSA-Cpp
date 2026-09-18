#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Dijkstra is not applicable to graphs with negative edge weights or graphs containing negative weight cycles

// TC: O(E log V)   SC: O(V + E) (priority queue + distance array + adjacency list)
vector<int> dijkstraPQ(int V, vector<vector<int>> adj[], int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Lazy check: Ignore an outdated entry in the priority queue
        if (distance > dist[node]) {
            continue;
        }
        // It's called the lazy check because instead of removing the old entry from the priority queue, we simply ignore it when it comes out

        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWt = it[1];

            if (distance + edgeWt < dist[adjNode]) {
                dist[adjNode] = distance + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}


// TC: O(E log V)   SC: O(V + E)  (set + distance array + adjacency list)
vector<int> dijkstraSet(int V, vector<vector<int>> adj[], int src) {
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto it = *(st.begin());
        int distance = it.first;
        int node = it.second;
        st.erase(it);

        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWt = it[1];

            if (distance + edgeWt < dist[adjNode]) {
                // Remove old pair if it exists
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = distance + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

/* 
A priority_queue is typically implemented as a binary heap, while set is typically implemented as a Red-Black Tree
Binary heap: array-based -> contiguous memory -> good cache locality -> fewer pointer operations.
Red-Black Tree: node-based -> lots of pointers -> worse cache locality -> tree rotations/rebalancing → more overhead

So even though both give roughly O(log V), the constant factors are smaller for a heap, so the priority queue is usually faster
And Dijkstra's PQ version gets another practical advantage of lazy check/ lazy deletion a it avoids the cost of searching/removing an arbitrary 
old pair unlike set

Set explicitly removes the old pair, meaning no stale entries; Priority queue keeps the old pair and the lazy check ignores it later.
*/

int main() {
    int V, E;
    cout << "Enter number of nodes and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj[100];

    cout << "Enter edges and their weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> ansPQ = dijkstraPQ(V, adj, src);
    vector<int> ansSet = dijkstraSet(V, adj, src);

    cout << "\nShortest distances using Priority Queue:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": ";
        if (ansPQ[i] == 1e9) {
            cout << "INF";
        } else {
            cout << ansPQ[i];
        }
        cout << endl;
    }

    cout << "\nShortest distances using Set:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : ";
        if (ansSet[i] == 1e9) {
            cout << "INF";
        } else {
            cout << ansSet[i];
        }
        cout << endl;
    }

    return 0;
}