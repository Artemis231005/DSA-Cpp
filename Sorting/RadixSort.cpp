#include <iostream>
using namespace std;

// Counting sort used inside Radix Sort
void countingSortByDigit(int arr[], int n, int exp, int minVal) {
    int output[100];
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        int num = arr[i] - minVal; 
        int digit = (num / exp) % 10;
        count[digit]++;
    }

    // Prefix sum (cumulative count)
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int num = arr[i] - minVal;
        int digit = (num / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    if (n == 0) {
        return;
    }

    int minVal = arr[0];
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Sort digits from Least significant digit to most '' '' ie units then tens then hundreds and so on
    int range = maxVal - minVal;
    for (int exp = 1; range / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp, minVal);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements (can include negative numbers): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
