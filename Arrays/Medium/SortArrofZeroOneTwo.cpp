#include<iostream>
#include<vector>
using namespace std;

// TC: O(NlogN)   SC: O(N)
void merge(vector<int> &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[100], R[100];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void display(vector<int> vec) {
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
    mergeSort(vec, 0, n - 1);
    display(vec);
    return 0;
}