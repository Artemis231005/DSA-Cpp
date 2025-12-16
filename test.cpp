#include <iostream>
#include <vector>
using namespace std;

void leftRotateByD (vector<int> &arr, int n) {
    vector<int> temp;
    for (int i=0; i<n; i++) {
        if (arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }
    int tempsize = temp.size();
    for (int i=0; i<tempsize; i++) {
        arr[i] = temp[i];
    }
    for (int i=tempsize; i<n; i++) {
        arr[i] = 0;
    }
}

int main() {
    vector<int> vec;
    int n;
    int val;
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    cout << "Vector left rotated by 1: ";
    leftRotateByD(vec, n);
    for (int i: vec) {
        cout << i << " ";
    }
    return 0;
}