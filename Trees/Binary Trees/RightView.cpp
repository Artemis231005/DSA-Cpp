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

    vector<int> rightView(Node* root) {     // TC: O(N)  SC: O(H)
        vector<int> ans;
        rightViewHelper(root, 0, ans);
        return ans;
    }

    void rightViewHelper(Node* node, int level, vector<int> &ans) {
        if (node == NULL) {
            return;
        }
        if (level == ans.size()) {      // Encountering for first time on that level
            ans.push_back(node->data);
        }

        rightViewHelper(node->right, level+1, ans);
        rightViewHelper(node->left, level+1, ans);
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

    vector<int> ans = tree.rightView(tree.root);
    for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
