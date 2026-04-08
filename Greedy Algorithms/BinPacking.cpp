#include<iostream>
#include<vector>
using namespace std;


// TC: O(n^2)   SC: O(N)
int firstFit(int n, int capacity, vector<int>& items) {
    vector<int> binRem(n, capacity); // remaining capacity
    int bins = 0;

    for(int i = 0; i < n; i++) {
        int j;
        for(j = 0; j < bins; j++) {
            if(binRem[j] >= items[i]) {
                binRem[j] -= items[i];
                break;
            }
        }

        if(j == bins) {
            binRem[bins] = capacity - items[i];
            bins++;
        }
    }
    return bins;
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> items(n);
    cout << "Enter item weights:\n";
    for(int i = 0; i < n; i++)
        cin >> items[i];

    cout << "Enter bin capacity: ";
    cin >> capacity;

    cout << "Minimum bins required: " << firstFit(n, capacity, items);
    return 0;
}