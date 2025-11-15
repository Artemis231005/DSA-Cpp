#include<iostream>
#include<vector>
using namespace std;

void moveZerosToEnd(vector<int> &arr) {          
    int n = arr.size();
    vector<int> temp;
    for (int i=0; i<n; i++) {
        if (arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    int nzSize = temp.size();
    for (int i=0; i<nzSize; i++) {
        arr[i] = temp[i];
    }
    for (int i=nzSize; i<n; i++) {
        arr[i] = 0;
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

    cout << "After moving all zeros to the end, vector: ";
    moveZerosToEnd(vec);
    display(vec);
    return 0;
}