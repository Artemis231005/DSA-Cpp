#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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

    bool isLeafNode (Node* node) {
        if (node == NULL) {
            return false;
        }
        if (node->left == NULL && node->right == NULL) {
            return true;
        }

        return false;
    }

    // TC: O(N)  (Each node is visited once either during left boundary, right or leaf node traversal) 
    // SC: O(H)  (Recursion stack space and for stack)  
    vector<int> boundaryTraversal (Node* root) {   
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        if (!isLeafNode(root)) {
            ans.push_back(root->data);
        }
        
        leftBoundary(root, ans);
        addLeafNodes(root, ans);
        rightBoundary(root, ans);
        return ans;
    }

    void leftBoundary(Node* node, vector<int> &ans) {
        Node* temp = node->left;

        while (temp) {
            if (!isLeafNode(temp)) {
                ans.push_back(temp->data);
            }
            if (temp->left) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
    }

    void rightBoundary(Node* node, vector<int> &ans) {
        Node* temp = node->right;
        stack<int> st;

        while (temp) {
            if (!isLeafNode(temp)) {
                st.push(temp->data);
            }
            if (temp->right) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }

    void addLeafNodes (Node* node, vector<int> &ans) {      // Inorder Traversal
        if (isLeafNode(node)) {
            ans.push_back(node->data);
            return;
        }

        if (node->left) {
            addLeafNodes(node->left, ans);
        }
        if (node->right) {
            addLeafNodes(node->right, ans);
        }
    }
    
    // For clockwise traversal, take rightBoundary first, then leaf nodes from right to left(node->right and then node->left)
    // Then take leftBoundary with stack and hence ensure left values are pushed in reverse order
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

    vector<int> ans = tree.boundaryTraversal(tree.root);
    cout << "Boundary Traversal: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
