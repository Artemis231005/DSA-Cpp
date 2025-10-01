#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int d) {
        data = d;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            return node->height;
        }
    }

    int getBF(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            return height(node->left) - height(node->right);
        }
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        else {
            return node; 
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int bf = getBF(node);

        if (bf > 1 && val < node->left->data) {
            return rightRotate(node);
        }

        if (bf < -1 && val > node->right->data) {
            return leftRotate(node);
        }

        if (bf > 1 && val > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (bf < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void printBalanceFactors(Node* node) {
        if (node == NULL) {
            return;
        }
        printBalanceFactors(node->left);
        cout << "Node " << node->data << " -> BF: " << getBF(node) << endl;
        printBalanceFactors(node->right);
    }

    int treeHeight() {
        return height(root);
    }

    bool isAVL(Node* node) {
        if (node == NULL) return true;

        int bf = getBF(node);
        if (bf < -1 || bf > 1) return false;

        return isAVL(node->left) && isAVL(node->right);
    }
};

int main() {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.root);
    cout << "\n\nBalance Factors:\n";
    tree.printBalanceFactors(tree.root);

    cout << "\nHeight of tree: " << tree.treeHeight() << endl;

    if (tree.isAVL(tree.root)) {
        cout << "The tree is a valid AVL tree." << endl;
    } else {
        cout << "The tree is NOT a valid AVL tree." << endl;
    }

    return 0;
}
