#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) {
    if (n <= 0) {
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

    int range = maxVal - minVal + 1;
    int bucketCount = n;                                        // we make one bucket per element 
    int bucketSize = (range + bucketCount - 1) / bucketCount;   // ceiling division

    // Each bucket can hold n elements at max
    int Buckets[100][100];
    int bucketIndex[100];

    for (int i = 0; i < bucketCount; i++) {
        bucketIndex[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int pos = (arr[i] - minVal) / bucketSize;
        
        if (pos >= bucketCount) {
            pos = bucketCount - 1;                             // due to integer division rounding or if arr[i] equals maxVal
        }
        Buckets[pos][bucketIndex[pos]] = arr[i];
        bucketIndex[pos]++;
    }

    int k = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketIndex[i] > 0) {
            insertionSort(Buckets[i], bucketIndex[i]);

            for (int j = 0; j < bucketIndex[i]; j++) {
                arr[k++] = Buckets[i][j];
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// int bucketSize = (range + bucketCount - 1) / bucketCount;
// This decides how many numbers fall into one bucket.
// Example: If numbers go from 10 to 29 (range = 20), and there are 10 buckets → each bucket covers 2 numbers.

// bucketIndex[i] = how many elements are currently in bucket i