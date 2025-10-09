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

    Node* BTFromPreInorder (vector<int> &preorder, vector<int> &inorder) {
        map<int,int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        Node* root = BTFromPreInorderHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }

    Node* BTFromPreInorderHelper (vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp) {
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        // If element not found in inorder => invalid traversal
        if (mp.find(preorder[preStart]) == mp.end()) {
            return NULL;
        }

        Node* root = new Node(preorder[preStart]);
        int inRoot = mp[root->data];
        int numsLeft = inRoot - inStart;

        root->left = BTFromPreInorderHelper(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
        root->right = BTFromPreInorderHelper(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);

        return root;
    }
};

int main() {
    BT tree;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n), inorder(n);
    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    tree.root = tree.BTFromPreInorder(preorder, inorder);
    if (tree.root) {
        cout << "Binary Tree constructed!" << endl;
    } else {
        cout << "Invalid traversals given!" << endl;
    }
    return 0;
}

