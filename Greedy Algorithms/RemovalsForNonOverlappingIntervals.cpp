#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

// TC: O(n log n), SC: O(1)  (since not using tuple)
int noOfRemovals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    int counter = 1;  
    int lastEnd = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] >= lastEnd) {
            counter++;
            lastEnd = intervals[i][1];
        }
    }

    return n - counter;   
}

int main() {
    int n, val;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals;

    cout << "Enter start and end of intervals:\n";
    for (int i = 0; i < n; i++) {
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];   // start, end
        intervals.push_back(temp);
    }

    int counter = 0;
    int ans = noOfRemovals(intervals);

    cout << "Minimum removals: " << ans << endl;
    return 0;
}