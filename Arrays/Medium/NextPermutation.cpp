#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC: O(N*N!)   SC: O(N)   Total SC:O(N*N!)
void generatePermutations(int index, vector<int>& vec, vector<vector<int>> &ans) {
    if (index == vec.size()) {
        ans.push_back(vec);
        return;
    }

    for (int i = index; i < vec.size(); i++) {
        swap(vec[index], vec[i]);
        generatePermutations(index+1, vec, ans);
        swap(vec[index], vec[i]);             
    }
}

vector<vector<int>> permute(vector<int> vec) {
    vector<vector<int>> ans;
    generatePermutations(0, vec, ans);
    return ans;
}

void display(vector<int> &vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

// doesnt handle lexigraphical order

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    vector<int> vec(n);                     
    cout << "Enter the values: ";
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    vector<vector<int>> ans = permute(vec);
    for(int i=0; i<ans.size(); i++) {
        if (ans[i] == vec) {
            cout << "Next permutation is: ";
            if (i+1 < ans.size()) {
                for (int j: ans[i+1]) {
                    cout << j << " ";
                }   
            } else {
                for (int j: ans[0]) {
                    cout << j << " ";
                } 
            }
        }
    }
    return 0;
}






















