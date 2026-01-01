#include<iostream>
#include<vector>
using namespace std;

int majorityElem(vector<int> vec) {     // TC: O(N)   SC: O(1)
    int count = 0;
    int elem;
    int n = vec.size();

    for (int i=0; i<n; i++) {
        if (count == 0) {
            elem = vec[i];
            count = 1;
        } else if (vec[i] == elem) {
            count++;
        } else {
            count--;
        }
    }

    int counter = 0;
    for (int i=0; i<n; i++) {       // This loop is not necessary if ques guarantees that all testcases will always have mojority elem
        if (vec[i] == elem) {
            counter++;
        }
    }
    if (counter > (n/2)) {
        return elem;
    }
    return -1;
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

    cout << "The element that appears more than " << n/2 << " times is: " << majorityElem(vec);
    return 0;
}