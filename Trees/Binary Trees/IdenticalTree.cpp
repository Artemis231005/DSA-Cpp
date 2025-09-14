#include <iostream>
#include <queue>
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

    bool isIdenticalTree(Node* root1, Node* root2) {
        if (root1 == NULL || root2 == NULL) {
            return (root1 == root2);
        }

        return (root1->data == root2->data) && 
        isIdenticalTree(root1->left, root2->left) && isIdenticalTree(root1->right, root2->right);
    }
};

int main() {
    BT tree1, tree2;
    int n, val;
    cout << "Enter no of nodes that you want to enter for tree 1: ";
    cin >> n;

    cout << "Enter the values in the node: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        tree1.insertNode(val);
    }

    cout << "Enter no of nodes that you want to enter for tree 2: ";
    cin >> n;

    cout << "Enter the values in the node: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        tree2.insertNode(val);
    }
    
    if (tree1.isIdenticalTree(tree1.root, tree2.root)) {
        cout << "The 2 trees are identical" << endl;
    } else {
        cout << "The 2 trees are not identical" << endl;
    }
    return 0;
}
