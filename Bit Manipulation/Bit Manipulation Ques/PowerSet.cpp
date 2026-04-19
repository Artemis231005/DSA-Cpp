#include<iostream>
#include<vector>
using namespace std;

bool checkithBitSet (int no, int i){
    int res = no & (1 << i);
    if (res != 0){
        return true;
    }
    return false;
}

// TC: O(n*(2^n)) (inner loop * outer loop)   SC: O(n*(2^n)) (approx, avg length taken n) 
vector<vector<int>> generatePowerSet(vector<int> vec, int n) {
    int noOfSubsets = 1 << n;   // equivalent to 2^n
    vector<vector<int>> ans;

    for (int num=0; num<noOfSubsets; num++) {   // goes from 0 to 2^n-1 to get all subsets
        vector<int> subset;
        for (int i=0; i<n; i++) {               // goes thru indices of vec to decide which to take and which to not take
            if (checkithBitSet(num, i)) {
                subset.push_back(vec[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}

int main(){
    int n, val;
    vector<int> vec;
    cout << "Enter a size: ";
    cin >> n;
    
    cout << "Enter elements: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    vector<vector<int>> ans = generatePowerSet(vec, n);
    cout << "Power sets are: ";

    for (auto i: ans) {
        cout << "[ ";
        for (auto j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}