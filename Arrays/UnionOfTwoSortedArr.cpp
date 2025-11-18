#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> unionOf2SortedArr(vector<int> vec1, vector<int> vec2) {           // TC: O((n1 + n2) * log(n1 + n2))
    vector<int> ans;
    set<int> st;

    for (int i=0; i<vec1.size(); i++) {                                       // TC: O(n1 log(n1))
        st.insert(vec1[i]);
    }
    for (int i=0; i<vec2.size(); i++) {                                       // TC: O(n2 log(n1 + n2))
        st.insert(vec2[i]);
    }
    for (auto it: st) {                                                       // TC: O(n1 + n2)
        ans.push_back(it);
    }
    return ans;
}
// set.insert() takes O(log N) where N is current size of the set

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