#include<iostream>
#include<vector>
using namespace std;

int longestConsecutiveSequence(vector<int> vec) {   // TC: O(N^2)   SC: O(!)
    int longest = 1;   // == 1 as shortest seq is 1 (1 elem itself)

    for (int i = 0; i < vec.size(); i++) {
        int elem = vec[i];
        int count = 1;
        bool found = true;

        while (found) {
            found = false;

            for (int j = 0; j < vec.size(); j++) {
                if (vec[j] == elem + 1) {
                    elem++;
                    count++;
                    found = true;
                    break;
                }
            }
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
