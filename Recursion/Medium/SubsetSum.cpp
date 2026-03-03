#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findSubsetSums(int idx, int sum, vector<int> &vec, int n, vector<int> &sumSubsets) {
    if(idx == n) {
        sumSubsets.push_back(sum);
        return;
    }

    // take
    findSubsetSums(idx+1, sum + vec[idx], vec, n, sumSubsets);
    // dont take
    findSubsetSums(idx+1, sum, vec, n, sumSubsets);
}

// TC: O(2^n log(2^n))  (sorting 2^n)
vector<int> subsetSums(vector<int> &vec, int n) {
    vector<int> sumSubsets;
    findSubsetSums(0, 0, vec, n, sumSubsets);
    sort(sumSubsets.begin(), sumSubsets.end());
    return sumSubsets;
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

    cout << "Subset sums of the array are: " << endl;
    vector<int> ans = subsetSums(vec, n);

    for (auto i: ans) {
        cout << i << " ";
    }
    return 0;
}