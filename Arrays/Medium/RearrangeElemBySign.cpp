#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> rearrangeElem (vector<int> vec) {       // TC: O(N)   SC: O(N) (O(N/2) + O(N/2))
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

    for (int i=0; i<n/2; i++) {
        ans[2*i] = pos[i];
        ans[2*i+1] = neg[i];
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