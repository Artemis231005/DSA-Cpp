#include<iostream>
#include<vector>
using namespace std;

void sortArr(vector<int> &vec) {        // TC: O(2N)   SC: O(1)
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] == 0) {
            count0++;
        } else if (vec[i] == 1) {
            count1++;
        } else {
            count2++;
        }
    }

    int idx = 0;

    for (int i = 0; i < count0; i++) {
        vec[idx++] = 0;
    }
    for (int i = 0; i < count1; i++) {
        vec[idx++] = 1;
    }
    for (int i = 0; i < count2; i++) {
        vec[idx++] = 2;
    }
}

void display(vector<int> &vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    vector<int> vec(n);                     
    cout << "Enter the values: ";
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    cout << "The sorted array is: ";
    sortArr(vec);
    display(vec);
    return 0;
}