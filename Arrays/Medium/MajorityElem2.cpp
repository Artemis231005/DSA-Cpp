#include<iostream>
#include<vector>
#include <map>
using namespace std;

int majorityElem(vector<int> vec, int n) {    // TC: O(NlogN)   SC: O(N) (all unique elem)
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        mp[vec[i]]++;
    }
    for (auto it: mp) {
        if (it.second > (n/2)) {
            return it.first;
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