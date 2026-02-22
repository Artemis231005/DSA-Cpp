#include<iostream>
#include<vector>
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

// TC: O(n*2^n)   SC: O(n)
// Each element has 2 choices ie take / not take
// Total subsequences = 2^n and printing each subsequence takes up to O(n) time
void printSubsequences(int idx, vector<int> & arr, vector<int> &store, int n) {
    if (idx == n) {
        display(store);
        return;
    }

    // take idx
    store.push_back(arr[idx]);
    printSubsequences(idx+1, arr, store, n);
    store.pop_back();

    // dont take
    printSubsequences(idx+1, arr, store, n);
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