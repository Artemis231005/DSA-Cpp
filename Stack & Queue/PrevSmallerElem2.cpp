#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TC: O(2N) = O(N) (similar to nge method)     SC: O(N)

void display(vector<int> &vec) {
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void prevSmallerElem(vector<int> vec) {
    int n = vec.size();
    stack<int> st;
    vector<int> pse(n, -1);

    for (int i=0; i<n; i++) {
        while (!st.empty() && st.top() >= vec[i]) {
            st.pop();
        }
        if (!st.empty()) {
            pse[i] = st.top();
        }
        st.push(vec[i]);
    }

    cout << "Array of Previous Smaller Elements: ";
    display(pse);
}

int main() {
    vector<int> vec;
    int n;
    cout <<"Enter no of elem: ";
    cin >> n;

    cout << "Enter value of elem: ";
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    display(vec);

    prevSmallerElem(vec);
    return 0;
}