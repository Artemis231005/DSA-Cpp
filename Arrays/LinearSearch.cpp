#include<iostream>
#include<vector>
using namespace std;

int linearSearch (vector<int> arr, int val) {
    int found = -1;
    for (int i=0; i<arr.size(); i++) {
        if (arr[i] == val) {
            found = i;
        }
    }
    return found;
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

    cout << "Enter the value you want to search for: ";
    int val;
    cin >> val;

    int found = linearSearch(vec, val);
    if (found != -1) {
        cout << "Value " << val << " found at index: " << found << endl;
    } else {
        cout << "Value " << val << " not found" << endl;
    }
    return 0;
}