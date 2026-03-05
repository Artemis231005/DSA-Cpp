#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC: O(n)   SC: O(1)
bool serve(vector<int> &bills) {
    int fives = 0, tens = 0;

    for (int i=0; i<bills.size(); i++) {
        if (bills[i] == 5) {
            fives++;
        } else if (bills[i] == 10) {
            if(fives) {
                fives--;
                tens++;
            } else {
                return false;
            }
        } else {
            if (tens && fives) {
                tens--;
                fives--;
            } else if (fives >= 3) {
                fives -=3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m, val;
    cout << "Enter number of customers: ";
    cin >> n;
    vector<int> bills;

    cout << "Enter bills: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        bills.push_back(val);
    }

    if (serve(bills)) {
        cout << "All customers can be served lemonades" << endl;
    } else {
        cout << "All customers cannot be served lemonades" << endl;
    }
    return 0;
}