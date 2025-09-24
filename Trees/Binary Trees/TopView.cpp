#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BT {
public:
    Node* root;

    BT() {
        root = NULL;
    }

    void insertNode(vector<string>& vec) {
        if (vec.empty() || vec[0] == "null") {
            return;
        }

        root = new Node(stoi(vec[0]));
        queue<Node*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < vec.size()) {
            Node* curr = q.front();
            q.pop();

            if (i < vec.size() && vec[i] != "null") {
                curr->left = new Node(stoi(vec[i]));
                q.push(curr->left);
            }
            i++;

            if (i < vec.size() && vec[i] != "null") {
                curr->right = new Node(stoi(vec[i]));
                q.push(curr->right);
            }
            i++;
        }
    }

    vector<int> topView(Node* root) {   // TC: O(N)   SC: O(N)
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* temp = it.first;
            int lineIdx = it.second;
            if(mp.find(lineIdx) == mp.end()) {
                mp[lineIdx] = temp->data;
            }

            if (temp->left != NULL) {
                q.push({temp->left, lineIdx - 1});
            }
            if (temp->right != NULL) {
                q.push({temp->right, lineIdx + 1});
            }
        }

        for (auto i: mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main() {
    BT tree;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<string> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tree.insertNode(arr);

    vector<int> ans = tree.topView(tree.root);
    for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
