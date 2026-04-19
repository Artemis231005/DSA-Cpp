#include<iostream>
#include<vector>
using namespace std;

// TC: O(1)   SC: O(N)
int singleNumber(vector<int> vec, int n) {
    int xorRes = 0;
    for (int i=0; i<n; i++) {
        xorRes = xorRes ^ vec[i];
    }
    return xorRes;
}

int main(){
    int n, val;
    vector<int> vec;
    cout << "Enter a size: ";
    cin >> n;
    
    cout << "Enter elements: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    cout << "The element that appears once among numbers appearing twice is: " << singleNumber(vec, n);
    return 0;
}