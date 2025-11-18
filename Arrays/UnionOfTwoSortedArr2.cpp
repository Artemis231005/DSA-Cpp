#include <iostream>
#include <vector>
using namespace std;

vector<int> unionOf2SortedArr(vector<int> vec1, vector<int> vec2) {      // TC:O(n1 + n2)  SC: O(n1 +n2) - just to return ans ans not to actually solve
    int n1 = vec1.size();
    int n2 = vec2.size();
    int i=0, j=0;
    vector<int> ans; 

    while (i < n1 && j < n2) {
        if (vec1[i] <= vec2[j]) {
            if (ans.size() == 0 || ans.back() != vec1[i]) {              // .back() gives value of last inserted elem in vector
                ans.push_back(vec1[i]);
            }
            i++;
        } else {
            if (ans.size() == 0 || ans.back() != vec2[j]) {          
                ans.push_back(vec2[j]);
            }
            j++;
        }
    }
    while (j < n2) {
        if (ans.size() == 0 || ans.back() != vec2[j]) {          
            ans.push_back(vec2[j]);
        }
        j++;
    }
    while (i < n1) {
        if (ans.size() == 0 || ans.back() != vec1[i]) {          
            ans.push_back(vec1[i]);
        }
        i++;
    }
    return ans;
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n1, n2, elem;
    vector<int> vec1, vec2;
    cout << "Enter number of elements for 1st array: ";
    cin >> n1;
    cout << "Enter elements of 1st array: ";
    for (int i = 0; i < n1; i++) {
        cin >> elem;
        vec1.push_back(elem);
    }

    cout << "Enter number of elements for 2nd array: ";
    cin >> n2;
    cout << "Enter elements of 2nd array: ";
    for (int i = 0; i < n2; i++) {
        cin >> elem;
        vec2.push_back(elem);
    }

    cout << "The union of the two sorted arrays is: ";
    vector<int> ans = unionOf2SortedArr(vec1, vec2);
    display(ans);
    return 0;
}