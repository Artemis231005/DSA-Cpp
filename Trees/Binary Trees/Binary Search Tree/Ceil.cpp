#include <iostream>
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

    // Ceil is lowest possible value greater tahn key such that ceilVal >= key AND ceilVal -> minimun
    int findCeil (Node* root, int key) {
        int ceil = -1;

        while(root) {
            if (root->data == key) {
                ceil = root->data;
                return root->data;
            }

            if (key > root->data) {
                root = root->right;
            } else {
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
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

    int key;
    cout << "Enter value for which you want to find ceil: ";
    cin >> key;
    if (tree.findCeil(tree.root, key) == -1) {
        cout << "Ceil for " << key << " not foundin the tree" << endl;
    } else {
        cout << "Ceil for " << key << " will be: " << tree.findCeil(tree.root, key) << endl;
    }
    return 0;
}
