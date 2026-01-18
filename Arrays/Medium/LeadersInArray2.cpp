#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> printLeaders (vector<int> vec) {    // TC: O(N)   SC: O(1)
    vector<int> ans;
    
    int maxElem = INT_MIN;
    for(int i=vec.size()-1; i>=0; i--) {
        if (vec[i] > maxElem) {
            ans.push_back(vec[i]);
            maxElem = vec[i];
        }
    }
    // will give elems in reverse order, can use .reverse() to put in correct order
    return ans;
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

    cout << "Leaders in the array are: ";
    vector<int> ans = printLeaders(vec);

    for (int i:ans) {
        cout << i << " ";
    }

    return 0;
}
