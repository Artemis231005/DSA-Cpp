#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> arr) {
    if (arr.empty()) {
        cout << "{}";
    } else {
        for (int i: arr) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void printSubsequences(int idx, vector<int>& vec, vector<int> &store, int n) {
    if (idx >= n) {
        display(store);
        return;
    }

    store.push_back(vec[idx]);
    printSubsequences(idx+1, vec, store, n);
    store.pop_back();

    printSubsequences(idx+1, vec, store, n);
}

int main() {
    int n, val;
    vector<int> vec;

    cout << "Enter size of vector: ";
    cin >> n;

    cout <<"Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    vector<int> store;
    cout << "Subsequences of the array are: " << endl;
    printSubsequences(0, vec, store, n);
    return 0;
}