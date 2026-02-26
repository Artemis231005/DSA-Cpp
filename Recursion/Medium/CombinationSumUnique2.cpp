#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// TC: (2^n * k) (2^n choices and to insert into ds takes k)     SC:O(k*x)
void findCombination(int idx, int target, vector<int> & arr, vector<vector<int>> &ans, vector<int> &store) {
    if (target == 0) {
            ans.push_back(store);
            return;
        }

    for(int i=idx; i<arr.size(); i++) {
        if (i > idx && arr[i] == arr[i-1]) {
            continue;
        }
        if (arr[i] > target) {
            break;
        }
        store.push_back(arr[i]);
        findCombination(i+1, target-arr[i], arr, ans, store);
        store.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end()); 

    vector<vector<int>> ans;
    vector<int> store;
    findCombination(0, target, candidates, ans, store);
    return ans;
}

int main() {
    int n, val, target;
    vector<int> vec;

    cout << "Enter size of vector: ";
    cin >> n;

    cout <<"Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    cout << "Enter target: ";
    cin >> target;

    cout << "Combinations of the array that sum up to " << target << " are: " << endl;
    vector<vector<int>> ans = combinationSum(vec, target);

    for (auto it: ans) {
        cout << "[";
        for (auto i: it) {
            cout << i << " ";
        }
        cout << "]";
        cout << " ";
    }
    return 0;
}