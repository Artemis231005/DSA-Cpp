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

    void levelOrder(Node* root) {        // TC: O(N)   SC:O(N) - Queue stores N int
        if (root == NULL) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                Node* temp = q.front();
                q.pop();

                cout << temp->data << " ";

                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
            cout << endl;
        }
    }

    // Can also store result in vector<vector<int>> and push_back value in iteration(for loop) to vector<int> level (individual values 
    // in level) and push_back level in ans for each iteration of while loop (each level of tree)

    vector<vector<int>> levelOrderStored(Node* root) {   // TC: O(N), SC: O(N)
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;   

            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();

                level.push_back(temp->data);
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};

int main() {
    BT tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);
    tree.insertNode(8);
    tree.insertNode(9);
    tree.insertNode(10);
    
    cout << "Level order traversal directly: " << endl;
    tree.levelOrder(tree.root);

    cout << "Level order traversal after storing: " << endl;
    vector<vector<int>> ans = tree.levelOrderStored(tree.root);
    for (auto &level : ans) {               // copying is expensive for big obj such as vector<int>, so use reference
        for (int val : level) {             // doesn't really matter for small types such as int
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
