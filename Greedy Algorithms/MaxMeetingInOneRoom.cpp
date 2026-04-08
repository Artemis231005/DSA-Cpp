#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

// TC: O(N*logN) + O(N)   SC: O(N) (for tuple)
vector<int> maxMeetings(vector<int>& start, vector<int>& end, int &counter) {
    vector<tuple<int, int, int>> meetings;                  // (end time, start time, original idx)

    for (int i = 0; i < start.size(); i++) {
        meetings.push_back({end[i], start[i], i + 1});      // i+1 for 1-based indexing
    }

    sort(meetings.begin(), meetings.end());                 // Sort by end time
    vector<int> result; 
    int lastEnd = -1;

    for (auto &m : meetings) {
        int e = get<0>(m);
        int s = get<1>(m);
        int idx = get<2>(m);

        if (s > lastEnd) {
            counter++;
            result.push_back(idx); 
            lastEnd = e; 
        }
    }
    return result;
}

int main() {
    int n, val;
    cout << "Enter number of meetings: ";
    cin >> n;

    vector<int> start, end;

    cout << "Enter start time of meetings: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        start.push_back(val);
    }

    cout << "Enter end times of meetings: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        end.push_back(val);
    }

    int counter = 0;
    vector<int> ans = maxMeetings(start, end, counter);

    cout << "The maximum number of meetings that can be held from " << n << " meetings in one room are: " << counter << endl;
    cout << "The order of the meetings are: ";
    for (int i: ans) {
        cout << i << " ";

    }
    return 0;
}