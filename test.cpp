#include <iostream>
#include <vector>
using namespace std;

void findPermutations(int idx, vector<int>& vec, vector<vector<int>>& ans) {
    if (idx == vec.size()) {
        ans.push_back(vec);
        return;
    }

    for(int i=idx; i<vec.size(); i++) {
        swap(vec[idx], vec[i]);
        findPermutations(idx+1, vec, ans);
        swap(vec[idx], vec[i]);
    }
}

vector<vector<int>> permute(vector<int> vec) {
    vector<vector<int>> ans;
    findPermutations(0, vec, ans);
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
