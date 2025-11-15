#include<iostream>
#include<vector>
using namespace std;

vector<int> rightRotateByOne(vector<int> &arr, int n) {
    int temp = arr[n-1];
    for(int i=n; i>0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
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
    cout << "Enter size: ";
    cin >> n;
    vector <int> vec (n);

    cout << "Enter the values: ";
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    cout << "Original vector: ";
    display(vec);

    cout << "After right rotation by one, vector: ";
    vector<int> ans = rightRotateByOne(vec, n);
    display(ans);
    return 0;
}