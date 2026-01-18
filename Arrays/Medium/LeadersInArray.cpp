#include<iostream>
#include<vector>
using namespace std;

vector<int> printLeaders (vector<int> vec) {    // TC: O(N^2) (near about)   SC: O(1) (extra)  
    vector<int> ans;
    bool isLeader = true;

    for (int i=0; i<vec.size(); i++) {
        isLeader = true;
        for (int j=i+1; j<vec.size(); j++) {
            if (vec[j] > vec[i]) {
                isLeader = false;
                break;
            }
        }

        if (isLeader) {
            ans.push_back(vec[i]);
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

    cout << "Leaders in the array are: ";
    vector<int> ans = printLeaders(vec);

    for (int i:ans) {
        cout << i << " ";
    }

    return 0;
}
