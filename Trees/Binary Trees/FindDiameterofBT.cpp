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

    // diameter- longest path between 2 nodes. (path does not need to pass through the root)
    int calculateDiameter(Node* root, int& diameter) {      // TC: O(N)   SC: O(H)
        if (root == NULL) {
            return 0;
        }

        int lh = calculateDiameter(root->left, diameter);                       // returns height of left subtree
        int rh = calculateDiameter(root->right, diameter);
        diameter = max(diameter, lh + rh);          // compares current best diameter with length of path thru current node

        return 1 + max(lh, rh);                     // returning height so that we can calculate height of subtrees
    }

    //Even though we are checking diameter at every node, we are not recomputing height repeatedly.
    // Each node contributes its height once on the way up. So, TC: O(N)

    int findDiameter() {
        int diameter = 0;   
        calculateDiameter(root, diameter);          // diameter is global prop of whole tree, it is not local to 1 node
        return diameter;
    }
};

int main() {
    BT tree;
    int n, val;
    cout << "Enter no of nodes that you want to enter: ";
    cin >> n;

    cout << "Enter the values in the node: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        tree.insertNode(val);
    }

    cout << "Diameter of tree: " << tree.findDiameter() << endl;
    return 0;
}
