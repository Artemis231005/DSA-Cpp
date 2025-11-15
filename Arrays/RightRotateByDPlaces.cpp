#include<iostream>
#include<vector>
using namespace std;

void rightRotateByDPlaces(vector<int> &arr, int n, int d) {          // TC: O(n+d) Extra SC: O(d)
    d = d % n;
    int temp[100];
    for (int i=0; i<d; i++) {
        temp[i] = arr[n - d + i];
    }
    for (int i=n-1; i>=d; i--) {
        arr[i] = arr[i - d];
    }
    for (int i=0; i<d; i++) {
        arr[i] = temp[i];
    }
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
    rightRotateByDPlaces(vec, n, d);
    cout << "After right rotation by " << d << " , vector: ";
    display(vec);
    return 0;
}