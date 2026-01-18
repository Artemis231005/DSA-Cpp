#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> vec) {   // TC: O(3N)  SC: O(1)
    int idx = -1;
    int n = vec.size();

    for (int i=n-2; i>=0; i--) {
        if (vec[i] < vec[i+1]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        reverse(vec.begin(), vec.end());
        return vec;
    }

    for (int i=n-1; i>idx; i--) {
        if(vec[i] > vec[idx]) {
            swap(vec[i], vec[idx]);
            break;
        }
    }

    reverse(vec.begin()+idx+1, vec.end());
    return vec;
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

    cout << "Next permutations is: ";
    vector<int> ans = nextGreaterPermutation(vec);
    for (int i: ans) {
        cout << i << " ";
    }
    return 0;
}






















