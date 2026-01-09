#include<iostream>
#include<vector>
using namespace std;

// TC: O(N*N!)   SC:O(N) (for recursion)
void generatePermutations(int index, vector<int>& vec, vector<vector<int>> &ans) {
    if (index == vec.size()) {
        ans.push_back(vec);
        return;
    }

    for (int i = index; i < vec.size(); i++) {
        swap(vec[index], vec[i]);
        generatePermutations(index+1, vec, ans);
        swap(vec[index], vec[i]);               // swapped to backtracking
    }
}

vector<vector<int>> permute(vector<int> vec) {
    vector<vector<int>> ans;
    generatePermutations(0, vec, ans);
    return ans;
}

int main() {
    int n, val;
    vector<int> vec;

    cout << "Enter size of vector: ";
    cin >> n;

    cout <<"Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    cout << "The permutations are: " << endl;
    vector<vector<int>> ans = permute(vec);
    for (vector<int> i : ans) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
