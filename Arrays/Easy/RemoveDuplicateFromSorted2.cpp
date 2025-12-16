#include<iostream>
using namespace std;

// 2 pointer approach
// TC: O(n)     SC: O(1)
int removeDuplicates(int arr[], int n) {
    int i = 0;
    for (int j=1; j<n; j++) {
        if (arr[i] != arr[j]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
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

    int uniqElem = removeDuplicates(arr, n);
    cout << "No of unique elements: " << uniqElem << endl;
    print(arr, uniqElem);

    // print(arr, n);
    // You are printing the entire original array (print(arr, n)) after removing duplicates, even though the function 
    // makes arr have new length. So, extra garbage/duplicate values from the old array may still show up in the output.
    return 0;
}