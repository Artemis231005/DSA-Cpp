#include<iostream>
#include<vector>
using namespace std;

void sortArr(vector<int> &vec) {    // TC: O(N)   SC: O(1)
    int low = 0, mid = 0, high = vec.size()-1;
    while(mid <= high) {
        if (vec[mid] == 0) {
            swap (vec[low], vec[mid]);
            low++;
            mid++;
        } else if (vec[mid] == 1){
            mid++;
        } else {
            swap(vec[mid], vec[high]);
            high--;
        }
    }
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

    cout << "The sorted array is: ";
    sortArr(vec);
    display(vec);
    return 0;
}