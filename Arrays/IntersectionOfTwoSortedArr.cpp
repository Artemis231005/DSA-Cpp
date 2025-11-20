#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectionOf2SortedArr(vector<int> vec1, vector<int> vec2) {      // TC: O(n1 * n2)   SC: O(n2)
    vector<int> ans;
    int vis[100] = {0};

    for (int i=0; i<vec1.size(); i++) {
        for (int j=0; j<vec2.size(); j++) {
            if (vec1[i] == vec2[j] && vis[j] == 0) {
                ans.push_back(vec2[j]);
                vis[j] = 1;
                break;
            }
            if (vec2[j] > vec1[i]) {
                break;
            }
        }
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

    cout << "The intersection of the two sorted arrays is: ";
    vector<int> ans = intersectionOf2SortedArr(vec1, vec2);
    display(ans);
    return 0;
}