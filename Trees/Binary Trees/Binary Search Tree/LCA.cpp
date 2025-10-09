#include <iostream>
#include <vector>
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

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    void insertNode(int val) {    
        Node* newNode = new Node(val);
        if (root == NULL) {
            root = newNode;
            return;
        }

        Node* temp = root;
        while (temp != NULL) {
            if (temp->data < val) {
                if (temp->right != NULL) {
                    temp = temp->right;
                } else {
                    temp->right = newNode;
                    return;
                }
            } else {
                if (temp->left != NULL) {
                    temp = temp->left;
                } else {
                    temp->left = newNode;
                    return;
                }
            }
        }
    }

    Node* lca (Node* root, Node* p, Node* q) {      // TC: O(H)   SC: O(H)
        if (root == NULL) {
            return NULL;
        }
        int currVal = root->data;
        if (currVal < p->data && currVal  < q->data) {
            return lca(root->right, p, q);
        }
        if (currVal > p->data && currVal > q->data) {
            return lca(root->left, p, q);
        }
        return root;
    }
};

int main() {
    BST tree;
    tree.insertNode(6);
    tree.insertNode(3);
    tree.insertNode(8);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(7);

    int i, j;
    cout << "Enter 2 values for nodes whose lowest common ancestor you want: ";
    cin >> i >> j;

    Node* p = new Node(i);
    Node* q = new Node(j);
    Node* ans = tree.lca(tree.root, p, q);

    if (ans) {
        cout << "Lowest Common Ancestor is: " << ans->data << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}
