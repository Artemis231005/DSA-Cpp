#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber (vector<int> vec, int N) {            // TC: O(2N)   SC: O(N)
    vector<int> hash (N+1, 0);
    for (int i=0; i<N; i++) {
        hash[vec[i]] = 1;
    }
    for (int i=1; i<=N;i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
    return -1;
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, elem;
    vector<int> vec;
    cout << "Enter value of N: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n-1; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    cout << "The missing number is: " << findMissingNumber(vec, n);
    return 0;
}