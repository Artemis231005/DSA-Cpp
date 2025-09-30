#include <iostream>
#include <climits>
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

    Node* inorderSuccessor(Node* root, int val) {    // TC: O(H)   SC: O(1)
        Node* succ = NULL;
        while(root != NULL) {
            if (val >= root->data) {
                root = root->right;
            } else {
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }

    Node* inorderPredecessor(Node* root, int val) {   
        Node* pred = NULL;
        while(root != NULL) {
            if (val > root->data) {
                pred = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return pred;
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
    cout << "Enter value of node for whom you want to find inorder successor: ";
    cin >> key;

    Node* succ = tree.inorderSuccessor(tree.root, key);
    if (succ != NULL) {
        cout << "Value of the successor node is: " << succ->data << endl; 
    } else {
        cout << "Successor cannot be found for the node: " << key << endl;
    }

    cout << "Enter value of node for whom you want to find inorder predecessor: ";
    cin >> key;

    Node* pred = tree.inorderPredecessor(tree.root, key);
    if (pred != NULL) {
        cout << "Value of the predecesoor node is: " << pred->data << endl; 
    } else {
        cout << "Predecessor cannot be found for the node: " << key << endl;
    }
    return 0;
}
