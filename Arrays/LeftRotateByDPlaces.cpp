#include<iostream>
#include<vector>
using namespace std;

void leftRotateByDPlaces(vector<int> &arr, int n, int d) {          // TC: O(n+d) Extra SC: O(d)
    d = d % n;
    int temp[100];
    for (int i=0; i<d; i++) {                                       // TC: O(n)
        temp[i] = arr[i];
    }
    for (int i=d; i<n; i++) {                                       // TC: O(n-d)
        arr[i-d] = arr[i];
    }
    for (int i=n-d; i<n; i++) {                                     // TC: O(d)
        arr[i] = temp[i - (n-d)];
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
    leftRotateByDPlaces(vec, n, d);
    cout << "After left rotation by " << d << " , vector: ";
    display(vec);
    return 0;
}