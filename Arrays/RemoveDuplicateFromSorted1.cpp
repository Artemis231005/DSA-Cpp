#include<iostream>
#include<set>
using namespace std;

// Using Set
// TC: O(nlogn) + O(n)   SC: O(N)

void removeDuplicates (int arr[], int n) {
    set<int> st;
    for (int i=0; i<n; i++) {
        st.insert(arr[i]);
    }
    cout << "Array without duplicates: ";
    for (int val: st) {
        cout << val << " ";
    }
    cout << endl;
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Original array: ";
    print(arr, n);

    removeDuplicates(arr,n);
    
    return 0;
}