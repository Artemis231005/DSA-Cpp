#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// TC: O(3N) = O(N)(insertion) + O(2N) (traversing set and while loop) under assumption that set is taking O(1)   SC: O(N)
// If set is taking logn, brute force and better approach is better
int longestConsecutiveSequence(vector<int> vec) {   
    int longest = 1; 
    int n = vec.size();
    unordered_set<int> st;

    for (int i=0; i<n; i++) {
        st.insert(vec[i]);
    }
    for (auto it: st) {
        if (st.find(it-1) == st.end()) {                    // implies it is first elem of seq
            int count = 1;
            int elem = it;

            while(st.find(elem+1) != st.end()) {            // instead of linear search like brute force, we traverse set
                elem++;
                count++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
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

    cout << "Longest consecutive sequence is: " << longestConsecutiveSequence(vec);
    return 0;
}
