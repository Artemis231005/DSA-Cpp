#include<iostream>
#include<vector>
using namespace std;

vector<int> leftRotateByOne(vector<int> &arr, int n) {
    int temp = arr[0];
    for(int i=1; i<n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    vector<int> vec;
    cout << "Enter size: ";
    cin >> n;

    vec.resize(n);                                  // allocate space before using indices
    // Or:  vector<int> vec(n);                     // declare and allocate space at same time after getting n

    cout << "Enter the values: ";
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    cout << "Original vector: ";
    display(vec);

    cout << "After left rotation by one, vector: ";
    vector<int> ans = leftRotateByOne(vec, n);
    display(ans);
    return 0;
}