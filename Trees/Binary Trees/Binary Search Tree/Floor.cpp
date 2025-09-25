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

    int findFloor(Node* root, int key) {
        int floor = -1;
        while (root != NULL) {
            if (root->data == key) {
                floor = root->data;
                return floor;
            }

            if (key > root->data) {
                floor = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
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
    cout << "Enter value for which you want to find floor: ";
    cin >> key;
    int ans = tree.findFloor(tree.root, key);
    if (ans == -1) {
        cout << "Floor for " << key << " not found in the tree" << endl;
    } else {
        cout << "Floor for " << key << " will be: " << ans << endl;
    }
    return 0;
}
