#include<iostream>
#include<vector>
using namespace std;

int majorityElem(vector<int> vec, int n) {      // TC: O(N^2)   SC: O(1)
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=0; j<n; j++) {
            if (vec[i] == vec[j]) {
                count++;
            }
        }
        if (count > n/2) {
            return vec[i];
        }
    }
    return -1;
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

    cout << "The element that appears more than " << n/2 << " times is: " << majorityElem(vec, n);
    return 0;
}