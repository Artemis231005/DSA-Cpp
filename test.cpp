#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, u, v, wt;
    cout << "Enter the values of n and m: ";
    cin >> n >> m;

    vector<int> adjList[100];

    for (int i=0; i<m; i++) {                       
        adjList[u].push_back(v);                        
        adjList[v].push_back(u);
    }

    return 0;
}