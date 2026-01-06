#include<iostream>
#include<vector>
using namespace std;

// TC: O(N*N!)   SC:O(3N)=O(N) (ds and freq) & O(N) for recursion
void generatePermutations(const vector<int>& vec, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& marked) {
    if (ds.size() == vec.size()) {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < vec.size(); i++) {
        if (!marked[i]) {
            marked[i] = true;
            ds.push_back(vec[i]);
            generatePermutations(vec, ds, ans, marked);

            ds.pop_back();
            marked[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> vec) {
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> marked(vec.size(), false);

    generatePermutations(vec, ds, ans, marked);
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
