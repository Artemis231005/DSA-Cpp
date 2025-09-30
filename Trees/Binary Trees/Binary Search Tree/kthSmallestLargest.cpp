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

    void getKthSmallestLargest(Node* root, int k) {
        int smallest = INT_MIN, largest = INT_MAX;
        int count = 0;

        findKthSmallest(root, k, count, smallest);

        count = 0; 
        findKthLargest(root, k, count, largest);

        cout << "Kth (" << k << ") smallest node is: " << smallest << " and largest node is: " << largest << endl;
    }

    void findKthSmallest(Node* node, int k, int& count, int& result) {
        if (node == NULL || count >= k) {
            return;
        }

        findKthSmallest(node->left, k, count, result);
        count++;
        if (count == k) {
            result = node->data;
            return;
        }
        findKthSmallest(node->right, k, count, result);
    }

    void findKthLargest(Node* node, int k, int& count, int& result) {
        if (node == NULL || count >= k) {
            return;
        }

        findKthLargest(node->right, k, count, result);
        count++;
        if (count == k) {
            result = node->data;
            return;
        }
        findKthLargest(node->left, k, count, result);
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

    tree.getKthSmallestLargest(tree.root, 3);
    return 0;
}
