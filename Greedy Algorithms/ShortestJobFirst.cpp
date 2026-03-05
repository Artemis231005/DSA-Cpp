#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC: O(nlogn)   SC: O(1)
int SFJ(vector<int> processes) {
    int n = processes.size();
    int t = 0, wt = 0;
    sort(processes.begin(), processes.end());

    for (int i=0; i<n; i++) {
        wt += t;
        t += processes[i];
    }
    return (wt/n);
}

int main() {
    int n, m, val;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> processes;

    cout << "Enter duration of processes: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        processes.push_back(val);
    }

    cout << "Average waiting time for processes by SHortest Job First Algorithm is: " << SFJ(processes);
    return 0;
}