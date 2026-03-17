#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Jobs {
public:
    int id;
    int profit;
    int deadline;
};

bool comp (Jobs val1, Jobs val2) {
    return val1.profit > val2.profit;
}

// TC: O(nlogn + n*maxDeadline)   SC: O(maxDeadline)
pair<int, int> maxProfit(vector<Jobs> jobs, int n) {
    sort(jobs.begin(), jobs.end(), comp);
    int tprofit = 0, counter = 0, maxDeadline = -1;

    for (int i=0; i<n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    vector<int> hash(maxDeadline+1, -1);

    for (int i=0; i<n; i++) {
        for (int j = jobs[i].deadline; j>0; j--) {  // j doesnt go till j=0 as deadlines begin from day 1
            if (hash[j] == -1) {
                counter++;
                hash[j] = jobs[i].id;
                tprofit += jobs[i].profit;
                break; 
            }
        }
    }
    return {counter, tprofit};
}

int main() {
    int n, m, Id, pr, de;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Jobs> jobs;

    for (int i=0; i<n; i++) {
        cin >> Id >> pr >> de;
        jobs.push_back({Id, pr,de});
    }

    auto ans = maxProfit(jobs, n);
    cout << "No of days and maxProfit: " << ans.first << " " << ans.second;
    return 0;
}