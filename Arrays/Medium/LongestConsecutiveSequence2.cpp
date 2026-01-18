#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int longestConsecutiveSequence(vector<int> vec) {   // TC: O(NlogN) (O(NlogN) for sorting + O(N))   SC: O(1)  
    sort(vec.begin(), vec.end());

    int longest = 1; 
    int count = 0;
    int prevSmallerElem = INT_MIN;  

    for (int i=0 ;i<vec.size(); i++) {
        if (vec[i]-1 == prevSmallerElem) {
            count++;
            prevSmallerElem = vec[i];
        } else if (vec[i] == prevSmallerElem) {

        } else {
            count = 1;
            prevSmallerElem = vec[i];
        }
        longest = max(longest, count);
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
