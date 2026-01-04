#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeElem (vector<int> vec) {   // TC: O(N) (unline other sol O(2N))   SC: O(1)  (extra)  
    int n = vec.size();
    vector<int> ans(n, 0);
    int posIdx = 0, negIdx = 1;

    for (int i=0; i<n; i++) {
        if (vec[i] < 0) {
            ans[negIdx] = vec[i];
            negIdx += 2;
        } else {
            ans[posIdx] = vec[i];
            posIdx += 2;
        }
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
    vector<int> ans = rearrangeElem(vec);
    display(ans);
    return 0;
}