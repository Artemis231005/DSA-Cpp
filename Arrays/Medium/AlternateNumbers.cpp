#include<iostream>
#include<vector>
using namespace std;

// No of pos and neg elem not guaranteed to be equal
vector<int> alternateNo (vector<int> vec) {  
    int n = vec.size();
    vector<int> ans(n);
    vector<int> pos;
    vector<int> neg;

    for (int i=0; i<n; i++) {
        if (vec[i] > 0) {
            pos.push_back(vec[i]);
        } else {
            neg.push_back(vec[i]);
        }
    }

    int idx = 0, p = 0, q = 0;
    while (p < pos.size() && q < neg.size()) {
        ans[idx++] = pos[p++];
        ans[idx++] = neg[q++];
    }

    while (p < pos.size()) {
        ans[idx++] = pos[p++];
    }

    while (q < neg.size()) {
        ans[idx++] = neg[q++];
    }

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

    cout << "The rearranged array by sign (+ - + -) is: ";
    vector<int> ans = alternateNo(vec);
    display(ans);
    return 0;
}