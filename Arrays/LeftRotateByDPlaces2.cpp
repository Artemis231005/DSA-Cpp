#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void leftRotateByDPlaces(vector<int> &arr, int n, int d) {          // TC: O(N) Extra SC: O(1)
    d = d % n;  
    reverse(arr.begin(), arr.begin() + d);                          // reverses from 0th index to d-1
    reverse(arr.begin() + d, arr.begin() + n);    
    reverse(arr.begin(), arr.begin() + n);
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    int d;
    cout << "Enter size: ";
    cin >> n;

    vector<int> vec(n);                     

    cout << "Enter the values: ";
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    cout << "Original vector: ";
    display(vec);

    cout << "Enter no of places to rotate vector by: ";
    cin >> d;
    leftRotateByDPlaces(vec, n, d);
    cout << "After left rotation by " << d << ", vector: ";
    display(vec);
    return 0;
}