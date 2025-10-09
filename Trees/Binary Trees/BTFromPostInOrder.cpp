#include <iostream>
#include <queue>
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

    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    Node* BTFromPostInorder (vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }
        map <int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return BTFromPostInorderHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }

    Node* BTFromPostInorderHelper (vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &mp) {
        if (inStart > inEnd || postStart > postEnd) {
            return NULL;
        }

        Node* root = new Node(postorder[postEnd]);
        if (mp.find(root->data) == mp.end()) { 
            return NULL;
        }

        int inRoot = mp[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root->left = BTFromPostInorderHelper(inorder, inStart, inRoot-1, postorder, postStart, postStart+numsLeft-1, mp);
        root->right = BTFromPostInorderHelper(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, mp);
        return root;
    }
};

int main() {
    BT tree;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> postorder(n), inorder(n);
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    tree.root = tree.BTFromPostInorder(inorder, postorder);
    if (tree.root) {
        cout << "Binary Tree constructed!" << endl;
    } else {
        cout << "Invalid traversals given!" << endl;
    }
    return 0;
}

