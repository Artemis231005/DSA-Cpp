#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, u, v, wt;
    cout << "Enter the values of n and m: ";
    cin >> n >> m;

    // -------- Matrix Method ---------------------------------------------------------------------------------------------------------

    int adjMatrix[100][100] = {0};
    // int adj[n+1][m+1];                           // For 1-based indexing
    // int adj[n][m];                               // For 0-based indexing 
    
    for (int i=0; i<m; i++) {                       // TC: O(N)    SC: O(N^2)
        cin >> u >> v;                              // Getting nodes between which there exists an edge
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    } 

    // For weighted graph:
    int adjMatrixWt[100][100] = {0};

    for (int i=0; i<m; i++) {                    
        cin >> u >> v >> wt;                              
        adjMatrixWt[u][v] = wt;
        adjMatrixWt[v][u] = wt;
    } 

    // For directed graph: 
    int adjMatrixDir[100][100] = {0};

    for (int i=0; i<m; i++) {                       
        cin >> u >> v;
        adjMatrixDir[u][v] = 1;                     
    }

    // -------- Adjacency List Method -------------------------------------------------------------------------------------------------

    vector<int> adjList[100];
    // vector<int> adj[n+1];                        // For 1-based indexing 
    // vector<int> adj[n+1];                        // For 0-based indexing

    for (int i=0; i<m; i++) {                       // TC: O(N)     SC: O(2E)
        cin >> u >> v;
        adjList[u].push_back(v);                        // On u-th index, store v
        adjList[v].push_back(u);
    }

    // For weighted graph:
    vector<pair<int, int>> adjListWt[100];
    for (int i=0; i<m; i++) {                       
        cin >> u >> v >> wt;
        adjListWt[u].push_back({v, wt});                        
        adjListWt[v].push_back({u, wt});
    }

    // For directed graph: 
    vector<int> adjListDir[100];

    for (int i=0; i<m; i++) {                       // TC: O(N)     SC: O(E)
        cin >> u >> v;
        adjListDir[u].push_back(v);                        
    }
    return 0;
}