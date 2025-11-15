#include<iostream>
#include<vector>
using namespace std;

void moveZerosToEnd(vector<int> &arr) {                       // TC: O(N)   SC: O(1) 
    int n = arr.size();
    int j = -1;
    
    for (int i=0; i<n; i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    for (int i=j+1; i<n; i++) {
        if (arr[i] != 0) {
            swap (arr[i], arr[j]);
            j++;
        }
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