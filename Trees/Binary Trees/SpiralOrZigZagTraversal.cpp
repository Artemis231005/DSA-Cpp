#include <iostream>
#include <queue>
#include <vector>
#include <string>
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

            if (vec[i] != "null") {
                curr->left = new Node(stoi(vec[i]));
                q.push(curr->left);
            }
            i++;

            if (vec[i] != "null") {
                curr->right = new Node(stoi(vec[i]));
                q.push(curr->right);
            }
            i++;
        }
    }

    vector<vector<int>> SpiralTraversal (Node* node) {      // TC: O(N)   SC: O(N)
        vector<vector<int>> ans;
        if (node == NULL) {
            return ans;
        }

        queue <Node*> q;
        q.push(node);
        bool ltor = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i=0; i<size; i++) {
                Node* temp = q.front();
                q.pop();

                int idx;
                if (ltor) {                     // find position to fill node's value (either from start or end)
                    idx = i;            
                } else {
                    idx = size-i-1;
                }

                level[idx] = temp->data;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            ltor = !ltor;
            ans.push_back(level);
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

    cout << "Spiral or Zig-Zag Traversal: " << endl;
    vector<vector<int>> ans = tree.SpiralTraversal(tree.root);
    for (auto &level : ans) {              
        for (int val : level) {            
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
